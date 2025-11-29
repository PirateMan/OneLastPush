// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    // initialize grid
    EnsureGridSize();
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...
    EnsureGridSize();
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}


void UInventoryComponent::EnsureGridSize()
{
    const int32 Desired = GridWidth * GridHeight;
    if (Grid.Num() != Desired)
    {
        Grid.SetNum(Desired);
        for (int32 i = 0; i < Desired; ++i)
        {
            Grid[i] = -1;
        }
    }
}

bool UInventoryComponent::CanPlaceItemAt(const FInventoryItem& Item, int32 X, int32 Y) const
{
    if (X < 0 || Y < 0) return false;
    if (X + Item.Width > GridWidth) return false;
    if (Y + Item.Height > GridHeight) return false;

    for (int32 yy = 0; yy < Item.Height; ++yy)
    {
        for (int32 xx = 0; xx < Item.Width; ++xx)
        {
            int32 idx = CellIndex(X + xx, Y + yy);
            if (!Grid.IsValidIndex(idx)) return false;
            if (Grid[idx] != -1) return false;
        }
    }
    return true;
}

bool UInventoryComponent::FindSpaceForItem(const FInventoryItem& Item, int32& OutX, int32& OutY) const
{
    for (int32 y = 0; y < GridHeight; ++y)
    {
        for (int32 x = 0; x < GridWidth; ++x)
        {
            if (CanPlaceItemAt(Item, x, y))
            {
                OutX = x;
                OutY = y;
                return true;
            }
        }
    }
    return false;
}

void UInventoryComponent::MarkCellsForItem(int32 ItemIndex, int32 X, int32 Y, const FInventoryItem& Item)
{
    for (int32 yy = 0; yy < Item.Height; ++yy)
    {
        for (int32 xx = 0; xx < Item.Width; ++xx)
        {
            int32 idx = CellIndex(X + xx, Y + yy);
            if (Grid.IsValidIndex(idx))
            {
                Grid[idx] = ItemIndex;
            }
        }
    }
}

bool UInventoryComponent::PlaceItemAt(const FInventoryItem& Item, int32 X, int32 Y)
{
    EnsureGridSize();

    if (!CanPlaceItemAt(Item, X, Y))
    {
        return false;
    }

    FPlacedInventoryItem Placed;
    Placed.Item = Item;
    Placed.X = X;
    Placed.Y = Y;

    const int32 NewIndex = PlacedItems.Add(Placed);
    // Stored index should be index into PlacedItems array, but Grid stores indices; subtract 1 to store -1 for empty
    MarkCellsForItem(NewIndex - 1, X, Y, Item);

    return true;
}

bool UInventoryComponent::AddItem(const FInventoryItem& Item, int32 Quantity, int32& OutX, int32& OutY)
{
    EnsureGridSize();

    // copy item and set quantity
    FInventoryItem NewItem = Item;
    NewItem.Quantity = FMath::Clamp(Quantity, 1, Item.MaxStack);

    // try to stack into existing stackable items first
    if (NewItem.bStackable)
    {
        for (int32 i = 0; i < PlacedItems.Num(); ++i)
        {
            FPlacedInventoryItem& PI = PlacedItems[i];
            if (PI.Item.ItemID == NewItem.ItemID && PI.Item.Quantity < PI.Item.MaxStack)
            {
                int32 Space = PI.Item.MaxStack - PI.Item.Quantity;
                int32 ToAdd = FMath::Min(Space, NewItem.Quantity);
                PI.Item.Quantity += ToAdd;
                NewItem.Quantity -= ToAdd;
                if (NewItem.Quantity <= 0)
                {
                    OutX = PI.X;
                    OutY = PI.Y;
                    return true;
                }
            }
        }
    }

    // still have to place remainder as one or more placed items
    while (NewItem.Quantity > 0)
    {
        if (!FindSpaceForItem(NewItem, OutX, OutY))
        {
            return false;
        }

        // place one stack up to MaxStack
        int32 PlaceQty = FMath::Min(NewItem.Quantity, NewItem.MaxStack);
        FInventoryItem PlaceItem = NewItem;
        PlaceItem.Quantity = PlaceQty;

        if (!PlaceItemAt(PlaceItem, OutX, OutY))
        {
            return false;
        }

        NewItem.Quantity -= PlaceQty;
    }

    return true;
}

bool UInventoryComponent::RemoveItemAt(int32 X, int32 Y)
{
    if (X < 0 || Y < 0) return false;
    if (X >= GridWidth || Y >= GridHeight) return false;

    const int32 idx = CellIndex(X, Y);
    if (!Grid.IsValidIndex(idx)) return false;

    int32 PIndex = Grid[idx];
    if (PIndex == -1) return false;

    if (!PlacedItems.IsValidIndex(PIndex))
    {
        // corrupted index; attempt to clear that cell and return
        Grid[idx] = -1;
        return false;
    }

    // remove placed item and clear its cells
    FPlacedInventoryItem Removed = PlacedItems[PIndex];

    // Clear cells referring to this placed item
    for (int32 yy = 0; yy < Removed.Item.Height; ++yy)
    {
        for (int32 xx = 0; xx < Removed.Item.Width; ++xx)
        {
            int32 c = CellIndex(Removed.X + xx, Removed.Y + yy);
            if (Grid.IsValidIndex(c) && Grid[c] == PIndex)
            {
                Grid[c] = -1;
            }
        }
    }

    PlacedItems.RemoveAt(PIndex);

    // after removal, indices after PIndex are shifted; fix grid to update indices
    for (int32 i = 0; i < Grid.Num(); ++i)
    {
        if (Grid[i] > PIndex)
        {
            Grid[i] = Grid[i] - 1;
        }
    }

    return true;
}

