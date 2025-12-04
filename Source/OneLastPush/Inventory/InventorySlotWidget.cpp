// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySlotWidget.h"
#include "InventoryItem.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Brushes/SlateColorBrush.h"

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Initialize visuals
	UpdateVisuals();
}

void UInventorySlotWidget::InitializeSlot(int32 InGridX, int32 InGridY)
{
	GridX = InGridX;
	GridY = InGridY;
	
	UpdateVisuals();
}

void UInventorySlotWidget::SetItem(UInventoryItem* InItem)
{
	Item = InItem;
	UpdateVisuals();
}

void UInventorySlotWidget::ClearSlot()
{
	Item = nullptr;
	UpdateVisuals();
}

void UInventorySlotWidget::SetHighlighted(bool bHighlight)
{
	bIsHighlighted = bHighlight;
	UpdateVisuals();
}

void UInventorySlotWidget::UpdateVisuals()
{
	// Update border color based on highlight state
	if (SlotBorder)
	{
		FLinearColor BorderColor = bIsHighlighted ? HighlightColor : NormalColor;
		SlotBorder->SetBrushColor(BorderColor);
	}

	// Update item icon
	if (ItemIcon)
	{
		if (Item && Item->Icon)
		{
			ItemIcon->SetBrushFromTexture(Item->Icon);
			ItemIcon->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			ItemIcon->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	// Update quantity text
	if (QuantityText)
	{
		if (Item && Item->MaxStackSize > 1 && Item->Quantity > 1)
		{
			QuantityText->SetText(FText::AsNumber(Item->Quantity));
			QuantityText->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			QuantityText->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UInventorySlotWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	
	SetHighlighted(true);
}

void UInventorySlotWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	
	SetHighlighted(false);
}

FReply UInventorySlotWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// Handle click events here
	// In the future, this will handle drag-drop operations
	
	if (Item)
	{
		UE_LOG(LogTemp, Log, TEXT("Clicked slot at (%d, %d) with item: %s"), 
			GridX, GridY, *Item->ItemName.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Clicked empty slot at (%d, %d)"), GridX, GridY);
	}
	
	return FReply::Handled();
}
