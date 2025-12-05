// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UInventoryItem;
class UInventoryGrid;

// Declare multicast delegates for inventory events
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemChanged, UInventoryItem*, bool);

/**
 * Grid-based inventory system component
 * Manages item placement in a 2D grid
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ONELASTPUSH_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	/** Grid width in slots */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Grid", meta = (ClampMin = "1"))
	int32 GridWidth;

	/** Grid height in slots */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Grid", meta = (ClampMin = "1"))
	int32 GridHeight;

	/** Called when item is added or moved */
	FOnInventoryItemChanged OnItemChanged;

protected:
	virtual void BeginPlay() override;

public:
	/**
	 * Add item to inventory at best available position
	 * @param Item item to add
	 * @return true if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(UInventoryItem* Item);

	/**
	 * Add item to inventory at specific position
	 * @param Item item to add
	 * @param X grid X position
	 * @param Y grid Y position
	 * @return true if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemAtPosition(UInventoryItem* Item, int32 X, int32 Y);

	/**
	 * Remove item from inventory
	 * @param Item item to remove
	 * @return true if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(UInventoryItem* Item);

	/**
	 * Move item to new position
	 * @param Item item to move
	 * @param X new grid X position
	 * @param Y new grid Y position
	 * @return true if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool MoveItem(UInventoryItem* Item, int32 X, int32 Y);

	/**
	 * Check if item is in this inventory
	 * @param Item item to check
	 * @return true if item is in inventory
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool ContainsItem(UInventoryItem* Item) const;

	/**
	 * Get all items in inventory
	 * @param OutItems output array of items
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	void GetAllItems(TArray<UInventoryItem*>& OutItems) const;

	/**
	 * Get the inventory grid
	 * @return grid object
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	UInventoryGrid* GetGrid() const { return Grid; }

	/**
	 * Create and add an item from data table
	 * @param DataTable the data table to read from
	 * @param RowName the row name to look up
	 * @param Quantity initial quantity
	 * @return true if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemFromDataTable(UDataTable* DataTable, FName RowName, int32 Quantity = 1);

private:
	/** Inventory grid */
	UPROPERTY()
	TObjectPtr<UInventoryGrid> Grid;
};
