// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InventoryItemData.generated.h"

/**
 * Item rarity levels
 */
UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	Common		UMETA(DisplayName = "Common"),
	Uncommon	UMETA(DisplayName = "Uncommon"),
	Rare		UMETA(DisplayName = "Rare"),
	Epic		UMETA(DisplayName = "Epic"),
	Legendary	UMETA(DisplayName = "Legendary")
};

/**
 * Item types/categories
 */
UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon		UMETA(DisplayName = "Weapon"),
	Armor		UMETA(DisplayName = "Armor"),
	Consumable	UMETA(DisplayName = "Consumable"),
	Quest		UMETA(DisplayName = "Quest Item"),
	Resource	UMETA(DisplayName = "Resource"),
	Misc		UMETA(DisplayName = "Miscellaneous")
};

/**
 * Data table row structure for inventory items
 * Create a DataTable asset based on this in the editor
 */
USTRUCT(BlueprintType)
struct FInventoryItemData : public FTableRowBase
{
	GENERATED_BODY()

	/** Unique item ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID;

	/** Display name of the item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemName;

	/** Description shown in tooltips */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemDescription;

	/** Item icon texture */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	TObjectPtr<UTexture2D> Icon;

	/** Width in grid cells */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid", meta = (ClampMin = "1", ClampMax = "10"))
	int32 GridWidth = 1;

	/** Height in grid cells */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid", meta = (ClampMin = "1", ClampMax = "10"))
	int32 GridHeight = 1;

	/** Maximum stack size (1 = not stackable) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stacking", meta = (ClampMin = "1"))
	int32 MaxStackSize = 1;

	/** Item type/category */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType = EItemType::Misc;

	/** Item rarity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemRarity Rarity = EItemRarity::Common;

	/** Item value in gold/currency */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Value = 0;

	/** Item weight */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float Weight = 0.0f;

	/** Can this item be dropped */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bCanDrop = true;

	/** Can this item be sold */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bCanSell = true;

	/** Is this a quest item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bIsQuestItem = false;

	FInventoryItemData()
		: ItemID(NAME_None)
		, ItemName(FText::GetEmpty())
		, ItemDescription(FText::GetEmpty())
		, Icon(nullptr)
		, GridWidth(1)
		, GridHeight(1)
		, MaxStackSize(1)
		, ItemType(EItemType::Misc)
		, Rarity(EItemRarity::Common)
		, Value(0)
		, Weight(0.0f)
		, bCanDrop(true)
		, bCanSell(true)
		, bIsQuestItem(false)
	{
	}
};
