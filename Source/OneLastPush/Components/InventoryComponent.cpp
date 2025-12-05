// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "../Inventory/InventoryItem.h"
#include "../Inventory/InventoryGrid.h"

UInventoryComponent::UInventoryComponent()
	: GridWidth(10)
	, GridHeight(5)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// Create and initialize grid
	Grid = NewObject<UInventoryGrid>(this);
	if (Grid)
	{
		Grid->Initialize(GridWidth, GridHeight);
	}
}

bool UInventoryComponent::AddItem(UInventoryItem* Item)
{
	if (!Item || !Grid)
	{
		return false;
	}

	int32 GridX, GridY;
	if (Grid->FindFreeSpace(Item, GridX, GridY))
	{
		return AddItemAtPosition(Item, GridX, GridY);
	}

	return false;
}

bool UInventoryComponent::AddItemAtPosition(UInventoryItem* Item, int32 X, int32 Y)
{
	if (!Item || !Grid)
	{
		return false;
	}

	// If item is already in another inventory, remove it first
	if (Item->OwningInventory.IsValid() && Item->OwningInventory.Get() != this)
	{
		Item->OwningInventory.Get()->RemoveItem(Item);
	}

	// Place item in grid
	if (Grid->PlaceItem(Item, X, Y))
	{
		Item->OwningInventory = this;
		OnItemChanged.Broadcast(Item, true);
		return true;
	}

	return false;
}

bool UInventoryComponent::RemoveItem(UInventoryItem* Item)
{
	if (!Item || !Grid)
	{
		return false;
	}

	if (Grid->RemoveItem(Item))
	{
		Item->OwningInventory = nullptr;
		OnItemChanged.Broadcast(Item, false);
		return true;
	}

	return false;
}

bool UInventoryComponent::MoveItem(UInventoryItem* Item, int32 X, int32 Y)
{
	if (!Item || !Grid || !ContainsItem(Item))
	{
		return false;
	}

	// Check if new position is free (ignoring this item)
	if (Grid->IsAreaFree(X, Y, Item->GridWidth, Item->GridHeight, Item))
	{
		// Remove from old position and place at new position
		Grid->RemoveItem(Item);
		if (Grid->PlaceItem(Item, X, Y))
		{
			OnItemChanged.Broadcast(Item, true);
			return true;
		}
		else
		{
			// Restore to old position if placement failed
			Grid->PlaceItem(Item, Item->GridX, Item->GridY);
			return false;
		}
	}

	return false;
}

bool UInventoryComponent::ContainsItem(UInventoryItem* Item) const
{
	if (!Item || !Grid)
	{
		return false;
	}

	TArray<UInventoryItem*> Items;
	Grid->GetAllItems(Items);
	return Items.Contains(Item);
}

void UInventoryComponent::GetAllItems(TArray<UInventoryItem*>& OutItems) const
{
	if (Grid)
	{
		Grid->GetAllItems(OutItems);
	}
}

bool UInventoryComponent::AddItemFromDataTable(UDataTable* DataTable, FName RowName, int32 Quantity)
{
	if (!DataTable)
	{
		UE_LOG(LogTemp, Error, TEXT("AddItemFromDataTable: DataTable is null"));
		return false;
	}

	// Create item from data table
	UInventoryItem* NewItem = UInventoryItem::CreateItemFromDataTable(this, DataTable, RowName, Quantity);
	if (!NewItem)
	{
		UE_LOG(LogTemp, Error, TEXT("AddItemFromDataTable: Failed to create item from row '%s'"), *RowName.ToString());
		return false;
	}

	// Try to add to inventory
	if (AddItem(NewItem))
	{
		UE_LOG(LogTemp, Log, TEXT("AddItemFromDataTable: Successfully added '%s' x%d"), *NewItem->ItemName.ToString(), NewItem->Quantity);
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AddItemFromDataTable: Failed to add item '%s' to inventory (no space?)"), *NewItem->ItemName.ToString());
		return false;
	}
}

