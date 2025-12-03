// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItemExample.h"

UInventoryItemExample::UInventoryItemExample()
	: Durability(100.0f)
{
	// Set some example properties
	GridWidth = 2;
	GridHeight = 2;
	MaxStackSize = 1;
	ItemName = FText::FromString("Example Item");
	ItemDescription = FText::FromString("This is an example inventory item");
}

void UInventoryItemExample::OnItemUsed()
{
	// Example method that could be called when item is used
	if (Durability > 0)
	{
		Durability -= 10.0f;
	}
}
