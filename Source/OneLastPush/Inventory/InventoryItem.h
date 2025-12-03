// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"

class UInventoryComponent;

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
};
