// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryUIWidget.generated.h"

class UInventoryComponent;
class UContainerComponent;
class UInventoryItem;
class UInventorySlotWidget;
class UUniformGridPanel;

/**
 * Minimal inventory UI widget for displaying grid and handling drag/drop
 * Most functionality is in C++, minimal UI code needed
 */
UCLASS()
class ONELASTPUSH_API UInventoryUIWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	 * Initialize the UI with player inventory and container
	 * @param InPlayerInventory player's inventory component
	 * @param InContainerComponent container's inventory component (optional)
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void InitializeInventory(UInventoryComponent* InPlayerInventory, UContainerComponent* InContainerComponent = nullptr);

	/**
	 * Show or hide the inventory UI
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void SetInventoryVisible(bool bVisible);

	/**
	 * Close inventory UI
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void CloseInventory();

	/**
	 * Update inventory display (call this when items change)
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void RefreshDisplay();

	/** Get the player inventory component */
	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	UInventoryComponent* GetPlayerInventory() const { return PlayerInventory; }

	/** Get the container component */
	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	UContainerComponent* GetContainerComponent() const { return ContainerComponent; }

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	/** Called when inventory item changes */
	UFUNCTION()
	void OnPlayerInventoryItemChanged(UInventoryItem* Item, bool bAdded);

	/** Create all inventory slot widgets */
	void CreateInventorySlots();

	/** Update slot widgets with current inventory state */
	void UpdateSlots();

protected:
	/** Slot widget class to spawn */
	UPROPERTY(EditAnywhere, Category = "Inventory|UI")
	TSubclassOf<UInventorySlotWidget> SlotWidgetClass;

	/** Grid panel widget reference (bind this in your UMG widget) */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UUniformGridPanel* InventoryGrid;

private:
	/** Player inventory reference */
	UPROPERTY()
	TObjectPtr<UInventoryComponent> PlayerInventory;

	/** Container being viewed */
	UPROPERTY()
	TObjectPtr<UContainerComponent> ContainerComponent;

	/** Array of all slot widgets */
	UPROPERTY()
	TArray<TObjectPtr<UInventorySlotWidget>> SlotWidgets;

	/** Has the grid been initialized */
	bool bGridInitialized = false;
};
