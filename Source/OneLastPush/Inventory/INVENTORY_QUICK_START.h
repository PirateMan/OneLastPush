// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**

GRID INVENTORY SYSTEM - QUICK START GUIDE
==========================================

This document provides step-by-step instructions to set up and use the grid inventory system
in your UE5 game with minimal Blueprint involvement.

TABLE OF CONTENTS:
==================
1. Setup Instructions
2. Creating Inventory Items
3. Setting Up Input Actions
4. Basic Usage Examples
5. Advanced Features
6. Troubleshooting


1. SETUP INSTRUCTIONS
======================

A. Character Setup

The inventory system is already integrated into AOneLastPushCharacter:
- Player characters automatically have an InventoryComponent
- Grid size is configurable (default 10x5)
- Access via GetInventory()

To use in your character:
1. Open your character Blueprint
2. Set GridWidth and GridHeight in the Inventory component details
3. Input actions will automatically be bound in C++

B. Container Setup

To create a container (chest, barrel, etc.):
1. Create a new Actor Blueprint
2. Add a UContainerComponent to it
3. Configure GridWidth and GridHeight
4. Place in your level

C. Input Mapping

These input actions need to be added to your EnhancedInput system:

1. IA_OpenInventory
   - Trigger: Your inventory toggle key (e.g., Tab or I)
   - Function: Opens/closes player inventory
   - Assigned to: OpenInventoryAction on character

2. IA_Interact
   - Trigger: Your interact key (e.g., E)
   - Function: Opens/closes nearby containers
   - Assigned to: InteractAction on character

2. CREATING INVENTORY ITEMS
=============================

Method A: Blueprint

1. Create new Blueprint child of UInventoryItem
2. Set these properties in defaults:
   - GridWidth: 1 (or however wide the item is)
   - GridHeight: 1 (or however tall the item is)
   - MaxStackSize: 1 for unique items, >1 for stackable items
   - ItemName: Display name
   - ItemDescription: Tooltip text
   - Icon: Item icon texture

3. Click "Compile" and "Save"

Method B: C++ (for custom item types)

```cpp
// MyCustomItem.h
#pragma once

#include "CoreMinimal.h"
#include "Inventory/InventoryItem.h"
#include "MyCustomItem.generated.h"

UCLASS()
class YOURPROJECT_API UMyCustomItem : public UInventoryItem
{
	GENERATED_BODY()

public:
	UMyCustomItem();

	// Your custom properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Durability;

	// Your custom methods
	UFUNCTION(BlueprintCallable)
	void OnItemUsed();
};
```

Then in your .cpp:
```cpp
UMyCustomItem::UMyCustomItem()
{
	GridWidth = 1;
	GridHeight = 1;
	MaxStackSize = 100; // for potions, etc.
	ItemName = FText::FromString("Potion");
}

void UMyCustomItem::OnItemUsed()
{
	// Custom logic here
}
```

3. SETTING UP INPUT ACTIONS
=============================

EnhancedInput System Required:

1. In your InputMappingContext:
   - Add IA_OpenInventory mapped to Tab key (or your preference)
   - Add IA_Interact mapped to E key (or your preference)

2. Assign to Character:
   - Set OpenInventoryAction property
   - Set InteractAction property

Input callbacks:
- ToggleInventory() - Called when IA_OpenInventory is triggered
- Interact() - Called when IA_Interact is triggered

4. BASIC USAGE EXAMPLES
=========================

A. Adding Items to Player Inventory (C++):

```cpp
void AMyGameMode::GivePlayerLoot()
{
	AOneLastPushCharacter* Player = Cast<AOneLastPushCharacter>(PlayerController->GetCharacter());
	if (Player && Player->GetInventory())
	{
		// Create item
		UInventoryItem* NewItem = NewObject<UInventoryItem>();
		NewItem->GridWidth = 2;
		NewItem->GridHeight = 2;
		NewItem->MaxStackSize = 1;
		NewItem->ItemName = FText::FromString("Sword");

		// Add to inventory
		if (Player->GetInventory()->AddItem(NewItem))
		{
			UE_LOG(LogTemp, Warning, TEXT("Item added successfully"));
		}
	}
}
```

B. Moving Items Within Inventory (Blueprint):

1. Get Player Character
2. Get Inventory component
3. Call "Move Item" with:
   - Item (the item to move)
   - X, Y (new grid position)

C. Transferring Items Between Inventories (C++):

```cpp
bool TransferItemBetweenInventories(UInventoryItem* Item, 
	UInventoryComponent* SourceInventory, 
	UInventoryComponent* TargetInventory)
{
	if (!Item || !SourceInventory || !TargetInventory)
	{
		return false;
	}

	// Remove from source
	if (SourceInventory->RemoveItem(Item))
	{
		// Add to target
		if (TargetInventory->AddItem(Item))
		{
			return true;
		}
		else
		{
			// If target fails, put back in source
			SourceInventory->AddItemAtPosition(Item, Item->GridX, Item->GridY);
			return false;
		}
	}

	return false;
}
```

