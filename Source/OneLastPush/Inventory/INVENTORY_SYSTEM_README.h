// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**

GRID INVENTORY SYSTEM DOCUMENTATION
====================================

OVERVIEW:
--------
A complete C++-based grid inventory system for UE5 games with minimal Blueprint requirements.
Supports items of various sizes, drag-and-drop between inventories and containers.


COMPONENTS:
-----------

1. UInventoryItem
   - Base class for all inventory items
   - Properties: GridWidth, GridHeight, MaxStackSize, Quantity, Icon, etc.
   - Manages item stacking and quantity operations
   - Location: Source/OneLastPush/Inventory/InventoryItem.h/cpp

2. UInventoryGrid
   - 2D grid data structure for managing item placement
   - Handles collision detection and space allocation
   - Uses first-fit algorithm for finding free space
   - Location: Source/OneLastPush/Inventory/InventoryGrid.h/cpp

3. UInventoryComponent (on character)
   - Main inventory manager component
   - Delegates: OnItemAdded, OnItemRemoved, OnItemMoved
   - Methods: AddItem(), AddItemAtPosition(), RemoveItem(), MoveItem()
   - Location: Source/OneLastPush/Components/InventoryComponent.h/cpp

4. UContainerComponent
   - Container actor component for storing items
   - Delegates: OnContainerOpened, OnContainerClosed
   - Methods: OpenContainer(), CloseContainer(), AddItem()
   - Can be placed on any actor to make it a container
   - Location: Source/OneLastPush/Components/ContainerComponent.h/cpp

5. UInventoryUIWidget
   - Minimal UI widget for visualization
   - Handles event binding and UI updates
   - Designed to be extended in Blueprint
   - Location: Source/OneLastPush/Inventory/InventoryUIWidget.h/cpp


USAGE EXAMPLES:
---------------

Creating an item programmatically:
  UInventoryItem* NewItem = NewObject<UInventoryItem>();
  NewItem->GridWidth = 2;
  NewItem->GridHeight = 2;
  NewItem->MaxStackSize = 1;
  NewItem->ItemName = FText::FromString("Sword");

Adding item to player inventory:
  AOneLastPushCharacter* Player = GetPlayer();
  UInventoryItem* Item = CreateItem();
  Player->GetInventory()->AddItem(Item);

Moving item within inventory:
  UInventoryComponent* Inventory = Player->GetInventory();
  Inventory->MoveItem(Item, 3, 2); // Move to grid position (3, 2)

Transferring items between inventories:
  UInventoryComponent* SourceInventory = Source->GetInventory();
  UInventoryComponent* TargetInventory = Target->GetInventory();
  
  SourceInventory->RemoveItem(Item);
  TargetInventory->AddItem(Item);

Creating a container:
  AActor* ContainerActor = GetWorld()->SpawnActor<AActor>();
  UContainerComponent* Container = NewObject<UContainerComponent>(ContainerActor);
  Container->GridWidth = 8;
  Container->GridHeight = 4;
  ContainerActor->SetRootComponent(Container);

Handling inventory events in Blueprint:
  MyInventory->OnItemAdded.AddDynamic(this, &AMyCharacter::OnItemAdded);
  MyInventory->OnItemRemoved.AddDynamic(this, &AMyCharacter::OnItemRemoved);


BLUEPRINT SETUP:
----------------

1. Create a Blueprint from UInventoryItem for custom items
2. Set GridWidth, GridHeight, MaxStackSize as needed
3. Set ItemName, ItemDescription, and Icon
4. Add custom properties as needed

Example Blueprint Item:
  - Base Class: UInventoryItem
  - GridWidth: 1
  - GridHeight: 1
  - MaxStackSize: 100
  - ItemName: "Health Potion"


INPUT SETUP:
-----------

Add these input actions to your EnhancedInput system:

1. IA_OpenInventory (required)
   - Mapped to Tab or I key
   - Calls ToggleInventory() on character

2. IA_Interact (required)
   - Mapped to E key
   - Calls Interact() on character
   - Opens/closes nearby containers

