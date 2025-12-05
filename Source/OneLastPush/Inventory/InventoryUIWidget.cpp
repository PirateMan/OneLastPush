// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryUIWidget.h"
#include "../Components/InventoryComponent.h"
#include "../Components/ContainerComponent.h"
#include "InventoryItem.h"
#include "InventorySlotWidget.h"
#include "../Inventory/InventoryGrid.h"
#include "Components/UniformGridPanel.h"
#include "Components/VerticalBox.h"
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

	// Bind to container inventory delegates if we have a container
	if (ContainerComponent && ContainerComponent->GetInventory())
	{
		TWeakObjectPtr<UInventoryUIWidget> WeakThis(this);
		ContainerComponent->GetInventory()->OnItemChanged.AddLambda([WeakThis](UInventoryItem* Item, bool bAdded)
		{
			if (WeakThis.IsValid())
			{
				WeakThis->UpdateContainerSlots();
			}
		});
	}

	// Create the grid slots if not already created
	if (!bGridInitialized)
	{
		CreateInventorySlots();
		bGridInitialized = true;
	}

	// Create container slots if we have a container
	if (ContainerComponent)
	{
		CreateContainerSlots();
		
		// Show container section
		if (ContainerVerticalBox)
		{
			ContainerVerticalBox->SetVisibility(ESlateVisibility::Visible);
		}
	}
	else
	{
		// Clear container slots if no container
		ClearContainerSlots();
		
		// Hide container section
		if (ContainerVerticalBox)
		{
			ContainerVerticalBox->SetVisibility(ESlateVisibility::Collapsed);
		}
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

void UInventoryUIWidget::CreateInventorySlots()
{
	if (!InventoryGrid || !PlayerInventory)
	{
		return;
	}

	// Clear existing slots
	InventoryGrid->ClearChildren();
	SlotWidgets.Empty();

	// Get grid dimensions from the inventory component
	const int32 GridWidth = PlayerInventory->GridWidth;
	const int32 GridHeight = PlayerInventory->GridHeight;

	// Create a slot widget for each grid cell
	for (int32 Y = 0; Y < GridHeight; ++Y)
	{
		for (int32 X = 0; X < GridWidth; ++X)
		{
			// Create slot widget
			UInventorySlotWidget* SlotWidget = CreateWidget<UInventorySlotWidget>(this, SlotWidgetClass);
			if (SlotWidget)
			{
				// Initialize the slot with its grid position
				SlotWidget->InitializeSlot(X, Y);

				// Add to the grid panel
				InventoryGrid->AddChildToUniformGrid(SlotWidget, Y, X);

				// Store reference
				SlotWidgets.Add(SlotWidget);
			}
		}
	}
}

void UInventoryUIWidget::RefreshDisplay()
{
	UpdateSlots();
}

void UInventoryUIWidget::UpdateSlots()
{
	if (!PlayerInventory || SlotWidgets.Num() == 0)
	{
		return;
	}

	// Get all items from inventory
	TArray<UInventoryItem*> Items;
	PlayerInventory->GetAllItems(Items);

	// First, clear all slots
	for (UInventorySlotWidget* SlotWidget : SlotWidgets)
	{
		if (SlotWidget)
		{
			SlotWidget->ClearSlot();
		}
	}

	// Then, populate slots with items
	for (UInventoryItem* Item : Items)
	{
		if (!Item)
		{
			continue;
		}

		// Find the slot at this item's grid position
		for (UInventorySlotWidget* SlotWidget : SlotWidgets)
		{
			if (SlotWidget && SlotWidget->GetGridX() == Item->GridX && SlotWidget->GetGridY() == Item->GridY)
			{
				SlotWidget->SetItem(Item);
				break;
			}
		}
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

void UInventoryUIWidget::CreateContainerSlots()
{
	if (!ContainerGrid || !ContainerComponent || !ContainerComponent->GetInventory())
	{
		return;
	}

	// Clear existing container slots
	ContainerGrid->ClearChildren();
	ContainerSlotWidgets.Empty();

	UInventoryComponent* ContainerInventory = ContainerComponent->GetInventory();
	const int32 GridWidth = ContainerInventory->GridWidth;
	const int32 GridHeight = ContainerInventory->GridHeight;

	// Create a slot widget for each grid cell
	for (int32 Y = 0; Y < GridHeight; ++Y)
	{
		for (int32 X = 0; X < GridWidth; ++X)
		{
			// Create slot widget
			UInventorySlotWidget* SlotWidget = CreateWidget<UInventorySlotWidget>(this, SlotWidgetClass);
			if (SlotWidget)
			{
				// Initialize the slot with its grid position
				SlotWidget->InitializeSlot(X, Y);

				// Add to the grid panel
				ContainerGrid->AddChildToUniformGrid(SlotWidget, Y, X);

				// Store reference
				ContainerSlotWidgets.Add(SlotWidget);
			}
		}
	}

	// Update with current container contents
	UpdateContainerSlots();
}

void UInventoryUIWidget::UpdateContainerSlots()
{
	if (!ContainerComponent || !ContainerComponent->GetInventory() || ContainerSlotWidgets.Num() == 0)
	{
		return;
	}

	// Get all items from container inventory
	TArray<UInventoryItem*> Items;
	ContainerComponent->GetInventory()->GetAllItems(Items);

	// First, clear all slots
	for (UInventorySlotWidget* SlotWidget : ContainerSlotWidgets)
	{
		if (SlotWidget)
		{
			SlotWidget->ClearSlot();
		}
	}

	// Then, populate slots with items
	for (UInventoryItem* Item : Items)
	{
		if (!Item)
		{
			continue;
		}

		// Find the slot at this item's grid position
		for (UInventorySlotWidget* SlotWidget : ContainerSlotWidgets)
		{
			if (SlotWidget && SlotWidget->GetGridX() == Item->GridX && SlotWidget->GetGridY() == Item->GridY)
			{
				SlotWidget->SetItem(Item);
				break;
			}
		}
	}
}

void UInventoryUIWidget::ClearContainerSlots()
{
	if (ContainerGrid)
	{
		ContainerGrid->ClearChildren();
	}
	ContainerSlotWidgets.Empty();
}
