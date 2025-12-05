// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContainerComponent.generated.h"

class UInventoryComponent;
class UInventoryItem;
class AOneLastPushCharacter;

/**
 * Container component for storing items
 * Can be interacted with to open/close and exchange items with player inventory
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ONELASTPUSH_API UContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UContainerComponent();

	/** Grid width in slots */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Container|Grid", meta = (ClampMin = "1"))
	int32 GridWidth;

	/** Grid height in slots */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Container|Grid", meta = (ClampMin = "1"))
	int32 GridHeight;

protected:
	virtual void BeginPlay() override;

public:
	/**
	 * Open/close the container UI
	 */
	UFUNCTION(BlueprintCallable, Category = "Container")
	void ToggleContainer();

	/**
	 * Open the container
	 */
	UFUNCTION(BlueprintCallable, Category = "Container")
	void OpenContainer(AOneLastPushCharacter* Interactor);

	/**
	 * Close the container
	 */
	UFUNCTION(BlueprintCallable, Category = "Container")
	void CloseContainer();

	/**
	 * Check if container is open
	 */
	UFUNCTION(BlueprintPure, Category = "Container")
	bool IsOpen() const { return bIsOpen; }

	/**
	 * Get the container's inventory
	 */
	UFUNCTION(BlueprintPure, Category = "Container")
	UInventoryComponent* GetInventory() const { return Inventory; }

	/**
	 * Add item to container
	 */
	UFUNCTION(BlueprintCallable, Category = "Container")
	bool AddItem(UInventoryItem* Item);

	/**
	 * Get all items in container
	 */
	UFUNCTION(BlueprintPure, Category = "Container")
	void GetAllItems(TArray<UInventoryItem*>& OutItems) const;

	/**
	 * Add item from data table to container
	 * @param DataTable the data table to read from
	 * @param RowName the row name to look up
	 * @param Quantity initial quantity
	 * @return true if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Container")
	bool AddItemFromDataTable(UDataTable* DataTable, FName RowName, int32 Quantity = 1);

	/**
	 * Get the currently interacting character
	 */
	UFUNCTION(BlueprintPure, Category = "Container")
	AOneLastPushCharacter* GetInteractingCharacter() const { return InteractingCharacter.Get(); }

private:
	/** Container inventory */
	UPROPERTY()
	TObjectPtr<UInventoryComponent> Inventory;

	/** Is container currently open */
	bool bIsOpen;

	/** Currently interacting player character */
	UPROPERTY()
	TWeakObjectPtr<AOneLastPushCharacter> InteractingCharacter;
};
