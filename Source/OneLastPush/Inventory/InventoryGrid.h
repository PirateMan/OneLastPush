// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryGrid.generated.h"

class UInventoryItem;

/**
 * Grid cell that can hold an item reference
 */
USTRUCT(BlueprintType)
struct FInventoryGridCell
{
	GENERATED_BODY()

	/** Item occupying this cell (only set on top-left corner of item) */
	UPROPERTY()
	TObjectPtr<UInventoryItem> Item;

	FInventoryGridCell() : Item(nullptr) {}
};

/**
 * 2D grid for managing inventory space and item placement
 */
UCLASS()
class ONELASTPUSH_API UInventoryGrid : public UObject
{
	GENERATED_BODY()

public:
	UInventoryGrid();

	/**
	 * Initialize the grid with dimensions
	 * @param InWidth grid width in slots
	 * @param InHeight grid height in slots
	 */
	void Initialize(int32 InWidth, int32 InHeight);

	/**
	 * Try to place an item at a specific grid position
	 * @param Item item to place
	 * @param X grid X position
	 * @param Y grid Y position
	 * @return true if placement was successful
	 */
	bool PlaceItem(UInventoryItem* Item, int32 X, int32 Y);

	/**
	 * Remove an item from the grid
	 * @param Item item to remove
	 * @return true if item was found and removed
	 */
	bool RemoveItem(UInventoryItem* Item);

	/**
	 * Check if an area is free for placement
	 * @param X start X position
	 * @param Y start Y position
	 * @param Width item width
	 * @param Height item height
	 * @param IgnoreItem item to ignore during check (useful for moving)
	 * @return true if area is free
	 */
	bool IsAreaFree(int32 X, int32 Y, int32 Width, int32 Height, UInventoryItem* IgnoreItem = nullptr) const;

	/**
	 * Find free space for an item using first-fit algorithm
	 * @param Item item to find space for
	 * @param OutX output X position
	 * @param OutY output Y position
	 * @return true if space was found
	 */
	bool FindFreeSpace(UInventoryItem* Item, int32& OutX, int32& OutY) const;

	/**
	 * Get all items in the grid
	 * @return array of items
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Grid")
	void GetAllItems(TArray<UInventoryItem*>& OutItems) const;

	/**
	 * Get grid dimensions
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Grid")
	void GetDimensions(int32& OutWidth, int32& OutHeight) const { OutWidth = GridWidth; OutHeight = GridHeight; }

	/**
	 * Check if position is valid
	 */
	bool IsPositionValid(int32 X, int32 Y) const { return X >= 0 && X < GridWidth && Y >= 0 && Y < GridHeight; }

private:
	/** Grid cells */
	UPROPERTY()
	TArray<FInventoryGridCell> Cells;

	/** Grid width */
	int32 GridWidth;

	/** Grid height */
	int32 GridHeight;

	/** Get cell index from coordinates */
	int32 GetCellIndex(int32 X, int32 Y) const { return Y * GridWidth + X; }
};
