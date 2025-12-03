// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/InventoryItem.h"
#include "InventoryItemExample.generated.h"

/**
 * Example inventory item showing how to create custom items
 */
UCLASS()
class ONELASTPUSH_API UInventoryItemExample : public UInventoryItem
{
	GENERATED_BODY()

public:
	UInventoryItemExample();

	/** Example property for demonstration */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Example")
	float Durability;

	/** Example method for custom logic */
	UFUNCTION(BlueprintCallable, Category = "Item|Example")
	void OnItemUsed();
};
