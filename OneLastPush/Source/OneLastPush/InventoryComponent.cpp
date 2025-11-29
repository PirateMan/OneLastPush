// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "Net/UnrealNetwork.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
    InitializeGrid(GridWidth, GridHeight);
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UInventoryComponent, Items);
    DOREPLIFETIME(UInventoryComponent, Cells);
}

void UInventoryComponent::InitializeGrid(int32 InWidth, int32 InHeight)
{
    GridWidth = FMath::Max(1, InWidth);
    GridHeight = FMath::Max(1, InHeight);
    Cells.Init(-1, GridWidth * GridHeight);
}

void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
    // ensure grid matches configured values
    if (Cells.Num() != GridWidth * GridHeight)
    {
        InitializeGrid(GridWidth, GridHeight);
    }
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

int32 UInventoryComponent::GetCellIndex(int32 X, int32 Y) const
{
    return Y * GridWidth + X;
}

bool UInventoryComponent::IsInBounds(int32 X, int32 Y) const
{
    return X >= 0 && X < GridWidth && Y >= 0 && Y < GridHeight;
}

bool UInventoryComponent::CanPlaceAt(int32 ItemIndex, int32 StartX, int32 StartY, int32 ItemW, int32 ItemH) const
{
    // Check bounds
    if (!IsInBounds(StartX, StartY))
    {
        return false;
    }
    if (!IsInBounds(StartX + ItemW - 1, StartY + ItemH - 1))
    {
        return false;
    }

    // Ensure all cells are empty or occupied by the same item (useful for rotation inplace)
    for (int32 Y = 0; Y < ItemH; ++Y)
    {
        for (int32 X = 0; X < ItemW; ++X)
        {
            int32 CellIdx = GetCellIndex(StartX + X, StartY + Y);
            int32 Occupier = Cells.IsValidIndex(CellIdx) ? Cells[CellIdx] : -1;
            if (Occupier != -1 && Occupier != ItemIndex)
            {
                return false;
            }
        }
    }
    return true;
}

void UInventoryComponent::MarkCellsForItem(int32 ItemIndex, int32 StartX, int32 StartY, int32 ItemW, int32 ItemH, int32 Value)
{
    for (int32 Y = 0; Y < ItemH; ++Y)
    {
        for (int32 X = 0; X < ItemW; ++X)
        {
            int32 CellIdx = GetCellIndex(StartX + X, StartY + Y);
            if (Cells.IsValidIndex(CellIdx))
            {
                Cells[CellIdx] = Value;
            }
        }
    }
}

int32 UInventoryComponent::FindSpaceForDimensions(int32 W, int32 H) const
{
    for (int32 Y = 0; Y <= GridHeight - H; ++Y)
    {
        for (int32 X = 0; X <= GridWidth - W; ++X)
        {
            bool bOk = true;
            for (int32 yy = 0; yy < H && bOk; ++yy)
            {
                for (int32 xx = 0; xx < W; ++xx)
                {
                    int32 CellIdx = GetCellIndex(X + xx, Y + yy);
                    if (!Cells.IsValidIndex(CellIdx) || Cells[CellIdx] != -1)
                    {
                        bOk = false;
                        break;
                    }
                }
            }
            if (bOk)
            {
                return GetCellIndex(X, Y);
            }
        }
    }
    return -1;
}

int32 UInventoryComponent::TryMergeStack(const FInventoryItem& Item, int32 AddCount)
{
    // Attempt to merge with existing stacks of same ItemID
    int32 Remaining = AddCount;
    if (!Item.bStackable || Item.MaxStack <= 0)
    {
        return Remaining;
    }
    for (int32 i = 0; i < Items.Num() && Remaining > 0; ++i)
    {
        const FInventoryItem& Cur = Items[i];
        if (!Cur.bActive)
            continue;
        if (Cur.ItemID == Item.ItemID && Cur.bStackable)
        {
            int32 Free = Cur.MaxStack - Cur.Count;
            if (Free > 0)
            {
                int32 ToAdd = FMath::Min(Free, Remaining);
                // mutate the item (needs non-const)
                Items[i].Count += ToAdd;
                Remaining -= ToAdd;
            }
        }
    }
    return Remaining;
}

int32 UInventoryComponent::AddItem(const FInventoryItem& Item, bool bAllowRotate)
{
    if (!GetOwner()->HasAuthority())
    {
        ServerAddItem(Item, bAllowRotate);
        return -1; // clients do not get authoritative index
    }
    return AddItem_Internal(Item, bAllowRotate);
}

