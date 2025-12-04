// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryUIWidget.h"
#include "../Components/InventoryComponent.h"
#include "../Components/ContainerComponent.h"
#include "InventoryItem.h"
#include "Components/UniformGridPanel.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

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
	// Get the grid panel widget
	UUniformGridPanel* GridPanel = Cast<UUniformGridPanel>(GetWidgetFromName(FName(TEXT("InventoryGrid"))));
	if (!GridPanel)
	{
		return;
	}

	// Clear existing items from grid
	GridPanel->ClearChildren();

	if (!PlayerInventory)
	{
		return;
	}

	// Get all items from inventory
	TArray<UInventoryItem*> Items;
	PlayerInventory->GetAllItems(Items);

	// Add each item to the grid
	for (UInventoryItem* Item : Items)
	{
		if (!Item)
		{
			continue;
		}

		// Create a simple image widget for the item
		UImage* ItemImage = NewObject<UImage>(GridPanel);
		if (Item->Icon)
		{
			ItemImage->SetBrushFromTexture(Item->Icon);
		}
		else
		{
			// Use a default white color if no icon
			ItemImage->SetColorAndOpacity(FLinearColor::White);
		}

		// Add to grid at item's grid position
		GridPanel->AddChildToUniformGrid(ItemImage, Item->GridY, Item->GridX);

		// Optional: Set size to match item dimensions
		// ItemImage->SetDesiredSizeOverride(FVector2D(Item->GridWidth * 50, Item->GridHeight * 50));
	}
}

void UInventoryUIWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind close button if it exists
	UButton* CloseButton = Cast<UButton>(GetWidgetFromName(FName(TEXT("CloseButton"))));
	if (CloseButton)
	{
		CloseButton->OnClicked.AddDynamic(this, &UInventoryUIWidget::CloseInventory);
	}
}

void UInventoryUIWidget::NativeDestruct()
{
	// Unbind delegates
	if (PlayerInventory)
	{
		PlayerInventory->OnItemChanged.RemoveAll(this);
	}

	Super::NativeDestruct();
}

void UInventoryUIWidget::OnPlayerInventoryItemChanged(UInventoryItem* Item, bool bAdded)
{
	RefreshDisplay();
}
