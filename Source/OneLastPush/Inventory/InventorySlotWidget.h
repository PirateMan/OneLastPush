// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.generated.h"

class UInventoryItem;
class UImage;
class UBorder;
class UTextBlock;

/**
 * Widget representing a single inventory slot
 * Can be empty or contain an item
 */
UCLASS()
class ONELASTPUSH_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Initialize the slot with grid position */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeSlot(int32 InGridX, int32 InGridY);

	/** Set the item displayed in this slot */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetItem(UInventoryItem* InItem);

	/** Get the item in this slot */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	UInventoryItem* GetItem() const { return Item; }

	/** Get grid X position */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetGridX() const { return GridX; }

	/** Get grid Y position */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetGridY() const { return GridY; }

	/** Check if this slot is empty */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool IsEmpty() const { return Item == nullptr; }

	/** Clear the slot */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ClearSlot();

	/** Set highlight state */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetHighlighted(bool bHighlight);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	/** Update the visual representation */
	void UpdateVisuals();

protected:
	/** Background border */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UBorder* SlotBorder;

	/** Item icon image */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* ItemIcon;

	/** Item quantity text */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* QuantityText;

private:
	/** Item stored in this slot */
	UPROPERTY()
	TObjectPtr<UInventoryItem> Item;

	/** Grid X position */
	int32 GridX = 0;

	/** Grid Y position */
	int32 GridY = 0;

	/** Is this slot highlighted */
	bool bIsHighlighted = false;

	/** Normal slot color */
	UPROPERTY(EditAnywhere, Category = "Appearance")
	FLinearColor NormalColor = FLinearColor(0.1f, 0.1f, 0.1f, 0.9f);

	/** Highlighted slot color */
	UPROPERTY(EditAnywhere, Category = "Appearance")
	FLinearColor HighlightColor = FLinearColor(0.3f, 0.3f, 0.5f, 0.9f);

	/** Slot size in pixels */
	UPROPERTY(EditAnywhere, Category = "Appearance")
	float SlotSize = 64.0f;
};
