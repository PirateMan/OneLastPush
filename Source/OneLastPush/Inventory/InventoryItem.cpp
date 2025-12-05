// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"
#include "Engine/DataTable.h"

UInventoryItem::UInventoryItem()
	: GridWidth(1)
	, GridHeight(1)
	, MaxStackSize(1)
	, Quantity(1)
	, Icon(nullptr)
	, ItemID(NAME_None)
	, ItemType(EItemType::Misc)
	, Rarity(EItemRarity::Common)
	, GridX(0)
	, GridY(0)
{
}

bool UInventoryItem::InitializeFromDataTable(UDataTable* DataTable, FName RowName, int32 InQuantity)
{
	if (!DataTable)
	{
		UE_LOG(LogTemp, Error, TEXT("InitializeFromDataTable: DataTable is null"));
		return false;
	}

	// Look up the row
	FInventoryItemData* ItemData = DataTable->FindRow<FInventoryItemData>(RowName, TEXT("InventoryItem"));
	if (!ItemData)
	{
		UE_LOG(LogTemp, Error, TEXT("InitializeFromDataTable: Failed to find row '%s' in data table"), *RowName.ToString());
		return false;
	}

	// Initialize from the data
	InitializeFromData(*ItemData, InQuantity);
	return true;
}

void UInventoryItem::InitializeFromData(const FInventoryItemData& ItemData, int32 InQuantity)
{
	ItemID = ItemData.ItemID;
	ItemName = ItemData.ItemName;
	ItemDescription = ItemData.ItemDescription;
	Icon = ItemData.Icon;
	GridWidth = ItemData.GridWidth;
	GridHeight = ItemData.GridHeight;
	MaxStackSize = ItemData.MaxStackSize;
	ItemType = ItemData.ItemType;
	Rarity = ItemData.Rarity;
	
	// Clamp quantity to max stack size
	Quantity = FMath::Clamp(InQuantity, 1, MaxStackSize);
}

UInventoryItem* UInventoryItem::CreateItemFromDataTable(UObject* Outer, UDataTable* DataTable, FName RowName, int32 InQuantity)
{
	if (!Outer || !DataTable)
	{
		return nullptr;
	}

	// Create new item instance
	UInventoryItem* NewItem = NewObject<UInventoryItem>(Outer);
	if (NewItem && NewItem->InitializeFromDataTable(DataTable, RowName, InQuantity))
	{
		return NewItem;
	}

	return nullptr;
}

int32 UInventoryItem::AddQuantity(int32 Amount)
{
	// Calculate how much we can actually add
	int32 SpaceLeft = MaxStackSize - Quantity;
	int32 AmountToAdd = FMath::Min(Amount, SpaceLeft);

	// Add the quantity
	Quantity += AmountToAdd;

	return AmountToAdd;
}

int32 UInventoryItem::RemoveQuantity(int32 Amount)
{
	// Calculate how much we can actually remove
	int32 AmountToRemove = FMath::Min(Amount, Quantity);

	// Remove the quantity
	Quantity -= AmountToRemove;

	return AmountToRemove;
}