Both actions need to be set in the character's properties:
  - OneLastPushCharacter::OpenInventoryAction
  - OneLastPushCharacter::InteractAction


DRAG AND DROP (IN-GAME):
------------------------

The system handles item movement through:
1. MoveItem(Item, NewX, NewY) - Move within same inventory
2. RemoveItem() + AddItem() - Transfer between inventories

UI can bind to events to handle visual feedback:
  OnItemMoved.Broadcast() - Called when item position changes
  OnItemAdded.Broadcast() - Called when item added
  OnItemRemoved.Broadcast() - Called when item removed


INTERACTION WORKFLOW:
---------------------

1. Player presses IA_OpenInventory
   ? ToggleInventory() is called
   ? Can broadcast custom event to show/hide UI

2. Player approaches container
   ? Interact() traces for nearby containers
   ? Finds closest container within InteractionRadius

3. Player presses IA_Interact
   ? Opens container UI (or closes if already open)
   ? OnContainerOpened is broadcasted
   ? UI can display container inventory alongside player inventory

4. Player drags items:
   ? Source inventory's RemoveItem() is called
   ? Target inventory's AddItem() or AddItemAtPosition() is called
   ? OnItemAdded/OnItemRemoved events fire for UI update


GRID PLACEMENT ALGORITHM:
--------------------------

The system uses a first-fit algorithm for automatic placement:
1. Iterates through grid cells from top-left
2. Finds first position where item fits
3. Checks bounds and collision with other items
4. Places item and marks all occupied cells

For manual placement:
1. Checks if target position is valid
2. Validates no collision with other items
3. Places item or rejects placement

Example placement:
  Item: 2x2
  Grid: 10x5
  
  First-fit finds: (0,0), (2,0), (4,0), etc.
  Manual placement: Inventory->MoveItem(Item, 5, 3)


NETWORKING CONSIDERATIONS:
---------------------------

For multiplayer games:
1. All item operations should be done on the owning client
2. Use RPCs to synchronize inventory state to server
3. Server validates all item transfers for security
4. Container access can be restricted to nearby players

Example RPC:
  UFUNCTION(Server, Reliable)
  void Server_MoveItem(UInventoryItem* Item, int32 X, int32 Y);


PERFORMANCE TIPS:
-----------------

1. Limit grid size: Most games use 10-20 width, 5-10 height
2. Cache grid references instead of repeated lookups
3. Batch UI updates when moving multiple items
4. Use ObjectPtr for component ownership
5. Consider using object pooling for frequently created items


EXTENDING THE SYSTEM:
---------------------

To create custom item types:
1. Create new class derived from UInventoryItem
2. Add custom properties and methods
3. Override OnItemUsed() or other events as needed
4. Create Blueprint children for configuration

Example custom item:
  class UWeapon : public UInventoryItem
  {
    UPROPERTY(EditAnywhere) float Damage;
    UPROPERTY(EditAnywhere) float FireRate;
    UFUNCTION() void Fire();
  };


COMMON ISSUES AND SOLUTIONS:
----------------------------

Issue: Item won't fit in inventory
  Solution: Check GridWidth/GridHeight of item vs inventory size

Issue: Item disappears after transfer
  Solution: Ensure RemoveItem() is called before AddItem() in transfers

Issue: Container won't open
  Solution: Verify InteractAction is bound and container is within radius

Issue: Multiple items at same position
  Solution: Grid collision detection is working; verify via debugging

Issue: Memory leaks with items
  Solution: Items are owned by inventory component; cleaned up automatically


FILE STRUCTURE:
---------------

Source/OneLastPush/
??? Inventory/
?   ??? InventoryItem.h/cpp           - Base item class
?   ??? InventoryGrid.h/cpp           - Grid data structure
?   ??? InventoryItemExample.h/cpp    - Example item class
?   ??? InventoryUIWidget.h/cpp       - UI widget base
??? Components/
    ??? InventoryComponent.h/cpp      - Character inventory
    ??? ContainerComponent.h/cpp      - Container component

*/

// This file is documentation only. Include real header files where needed.
