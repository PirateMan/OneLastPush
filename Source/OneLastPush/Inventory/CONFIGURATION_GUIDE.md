# Inventory System Configuration Guide

## Quick Configuration Checklist

### Step 1: Input Actions Setup (REQUIRED)

In your EnhancedInput IMC (Input Mapping Context):

```
IA_OpenInventory
  ?? Mapped to: Tab (or I, B, etc.)
  ?? Trigger Event: Triggered
  
IA_Interact
  ?? Mapped to: E
  ?? Trigger Event: Triggered
```

### Step 2: Character Configuration

1. Open your character Blueprint (e.g., BP_MyCharacter)
2. Select the character in viewport or outliner
3. In Details panel, find "OneLastPush Character" category
4. Assign:
   - **OpenInventoryAction**: Select IA_OpenInventory
   - **InteractAction**: Select IA_Interact

Optional: Adjust inventory grid size:
- **GridWidth**: Default 10 (how many slots wide)
- **GridHeight**: Default 5 (how many slots tall)

### Step 3: Create Inventory Items

**Option A: Simple Blueprint Item**

1. Content Browser ? Right-click ? Blueprint Class
2. Search for "UInventoryItem"
3. Create Blueprint ? Name it "BP_Item_Sword" (or similar)
4. Open blueprint and set defaults:
   ```
   Grid Width: 2
   Grid Height: 1
   Max Stack Size: 1 (not stackable)
   Item Name: "Sword"
   Item Description: "A sharp blade"
   Icon: [Your texture]
   ```
5. Compile & Save

**Option B: Custom C++ Item Class**

1. Create new C++ class inheriting from UInventoryItem
2. Add your properties (damage, durability, etc.)
3. Override functions as needed
4. Create Blueprint child and configure

### Step 4: Create Containers

1. Place an Actor in your level (e.g., Cube)
2. In Details, click "+ Add Component"
3. Search for "UContainerComponent"
4. Configure the component:
   ```
   Grid Width: 8 (container inventory width)
   Grid Height: 4 (container inventory height)
   ```
5. Optional: Add a static mesh for visuals

### Step 5: Create UI Widget (Blueprint)

1. Create Widget Blueprint (UMG)
2. Add Canvas Panel as root
3. Add:
   - Text for title ("Inventory")
   - Uniform Grid Panel for slots
   - Buttons for interactions
4. In code (Event Graph):
   ```
   Event Construct:
     Get Player Character
     Cast to OneLastPushCharacter
     Get Inventory
     Call InitializeInventory on UI widget
   ```

### Step 6: Implement Drag-Drop (Blueprint UI)

In your inventory UI widget:

```
On Drag Item:
  1. Get source inventory
  2. Get target position (X, Y)
  3. Call MoveItem with new position
  4. Or RemoveItem + AddItem for transfer

On Drop Item:
  1. Calculate grid position from mouse
  2. Call MoveItem or transfer functions
  3. Refresh display
```

## Default Grid Sizes

**Player Inventory**
- Width: 10 slots
- Height: 5 slots
- Capacity: 50 cells

**Container (Chest)**
- Width: 8 slots
- Height: 4 slots
- Capacity: 32 cells

You can modify these per-instance in Blueprint details.

## Item Size Examples

**1x1 Items** (1 cell)
- Potions
- Coins
- Small weapons
- Scrolls

**2x1 Items** (2 cells)
- Swords
- Daggers
- Small shields

**2x2 Items** (4 cells)
- Heavy weapons
- Large shields
- Armor pieces

**3x3 Items** (9 cells)
- 2-handed weapons
- Large shields

## Testing the System

### In-Editor Test

