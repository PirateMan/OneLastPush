// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"

UInventoryItem::UInventoryItem()
	: GridWidth(1)
	, GridHeight(1)
	, MaxStackSize(1)
	, Quantity(1)
	, Icon(nullptr)
	, GridX(0)
	, GridY(0)
{
}

int32 UInventoryItem::AddQuantity(int32 Amount)
{
	if (!CanStack() || Amount <= 0)
	{
		return 0;
	}

	const int32 SpaceAvailable = MaxStackSize - Quantity;
	const int32 AmountAdded = FMath::Min(Amount, SpaceAvailable);
	Quantity += AmountAdded;

	return AmountAdded;
}

int32 UInventoryItem::RemoveQuantity(int32 Amount)
{
	if (Amount <= 0)
	{
		return 0;
	}

	const int32 AmountRemoved = FMath::Min(Amount, Quantity);
	Quantity -= AmountRemoved;

	return AmountRemoved;
}