void UInventoryComponent::ServerAddItem_Implementation(const FInventoryItem& Item, bool bAllowRotate)
{
    AddItem_Internal(Item, bAllowRotate);
}

int32 UInventoryComponent::AddItem_Internal(const FInventoryItem& Item, bool bAllowRotate)
{
    // If stackable, try merge first
    if (Item.bStackable)
    {
        int32 Remaining = TryMergeStack(Item, Item.Count);
        if (Remaining <= 0)
        {
            // fully merged
            return -1; // merged, no new item index
        }
        // update a local copy with remaining count
        FInventoryItem Copy = Item;
        Copy.Count = Remaining;

        // fall through to place remaining as a new item
        // try placement for Copy
        // try non-rotated then rotated (if allowed)
        int32 W = FMath::Max(1, Copy.Width);
        int32 H = FMath::Max(1, Copy.Height);

        int32 Found = FindSpaceForDimensions(W, H);
        if (Found != -1)
        {
            int32 CellX = Found % GridWidth;
            int32 CellY = Found / GridWidth;
            int32 NewIndex = Items.Add(Copy);
            MarkCellsForItem(NewIndex, CellX, CellY, W, H, NewIndex);
            Items[NewIndex].bRotated = false;
            OnRep_Items();
            OnRep_Cells();
            return NewIndex;
        }

        if (bAllowRotate && (Copy.Width != Copy.Height))
        {
            Found = FindSpaceForDimensions(H, W);
            if (Found != -1)
            {
                int32 CellX = Found % GridWidth;
                int32 CellY = Found / GridWidth;
                Copy.bRotated = true;
                Swap(Copy.Width, Copy.Height); // rotated copy
                int32 NewIndex = Items.Add(Copy);
                MarkCellsForItem(NewIndex, CellX, CellY, Copy.Width, Copy.Height, NewIndex);
                Items[NewIndex].bRotated = true;
                OnRep_Items();
                OnRep_Cells();
                return NewIndex;
            }
        }

        // couldn't place remaining; return -1 to indicate partial merge only
        return -1;
    }
    else
    {
        // non stackable: treat Count as 1 and place
        FInventoryItem Copy = Item;
        Copy.Count = FMath::Max(1, Item.Count);
        int32 W = FMath::Max(1, Copy.Width);
        int32 H = FMath::Max(1, Copy.Height);

        int32 Found = FindSpaceForDimensions(W, H);
        if (Found != -1)
        {
            int32 CellX = Found % GridWidth;
            int32 CellY = Found / GridWidth;
            int32 NewIndex = Items.Add(Copy);
            MarkCellsForItem(NewIndex, CellX, CellY, W, H, NewIndex);
            Items[NewIndex].bRotated = false;
            OnRep_Items();
            OnRep_Cells();
            return NewIndex;
        }

        if (bAllowRotate && (Copy.Width != Copy.Height))
        {
            Found = FindSpaceForDimensions(H, W);
            if (Found != -1)
            {
                int32 CellX = Found % GridWidth;
                int32 CellY = Found / GridWidth;
                Copy.bRotated = true;
                Swap(Copy.Width, Copy.Height);
                int32 NewIndex = Items.Add(Copy);
                MarkCellsForItem(NewIndex, CellX, CellY, Copy.Width, Copy.Height, NewIndex);
                Items[NewIndex].bRotated = true;
                OnRep_Items();
                OnRep_Cells();
                return NewIndex;
            }
        }

        // failed to place
        return -1;
    }
}

int32 UInventoryComponent::PlaceItemAt(const FInventoryItem& Item, int32 StartX, int32 StartY, bool bRotate)
{
    if (!GetOwner()->HasAuthority())
    {
        // Clients currently call server AddItem; explicit placement RPC could be added similarly
        return -1;
    }
    return PlaceItemAt_Internal(Item, StartX, StartY, bRotate);
}

int32 UInventoryComponent::PlaceItemAt_Internal(const FInventoryItem& Item, int32 StartX, int32 StartY, bool bRotate)
{
    FInventoryItem Copy = Item;
    int32 W = FMath::Max(1, Copy.Width);
    int32 H = FMath::Max(1, Copy.Height);

    if (bRotate)
    {
        Swap(W, H);
        Copy.bRotated = true;
    }

    // Ensure placement available
    if (!CanPlaceAt(-1, StartX, StartY, W, H))
    {
        return -1;
    }

    int32 NewIndex = Items.Add(Copy);
    MarkCellsForItem(NewIndex, StartX, StartY, W, H, NewIndex);
    OnRep_Items();
    OnRep_Cells();
    return NewIndex;
}

