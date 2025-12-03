// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryUIWidget.h"
#include "../Components/InventoryComponent.h"
#include "../Components/ContainerComponent.h"
#include "InventoryItem.h"

void UInventoryUIWidget::InitializeInventory(UInventoryComponent* InPlayerInventory, UContainerComponent* InContainerComponent)
{
	PlayerInventory = InPlayerInventory;
	ContainerComponent = InContainerComponent;

	// Bind to inventory delegates using lambda
	if (PlayerInventory)
	{
		TWeakObjectPtr<UInventoryUIWidget> WeakThis(this);
		PlayerInventory->OnItemChanged.AddLambda([WeakThis](UInventoryItem* Item, bool bAdded)
		{
			if (WeakThis.IsValid())
			{
				WeakThis->RefreshDisplay();
			}
		});
	}

	RefreshDisplay();
}

void UInventoryUIWidget::SetInventoryVisible(bool bVisible)
{
	SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}

void UInventoryUIWidget::CloseInventory()
{
	SetInventoryVisible(false);
}

void UInventoryUIWidget::RefreshDisplay()
{
	// This can be overridden in Blueprint for custom UI updates
	// The core inventory management is done in C++
}

void UInventoryUIWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInventoryUIWidget::NativeDestruct()
{
	// Delegates are cleaned up automatically
	Super::NativeDestruct();
}

void UInventoryUIWidget::OnPlayerInventoryItemChanged(UInventoryItem* Item, bool bAdded)
{
	RefreshDisplay();
}