1. **Place a container** in your level with ContainerComponent
2. **Play** the game (PIE)
3. **Add item** via command:
   ```
   Ctrl+Shift+`  (Open console)
   GetPlayerCharacter(0 0).GetInventory().AddItem(YourItemInstance)
   ```
4. **Move closer** to container (within 200 units)
5. **Press E** (or your interact key) to open container
6. **Press I** (or your inventory key) to view inventory

### Blueprint Test

1. Create **Level Blueprint**
2. On BeginPlay:
   - Spawn your item Blueprint
   - Get player inventory
   - Call AddItem
3. Play and verify item appears

## Troubleshooting Configuration

### Items Won't Add
- ? Check GridWidth/GridHeight > 0 in inventory
- ? Verify item's GridWidth/GridHeight fit in available space
- ? Check inventory is initialized (BeginPlay called)
- ? Ensure no overlapping items

### Container Won't Open
- ? Check Interact key is mapped and bound
- ? Verify you're within 200 units of container
- ? Check container has ContainerComponent
- ? Ensure OpenContainer receives valid character

### UI Not Updating
- ? Verify InitializeInventory was called
- ? Check OnItemChanged delegate is connected
- ? Ensure RefreshDisplay updates UI visuals
- ? Verify player inventory is valid

### Items Disappear After Transfer
- ? Call RemoveItem() before adding to new inventory
- ? Don't destroy items, just move them
- ? Check both inventories exist and are valid
- ? Verify OwningInventory pointer updates

## Common Configurations

### Small Inventory (Minimalist)
```
GridWidth: 5
GridHeight: 3
Capacity: 15 cells
Suitable for: Limited inventory games
```

### Standard Inventory (RPG)
```
GridWidth: 10
GridHeight: 5
Capacity: 50 cells
Suitable for: Most RPGs
```

### Large Inventory (Hoarding)
```
GridWidth: 15
GridHeight: 10
Capacity: 150 cells
Suitable for: Open-world games
```

### Tiny Container (Limited Storage)
```
GridWidth: 4
GridHeight: 3
Capacity: 12 cells
Suitable for: Quick loot containers
```

### Large Storage (Vault)
```
GridWidth: 12
GridHeight: 12
Capacity: 144 cells
Suitable for: Bank/vault systems
```

## Input Action Binding Details

### IA_OpenInventory
- **Trigger**: Triggered (fire every frame while held)
- **Calls**: AOneLastPushCharacter::ToggleInventory()
- **Usage**: Blueprint can override to show/hide UI
- **Default**: Not bound in C++, set in Blueprint details

### IA_Interact
- **Trigger**: Triggered (fire every frame while held)
- **Calls**: AOneLastPushCharacter::Interact()
- **Usage**: Opens nearest container within 200 units
- **Feedback**: Call ToggleContainer() on found container

## Grid Coordinates System

```
(0,0) ??? (1,0) ??? (2,0) ??? ... ??? (GridWidth-1, 0)
  ?         ?         ?                    ?
(0,1) ??? (1,1) ??? (2,1) ??? ... ??? (GridWidth-1, 1)
  ?         ?         ?                    ?
  ...       ...       ...       ...       ...
  ?         ?         ?                    ?
(0,H) ??? (1,H) ??? (2,H) ??? ... ??? (GridWidth-1, H)
```

- **X-axis**: Increases left to right
- **Y-axis**: Increases top to bottom
- **Origin**: Top-left corner (0, 0)

## Performance Settings

### For Low-End Systems
```
GridWidth: 6
GridHeight: 4
Container Width: 4
Container Height: 3
Max items cached: 50
```

### For High-End Systems
```
GridWidth: 20
GridHeight: 15
Container Width: 15
Container Height: 12
Max items cached: 500
```

## Advanced Configuration

### Custom Interaction Radius

In OneLastPushCharacter::Interact():
```cpp
const float InteractionRadius = 200.0f;  // Change this value
```

### Custom Grid Algorithm

Override in InventoryGrid:
```cpp
- FindFreeSpace() - Change from first-fit to best-fit
- IsAreaFree() - Add custom collision rules
- PlaceItem() - Add custom placement logic
```

### Custom Delegates

Modify in InventoryComponent:
```cpp
FOnInventoryItemChanged OnItemChanged;  // Add parameters if needed
```

## Common Issues & Solutions

| Issue | Solution |
|-------|----------|
| Items stack when shouldn't | Set MaxStackSize = 1 |
| Inventory too small | Increase GridWidth/Height |
| Container not found | Reduce InteractionRadius or get closer |
| UI doesn't update | Check InitializeInventory() was called |
| Items won't move | Verify target position is free |
| Memory leaks | Items auto-owned by component |

---

**Last Updated**: For UE 5.7  
**Configuration Time**: ~10 minutes for basic setup  
**Full Implementation**: ~1 hour with UI  