void UInventoryComponent::ClearItemCells(int32 ItemIndex)
{
    if (!Items.IsValidIndex(ItemIndex))
        return;

    // Find the footprint and clear any cells referencing this item index
    for (int32 i = 0; i < Cells.Num(); ++i)
    {
        if (Cells[i] == ItemIndex)
            Cells[i] = -1;
    }
    Items[ItemIndex].bActive = false;
    Items[ItemIndex].Count = 0;
}

bool UInventoryComponent::RemoveFromItem(int32 ItemIndex, int32 RemoveCount)
{
    if (!GetOwner()->HasAuthority())
    {
        ServerRemoveFromItem(ItemIndex, RemoveCount);
        return false;
    }
    return RemoveFromItem_Internal(ItemIndex, RemoveCount);
}

void UInventoryComponent::ServerRemoveFromItem_Implementation(int32 ItemIndex, int32 RemoveCount)
{
    RemoveFromItem_Internal(ItemIndex, RemoveCount);
}

bool UInventoryComponent::RemoveFromItem_Internal(int32 ItemIndex, int32 RemoveCount)
{
    if (!Items.IsValidIndex(ItemIndex))
        return false;
    FInventoryItem& Item = Items[ItemIndex];
    if (!Item.bActive)
        return false;
    if (!Item.bStackable || RemoveCount >= Item.Count)
    {
        // remove entirely
        ClearItemCells(ItemIndex);
        OnRep_Items();
        OnRep_Cells();
        return true;
    }
    else
    {
        Item.Count = FMath::Max(0, Item.Count - RemoveCount);
        if (Item.Count == 0)
        {
            ClearItemCells(ItemIndex);
        }
        OnRep_Items();
        return true;
    }
}

bool UInventoryComponent::RemoveItem(int32 ItemIndex)
{
    if (!GetOwner()->HasAuthority())
    {
        ServerRemoveItem(ItemIndex);
        return false;
    }
    return RemoveItem_Internal(ItemIndex);
}

void UInventoryComponent::ServerRemoveItem_Implementation(int32 ItemIndex)
{
    RemoveItem_Internal(ItemIndex);
}

bool UInventoryComponent::RemoveItem_Internal(int32 ItemIndex)
{
    if (!Items.IsValidIndex(ItemIndex))
        return false;
    ClearItemCells(ItemIndex);
    OnRep_Items();
    OnRep_Cells();
    return true;
}

bool UInventoryComponent::RotatePlacedItem(int32 ItemIndex)
{
    if (!GetOwner()->HasAuthority())
    {
        ServerRotatePlacedItem(ItemIndex);
        return false;
    }
    return RotatePlacedItem_Internal(ItemIndex);
}

void UInventoryComponent::ServerRotatePlacedItem_Implementation(int32 ItemIndex)
{
    RotatePlacedItem_Internal(ItemIndex);
}

bool UInventoryComponent::RotatePlacedItem_Internal(int32 ItemIndex)
{
    if (!Items.IsValidIndex(ItemIndex))
        return false;
    FInventoryItem& Item = Items[ItemIndex];
    if (!Item.bActive)
        return false;

    // Determine current footprint extents
    int32 CurrW = Item.bRotated ? Item.Height : Item.Width;
    int32 CurrH = Item.bRotated ? Item.Width : Item.Height;

    // Find current top-left by scanning cells for ItemIndex
    int32 FoundCell = -1;
    for (int32 i = 0; i < Cells.Num(); ++i)
    {
        if (Cells[i] == ItemIndex)
        {
            FoundCell = i;
            break;
        }
    }
    if (FoundCell == -1)
        return false;

    int32 CurrX = FoundCell % GridWidth;
    int32 CurrY = FoundCell / GridWidth;

    // Compute rotated dims
    int32 NewW = CurrH;
    int32 NewH = CurrW;

    // Try rotate in place first
    ClearItemCells(ItemIndex); // free existing cells so CanPlaceAt can reuse them
    if (CanPlaceAt(ItemIndex, CurrX, CurrY, NewW, NewH))
    {
        MarkCellsForItem(ItemIndex, CurrX, CurrY, NewW, NewH, ItemIndex);
        Item.bRotated = !Item.bRotated;
        OnRep_Cells();
        OnRep_Items();
        return true;
    }

    // Try find alternative place for rotated item
    int32 Found = FindSpaceForDimensions(NewW, NewH);
    if (Found != -1)
    {
        int32 CellX = Found % GridWidth;
        int32 CellY = Found / GridWidth;
        MarkCellsForItem(ItemIndex, CellX, CellY, NewW, NewH, ItemIndex);
        Item.bRotated = !Item.bRotated;
        OnRep_Cells();
        OnRep_Items();
        return true;
    }

    // Restore original placement if rotation failed
    MarkCellsForItem(ItemIndex, CurrX, CurrY, CurrW, CurrH, ItemIndex);
    return false;
}

