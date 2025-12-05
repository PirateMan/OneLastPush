# Inventory System - Data Table & Container Setup Guide

## What Was Added

### 1. **Data Table Support**
- **FInventoryItemData** struct for defining items in data tables
- Item properties: Name, Description, Icon, Grid Size, Stack Size, Type, Rarity, Value, Weight
- Helper methods to create items from data tables

### 2. **Container Inventory System**
- Containers now have full inventory support (separate from player)
- Can populate containers with items from data tables
- Opens side-by-side with player inventory

---

## Setting Up in Unreal Editor

### **Step 1: Create Item Data Table**

1. **Content Browser** ? Right-click ? **Miscellaneous** ? **Data Table**
2. Choose **InventoryItemData** as the row structure
3. Name it: `DT_Items`

### **Step 2: Add Items to Data Table**

Open `DT_Items` and add rows:

#### Example Items:

| Row Name | Item ID | Item Name | Description | Grid Width | Grid Height | Max Stack | Item Type | Rarity | Icon |
|----------|---------|-----------|-------------|------------|-------------|-----------|-----------|---------|------|
| `Sword_Iron` | Sword_Iron | Iron Sword | A basic iron sword | 1 | 3 | 1 | Weapon | Common | (your icon) |
| `Potion_Health` | Potion_Health | Health Potion | Restores 50 HP | 1 | 1 | 10 | Consumable | Common | (your icon) |
| `Gold_Coin` | Gold_Coin | Gold Coin | Currency | 1 | 1 | 999 | Misc | Common | (your icon) |
| `Armor_Plate` | Armor_Plate | Plate Armor | Heavy armor | 2 | 3 | 1 | Armor | Rare | (your icon) |

### **Step 3: Add Items to Player Inventory (Testing)**

In your **Character Blueprint** (BeginPlay event):

```
1. Get Inventory Component
2. Call "Add Item From Data Table"
   - Data Table: DT_Items
   - Row Name: "Potion_Health"
   - Quantity: 5
```

### **Step 4: Create a Container Actor**

1. **Content Browser** ? Blueprint Class ? Actor
2. Name: `BP_Chest` (or any container name)
3. Open the Blueprint

**Add Components:**
- **Static Mesh** (for visual representation)
- **Container Component** (your custom component)

**Configure Container Component:**
- Grid Width: `8` (or your desired size)
- Grid Height: `4`

**Add Items to Container (BeginPlay):**
```
1. Get Container Component
2. Call "Add Item From Data Table"
   - Data Table: DT_Items
   - Row Name: "Sword_Iron"
   - Quantity: 1
3. (Repeat for more items)
```

### **Step 5: Update WBP_Inventory Widget**

Your `WBP_Inventory` needs a second grid for containers:

**Add to Designer:**
1. **Horizontal Box** (to hold both grids side-by-side)
   - Inside add **Vertical Box** (Player Inventory)
     - Text: "Player Inventory"
     - **Uniform Grid Panel**: `InventoryGrid` ? (already exists)
   
   - Inside add **Vertical Box** (Container Inventory)
     - Text: "Container"
     - **Uniform Grid Panel**: `ContainerGrid` ? (make this a variable)

**Layout Example:**
```
[Horizontal Box]
  ?? [Vertical Box - Player]
  ?  ?? Text: "Player Inventory"
  ?  ?? InventoryGrid (10x5)
  ?
  ?? [Vertical Box - Container]
     ?? Text: "Container"  
     ?? ContainerGrid (8x4)
```

---

## Usage in C++

### **Add Items to Player Inventory:**

```cpp
// In BeginPlay or anywhere
if (UInventoryComponent* Inventory = GetInventory())
{
    // Assuming you have a reference to your data table
    Inventory->AddItemFromDataTable(ItemDataTable, FName("Potion_Health"), 5);
    Inventory->AddItemFromDataTable(ItemDataTable, FName("Sword_Iron"), 1);
}
```

### **Populate Container with Items:**

```cpp
// In container actor's BeginPlay
if (UContainerComponent* Container = FindComponentByClass<UContainerComponent>())
{
    Container->AddItemFromDataTable(ItemDataTable, FName("Gold_Coin"), 100);
    Container->AddItemFromDataTable(ItemDataTable, FName("Armor_Plate"), 1);
}
```

### **Interact with Container:**

```cpp
// Already implemented in AOneLastPushCharacter::Interact()
// Press 'E' near container to open/close
```

---

## How It Works

### **Player Inventory:**
1. Press **Tab** ? Opens inventory UI
2. Shows player's 10x5 grid with items
3. Items populate from data table

### **Container Interaction:**
1. Walk near a container (within 200 units)
2. Press **E** ? Opens container + inventory UI
3. **Left side**: Player inventory (10x5)
4. **Right side**: Container inventory (8x4, or custom size)
5. Press **E** again ? Closes container

### **Adding Items:**
- Items defined in **Data Table** (design-time)
- Spawned via `AddItemFromDataTable()` (C++ or Blueprint)
- Automatically positioned in first available slot
- Supports stacking based on MaxStackSize

---

## Next Steps (Optional Enhancements)

1. **Drag & Drop Between Inventories**
   - Implement `NativeOnDragDetected()` in `UInventorySlotWidget`
   - Transfer items between player/container

2. **Item Tooltips**
   - Show item details on hover
   - Display stats, description, value

3. **Multi-Cell Item Visualization**
   - Items that occupy 2x3 or larger spaces
   - Visual representation spanning multiple slots

4. **Save/Load System**
   - Serialize inventory contents
   - Restore on game load

5. **Loot Tables**
   - Randomized container contents
   - Probability-based item spawning

---

## Troubleshooting

**Q: Container grid doesn't appear?**
- Make sure you added `ContainerGrid` to WBP_Inventory and made it a variable
- Check that it's named exactly "ContainerGrid"

**Q: Items don't show in data table?**
- Verify the DataTable's row structure is `FInventoryItemData`
- Make sure Row Names match what you're using in code

**Q: Can't interact with container?**
- Check container has `ContainerComponent`
- Verify container actor's collision is set to `WorldDynamic`
- Make sure you're within 200 units

**Q: Inventory doesn't open?**
- Verify `InventoryWidgetClass` is set to `WBP_Inventory` in Character BP
- Check input action mappings for Tab and E keys

---

## Summary

? **Data Table system** for defining items  
? **Container inventory** with full grid support  
? **Side-by-side UI** for player + container  
? **Interaction system** to open/close containers  
? **C++ implementation** with minimal Blueprints  

You can now:
- Define items in a data table
- Add items to player/containers from data
- Open containers to view their contents
- See both inventories at once

**Ready for drag-drop implementation next!**
