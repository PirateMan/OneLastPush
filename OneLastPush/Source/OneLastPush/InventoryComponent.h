// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
    GENERATED_BODY()

    // A simple identifier for the item type (could be a soft class reference or gameplay tag in future)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FName ItemID = NAME_None;

    // Base (unrotated) size in grid cells
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 Width = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 Height = 1;

    // If item can be stacked
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    bool bStackable = false;

    // Current stack count (if stackable)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 Count = 1;

    // Maximum stack size
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 MaxStack = 1;

    // True when this entry is active (not removed)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    bool bActive = true;

    // True if the item is placed rotated (Width/Height swapped)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    bool bRotated = false;

    // Optional gameplay tags for querying
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FGameplayTagContainer Tags;
};

USTRUCT()
struct FPlacedItem
{
    GENERATED_BODY()

    // Index into Items array
    int32 ItemIndex = -1;

    // Top-left position in grid
    int32 X = 0;
    int32 Y = 0;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONELASTPUSH_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    // Initialize/resize the grid
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void InitializeGrid(int32 InWidth, int32 InHeight);

    // Add item (client calls server; returns index only on server). Returns index of placed item or -1.
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    int32 AddItem(const FInventoryItem& Item, bool bAllowRotate = true);

    // Place item explicitly at a grid position (top-left), optionally rotate. Returns item index or -1 on fail.
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    int32 PlaceItemAt(const FInventoryItem& Item, int32 StartX, int32 StartY, bool bRotate = false);

    // Remove a given number of stack from an item index. If count >= stack, the item is removed.
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool RemoveFromItem(int32 ItemIndex, int32 RemoveCount = 1);

    // Remove item completely (clears cells)
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool RemoveItem(int32 ItemIndex);

    // Rotate a placed item (attempts rotate in place or fails)
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool RotatePlacedItem(int32 ItemIndex);

    // Transfer item (or a stack count) to another inventory. Returns true if fully transferred.
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    bool TransferTo(UInventoryComponent* Destination, int32 ItemIndex, int32 TransferCount = 0);

    // Query helpers
    UFUNCTION(BlueprintPure, Category = "Inventory")
    int32 GetGridWidth() const { return GridWidth; }

    UFUNCTION(BlueprintPure, Category = "Inventory")
    int32 GetGridHeight() const { return GridHeight; }

    UFUNCTION(BlueprintPure, Category = "Inventory")
    const TArray<FInventoryItem>& GetItems() const { return Items; }

    // Blueprint notification when inventory updates from replication
    UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
    void BP_OnInventoryChanged();

protected:
    virtual void BeginPlay() override;

private:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Override to set lifetime replicated props
    virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

    // grid dims
    UPROPERTY(EditAnywhere, Category = "Inventory")
    int32 GridWidth = 8;

    UPROPERTY(EditAnywhere, Category = "Inventory")
    int32 GridHeight = 6;

    // Grid cells; stores item index placed at cell, -1 for empty
    UPROPERTY(ReplicatedUsing=OnRep_Cells)
    TArray<int32> Cells;

    // All items (index used by grid cells)
    UPROPERTY(ReplicatedUsing=OnRep_Items, VisibleAnywhere, Category = "Inventory")
    TArray<FInventoryItem> Items;

    // Replication handlers
    UFUNCTION()
    void OnRep_Items();

    UFUNCTION()
    void OnRep_Cells();

    // Server RPCs for client requests
    UFUNCTION(Server, Reliable)
    void ServerAddItem(const FInventoryItem& Item, bool bAllowRotate);

    UFUNCTION(Server, Reliable)
    void ServerRemoveFromItem(int32 ItemIndex, int32 RemoveCount);

    UFUNCTION(Server, Reliable)
    void ServerRemoveItem(int32 ItemIndex);

    UFUNCTION(Server, Reliable)
    void ServerRotatePlacedItem(int32 ItemIndex);

    UFUNCTION(Server, Reliable)
    void ServerTransferTo(UInventoryComponent* Destination, int32 ItemIndex, int32 TransferCount);

    // Internal implementations that actually mutate arrays (call only on server)
    int32 AddItem_Internal(const FInventoryItem& Item, bool bAllowRotate = true);
    int32 PlaceItemAt_Internal(const FInventoryItem& Item, int32 StartX, int32 StartY, bool bRotate = false);
    bool RemoveFromItem_Internal(int32 ItemIndex, int32 RemoveCount = 1);
    bool RemoveItem_Internal(int32 ItemIndex);
    bool RotatePlacedItem_Internal(int32 ItemIndex);
    bool TransferTo_Internal(UInventoryComponent* Destination, int32 ItemIndex, int32 TransferCount = 0);

    // Helpers
    int32 GetCellIndex(int32 X, int32 Y) const;
    bool IsInBounds(int32 X, int32 Y) const;
    bool CanPlaceAt(int32 ItemIndex, int32 StartX, int32 StartY, int32 ItemW, int32 ItemH) const;
    void MarkCellsForItem(int32 ItemIndex, int32 StartX, int32 StartY, int32 ItemW, int32 ItemH, int32 Value);
    int32 FindSpaceForDimensions(int32 W, int32 H) const;
    int32 TryMergeStack(const FInventoryItem& Item, int32 AddCount); // returns remaining to place
    void ClearItemCells(int32 ItemIndex);

    // Note: Items/Cells are authoritative on server
};
