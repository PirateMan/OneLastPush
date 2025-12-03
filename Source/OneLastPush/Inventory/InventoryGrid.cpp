// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryGrid.h"
#include "InventoryItem.h"

UInventoryGrid::UInventoryGrid()
	: GridWidth(0)
	, GridHeight(0)
{
}

void UInventoryGrid::Initialize(int32 InWidth, int32 InHeight)
{
	GridWidth = FMath::Max(1, InWidth);
	GridHeight = FMath::Max(1, InHeight);

	Cells.SetNum(GridWidth * GridHeight);
}

bool UInventoryGrid::PlaceItem(UInventoryItem* Item, int32 X, int32 Y)
{
	if (!Item || !IsAreaFree(X, Y, Item->GridWidth, Item->GridHeight, Item))
	{
		return false;
	}

	// Set item position
	Item->GridX = X;
	Item->GridY = Y;

	// Mark all cells as occupied by this item
	for (int32 OffsetY = 0; OffsetY < Item->GridHeight; ++OffsetY)
	{
		for (int32 OffsetX = 0; OffsetX < Item->GridWidth; ++OffsetX)
		{
			const int32 CellX = X + OffsetX;
			const int32 CellY = Y + OffsetY;

			if (IsPositionValid(CellX, CellY))
			{
				const int32 CellIndex = GetCellIndex(CellX, CellY);
				// Only store reference at top-left corner
				if (OffsetX == 0 && OffsetY == 0)
				{
					Cells[CellIndex].Item = Item;
				}
			}
		}
	}

	return true;
}

bool UInventoryGrid::RemoveItem(UInventoryItem* Item)
{
	if (!Item)
	{
		return false;
	}

	const int32 StartX = Item->GridX;
	const int32 StartY = Item->GridY;

	// Clear all cells occupied by this item
	for (int32 OffsetY = 0; OffsetY < Item->GridHeight; ++OffsetY)
	{
		for (int32 OffsetX = 0; OffsetX < Item->GridWidth; ++OffsetX)
		{
			const int32 CellX = StartX + OffsetX;
			const int32 CellY = StartY + OffsetY;

			if (IsPositionValid(CellX, CellY))
			{
				const int32 CellIndex = GetCellIndex(CellX, CellY);
				if (Cells[CellIndex].Item == Item)
				{
					Cells[CellIndex].Item = nullptr;
				}
			}
		}
	}

	return true;
}

bool UInventoryGrid::IsAreaFree(int32 X, int32 Y, int32 Width, int32 Height, UInventoryItem* IgnoreItem /*= nullptr*/) const
{
	// Check bounds
	if (X < 0 || Y < 0 || X + Width > GridWidth || Y + Height > GridHeight)
	{
		return false;
	}

	// Check cells
	for (int32 OffsetY = 0; OffsetY < Height; ++OffsetY)
	{
		for (int32 OffsetX = 0; OffsetX < Width; ++OffsetX)
		{
			const int32 CellX = X + OffsetX;
			const int32 CellY = Y + OffsetY;
			const int32 CellIndex = GetCellIndex(CellX, CellY);

			if (Cells[CellIndex].Item && Cells[CellIndex].Item != IgnoreItem)
			{
				return false;
			}
		}
	}

	return true;
}

bool UInventoryGrid::FindFreeSpace(UInventoryItem* Item, int32& OutX, int32& OutY) const
{
	if (!Item)
	{
		return false;
	}

	// Use first-fit algorithm
	for (int32 Y = 0; Y < GridHeight; ++Y)
	{
		for (int32 X = 0; X < GridWidth; ++X)
		{
			if (IsAreaFree(X, Y, Item->GridWidth, Item->GridHeight))
			{
				OutX = X;
				OutY = Y;
				return true;
			}
		}
	}

	return false;
}

void UInventoryGrid::GetAllItems(TArray<UInventoryItem*>& OutItems) const
{
	for (const FInventoryGridCell& Cell : Cells)
	{
		// Only add item once (when we encounter it at its top-left position)
		if (Cell.Item && (!OutItems.Contains(Cell.Item)))
		{
			OutItems.Add(Cell.Item);
		}
	}
}
