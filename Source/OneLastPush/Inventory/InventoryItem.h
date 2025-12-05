// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemData.h"
#include "InventoryItem.generated.h"

class UInventoryComponent;
class UDataTable;

/**
 * Base class for inventory items
 * Stores item data and grid position information
 */
UCLASS(Blueprintable)
class ONELASTPUSH_API UInventoryItem : public UObject
{
	GENERATED_BODY()

public:
	UInventoryItem();

	/** Grid width in slots */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Grid")
	int32 GridWidth;

	/** Grid height in slots */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Grid")
	int32 GridHeight;

	/** Display name for the item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	FText ItemName;

	/** Item description */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	FText ItemDescription;

	/** Maximum stack size (1 means not stackable) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (ClampMin = "1"))
	int32 MaxStackSize;

	/** Current quantity if stackable */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Item")
	int32 Quantity;

	/** Item icon texture */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	class UTexture2D* Icon;

	/** Item ID for data table lookup */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	FName ItemID;

	/** Item type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	EItemType ItemType;

	/** Item rarity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	EItemRarity Rarity;

	/** Current grid X position */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Grid")
	int32 GridX;

	/** Current grid Y position */
	UPROPERTY(BlueprintReadWrite, Category = "Inventory|Grid")
	int32 GridY;

	/** Owning inventory component */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Grid")
	TWeakObjectPtr<UInventoryComponent> OwningInventory;

	/**
	 * Initialize item from data table row
	 * @param DataTable the data table to read from
	 * @param RowName the row name to look up
	 * @param InQuantity initial quantity
	 * @return true if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	bool InitializeFromDataTable(UDataTable* DataTable, FName RowName, int32 InQuantity = 1);

	/**
	 * Initialize item from data struct
	 * @param ItemData the item data struct
	 * @param InQuantity initial quantity
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	void InitializeFromData(const FInventoryItemData& ItemData, int32 InQuantity = 1);

	/**
	 * Check if item can stack
	 * @return true if item can stack
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Item")
	bool CanStack() const { return MaxStackSize > 1; }

	/**
	 * Check if item is full stack
	 * @return true if quantity equals max stack size
	 */
	UFUNCTION(BlueprintPure, Category = "Inventory|Item")
	bool IsFullStack() const { return Quantity >= MaxStackSize; }

	/**
	 * Try to add quantity to this item
	 * @param Amount quantity to add
	 * @return amount that was actually added
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	int32 AddQuantity(int32 Amount);

	/**
	 * Try to remove quantity from this item
	 * @param Amount quantity to remove
	 * @return amount that was actually removed
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	int32 RemoveQuantity(int32 Amount);

	/**
	 * Static helper to create an item from data table
	 * @param Outer the outer object for the new item
	 * @param DataTable the data table to read from
	 * @param RowName the row name to look up
	 * @param InQuantity initial quantity
	 * @return the created item or nullptr if failed
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Item", meta = (WorldContext = "Outer"))
	static UInventoryItem* CreateItemFromDataTable(UObject* Outer, UDataTable* DataTable, FName RowName, int32 InQuantity = 1);
};