D. Opening Container via Blueprint:

1. Get nearby Container Component
2. Cast Interacting Actor to Character
3. Call "Open Container" passing the character

E. Container Interaction in Game:

```cpp
// In your character class

void AMyCharacter::OnOpenContainerPressed()
{
	// Find nearby containers
	// Containers broadcast their open/close state
	// Update UI based on container's IsOpen() status
}
```

5. ADVANCED FEATURES
=======================

A. Custom Item Stacking:

```cpp
UInventoryItem* stackableItem = NewObject<UInventoryItem>();
stackableItem->MaxStackSize = 50;  // Can stack up to 50
stackableItem->Quantity = 10;      // Currently have 10

// Add 20 more
int32 AmountAdded = stackableItem->AddQuantity(20);
// AmountAdded will be 20 (now at 30/50)

// Try to add 50 more
AmountAdded = stackableItem->AddQuantity(50);
// AmountAdded will be 20 (now at 50/50, full stack)
```

B. Listening to Inventory Changes:

```cpp
// In your widget or component
if (UInventoryComponent* Inventory = Player->GetInventory())
{
	TWeakObjectPtr<UMyWidget> WeakThis(this);
	Inventory->OnItemChanged.AddLambda([WeakThis](UInventoryItem* Item, bool bAdded)
	{
		if (WeakThis.IsValid())
		{
			if (bAdded)
			{
				WeakThis->DisplayItemAdded(Item);
			}
			else
			{
				WeakThis->DisplayItemRemoved(Item);
			}
		}
	});
}
```

C. Finding Free Space:

```cpp
UInventoryComponent* Inventory = Player->GetInventory();
if (Inventory && Inventory->GetGrid())
{
	int32 FreeX, FreeY;
	if (Inventory->GetGrid()->FindFreeSpace(Item, FreeX, FreeY))
	{
		Inventory->AddItemAtPosition(Item, FreeX, FreeY);
	}
}
```

D. Checking if Area is Free:

```cpp
UInventoryGrid* Grid = Inventory->GetGrid();
if (Grid && Grid->IsAreaFree(X, Y, Width, Height))
{
	// Can place item here
}
```

6. TROUBLESHOOTING
===================

Issue: Items won't add to inventory
- Check that GridWidth and GridHeight are configured
- Verify inventory grid is initialized (check BeginPlay)
- Ensure item's GridWidth/GridHeight fit in inventory

Issue: Item disappears after transfer
- Make sure to call RemoveItem() before adding to another inventory
- Verify OwningInventory pointer is updated

Issue: Container won't open
- Check InteractAction is bound
- Verify container is within 200 unit interaction radius
- Ensure OpenContainer() is called with valid character

Issue: Items stack unexpectedly
- Check MaxStackSize > 1
- Verify Quantity matches MaxStackSize when full

Issue: No grid visualization
- Grid is managed purely in C++
- UI should be implemented in Blueprint using the grid data

ARCHITECTURE OVERVIEW
======================

Classes & Files:
- InventoryItem.h/cpp - Base item class
- InventoryGrid.h/cpp - 2D grid data structure
- InventoryComponent.h/cpp - Main inventory manager
- ContainerComponent.h/cpp - Container actor component
- InventoryUIWidget.h/cpp - Base UI widget
- InventoryItemExample.h/cpp - Example custom item

Delegates (C++ only, not Blueprint visible):
- UInventoryComponent::OnItemChanged
  Fired when item is added, moved, or removed
  Parameters: (UInventoryItem* Item, bool bAdded)

KEY CONCEPTS
============

Grid Coordinates:
- (0,0) is top-left
- X increases to the right
- Y increases downward
- Multi-cell items occupy all cells from top-left to bottom-right

Item Ownership:
- Items can only be in one inventory at a time
- OwningInventory tracks parent inventory
- Transferring auto-removes from previous inventory

Grid Storage:
- Cells only store reference at item's top-left corner
- Remaining cells are marked as occupied
- Prevents overlapping items

NEXT STEPS
==========

1. Create your item Blueprints
2. Add containers to your level
3. Create an inventory UI widget (in Blueprint)
4. Test item pickup and transfer
5. Customize appearance and behavior

For questions or issues, refer to the source code comments in:
- Source/OneLastPush/Inventory/InventoryItem.h
- Source/OneLastPush/Inventory/InventoryGrid.h
- Source/OneLastPush/Components/InventoryComponent.h

*/