bool UInventoryComponent::TransferTo(UInventoryComponent* Destination, int32 ItemIndex, int32 TransferCount)
{
    if (!GetOwner()->HasAuthority())
    {
        ServerTransferTo(Destination, ItemIndex, TransferCount);
        return false;
    }
    return TransferTo_Internal(Destination, ItemIndex, TransferCount);
}

void UInventoryComponent::ServerTransferTo_Implementation(UInventoryComponent* Destination, int32 ItemIndex, int32 TransferCount)
{
    TransferTo_Internal(Destination, ItemIndex, TransferCount);
}

bool UInventoryComponent::TransferTo_Internal(UInventoryComponent* Destination, int32 ItemIndex, int32 TransferCount)
{
    if (!Destination || !Items.IsValidIndex(ItemIndex))
        return false;

    FInventoryItem& SourceItem = Items[ItemIndex];
    if (!SourceItem.bActive)
        return false;

    // If TransferCount == 0 -> transfer entire stack or whole item
    int32 CountToTransfer = TransferCount <= 0 ? SourceItem.Count : FMath::Min(TransferCount, SourceItem.Count);

    // If stackable, try merging to destination stacks first
    FInventoryItem TransferCopy = SourceItem;
    TransferCopy.Count = CountToTransfer;

    // Attempt to add to destination
    int32 AddResult = Destination->AddItem(TransferCopy, true);

    // AddResult == -1 can mean either fully merged (for stackable) or merged but couldn't place remaining.
    // To simplify: if stackable and TransferCount <= SourceCount, we assume destination took CountToTransfer if AddItem returned -1 after TryMergeStack succeeded.
    // Safer approach: check destination items to detect increase. For simplicity here, we treat return != -1 as newly placed index.

    // If stackable and AddItem returned -1, that indicates merge completed and nothing placed new (fully merged)
    bool bFullyTransferred = false;
    if (SourceItem.bStackable)
    {
        // Try merging explicitly, checking remaining after merge
        int32 RemainingAfterMerge = Destination->TryMergeStack(TransferCopy, TransferCopy.Count);
        if (RemainingAfterMerge == 0)
        {
            // all merged; remove from source
            RemoveFromItem_Internal(ItemIndex, CountToTransfer);
            bFullyTransferred = true;
        }
        else
        {
            // Some remained; try to place remaining
            TransferCopy.Count = RemainingAfterMerge;
            int32 PlacedIndex = Destination->AddItem(TransferCopy, true);
            if (PlacedIndex != -1)
            {
                // assume placed; remove transferred amount from source accordingly
                RemoveFromItem(ItemIndex, CountToTransfer - RemainingAfterMerge);
                // if placed, still need to remove the amount that was merged earlier; compute actual removed
                // For simplicity remove CountToTransfer (best-effort). Real production should track exact change.
                RemoveFromItem(ItemIndex, RemainingAfterMerge);
                bFullyTransferred = true;
            }
            else
            {
                // could not fully transfer; attempt to remove only what was merged
                RemoveFromItem(ItemIndex, CountToTransfer - RemainingAfterMerge);
                bFullyTransferred = (CountToTransfer - RemainingAfterMerge) > 0;
            }
        }
    }
    else
    {
        // non-stackable: add as single item (Count should be 1)
        int32 PlacedIndex = Destination->AddItem(TransferCopy, true);
        if (PlacedIndex != -1)
        {
            RemoveItem(ItemIndex);
            bFullyTransferred = true;
        }
    }

    return bFullyTransferred;
}

void UInventoryComponent::OnRep_Items()
{
    BP_OnInventoryChanged();
}

void UInventoryComponent::OnRep_Cells()
{
    BP_OnInventoryChanged();
}

// Server RPC stubs (declarations in header) need implementations for _Validate if using WithValidation; not used here.

