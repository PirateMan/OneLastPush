// Fill out your copyright notice in the Description page of Project Settings.

#include "ContainerComponent.h"
#include "InventoryComponent.h"
#include "../Inventory/InventoryItem.h"
#include "../OneLastPushCharacter.h"

UContainerComponent::UContainerComponent()
	: GridWidth(8)
	, GridHeight(4)
	, bIsOpen(false)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UContainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// Create container inventory if not already created
	if (!Inventory)
	{
		Inventory = NewObject<UInventoryComponent>(this);
		if (Inventory)
		{
			Inventory->GridWidth = GridWidth;
			Inventory->GridHeight = GridHeight;
		}
	}
}

void UContainerComponent::ToggleContainer()
{
	if (bIsOpen)
	{
		CloseContainer();
	}
	else if (InteractingCharacter.IsValid())
	{
		OpenContainer(InteractingCharacter.Get());
	}
}

void UContainerComponent::OpenContainer(AOneLastPushCharacter* Interactor)
{
	// Ensure inventory is initialized
	if (!Inventory)
	{
		Inventory = NewObject<UInventoryComponent>(this);
		if (Inventory)
		{
			Inventory->GridWidth = GridWidth;
			Inventory->GridHeight = GridHeight;
		}
	}

	if (!Inventory || bIsOpen)
	{
		return;
	}

	InteractingCharacter = Interactor;
	bIsOpen = true;

	// Delegates removed - Blueprint can bind to container state changes
	// through IsOpen() getter if needed
}

void UContainerComponent::CloseContainer()
{
	if (!bIsOpen)
	{
		return;
	}

	bIsOpen = false;
	// Delegates removed - Blueprint can bind to container state changes
	// through IsOpen() getter if needed
}

bool UContainerComponent::AddItem(UInventoryItem* Item)
{
	if (!Inventory)
	{
		Inventory = NewObject<UInventoryComponent>(this);
		if (Inventory)
		{
			Inventory->GridWidth = GridWidth;
			Inventory->GridHeight = GridHeight;
		}
	}

	if (!Inventory)
	{
		return false;
	}

	return Inventory->AddItem(Item);
}

void UContainerComponent::GetAllItems(TArray<UInventoryItem*>& OutItems) const
{
	if (Inventory)
	{
		Inventory->GetAllItems(OutItems);
	}
}

