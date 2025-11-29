// Fill out your copyright notice in the Description page of Project Settings.

#include "ContainerComponent.h"
#include "InventoryComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UContainerComponent::UContainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UContainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// Try to find an existing inventory component on the same actor
	Inventory = GetOwner()->FindComponentByClass<UInventoryComponent>();
	if (!Inventory)
	{
		// create a transient InventoryComponent if none exists
		Inventory = NewObject<UInventoryComponent>(GetOwner(), UInventoryComponent::StaticClass(), NAME_None, RF_Transactional);
		if (Inventory)
		{
			Inventory->RegisterComponent();
			Inventory->InitializeGrid(InitialWidth, InitialHeight);
		}
	}
}


// Called every frame
void UContainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UContainerComponent::InitializeContainer(int32 Width, int32 Height)
{
	if (!Inventory)
	{
		Inventory = GetOwner()->FindComponentByClass<UInventoryComponent>();
		if (!Inventory)
		{
			Inventory = NewObject<UInventoryComponent>(GetOwner(), UInventoryComponent::StaticClass(), NAME_None, RF_Transactional);
			Inventory->RegisterComponent();
		}
	}
	if (Inventory && GetOwner()->HasAuthority())
	{
		Inventory->InitializeGrid(Width, Height);
	}
}

bool UContainerComponent::TransferItemTo(UInventoryComponent* Destination, int32 ItemIndex, int32 Count)
{
	if (!Inventory || !Destination)
		return false;

	if (!GetOwner()->HasAuthority())
	{
		ServerTransferItemTo(Destination, ItemIndex, Count);
		return false;
	}

	return Inventory->TransferTo(Destination, ItemIndex, Count);
}

void UContainerComponent::ServerTransferItemTo_Implementation(UInventoryComponent* Destination, int32 ItemIndex, int32 Count)
{
	if (Inventory && Destination)
	{
		Inventory->TransferTo(Destination, ItemIndex, Count);
	}
}

bool UContainerComponent::ReceiveItemFrom(UInventoryComponent* SourceInventory, int32 ItemIndex, int32 Count)
{
	if (!Inventory || !SourceInventory)
		return false;
	if (!GetOwner()->HasAuthority())
	{
		ServerReceiveItemFrom(SourceInventory, ItemIndex, Count);
		return false;
	}
	return SourceInventory->TransferTo(Inventory, ItemIndex, Count);
}

void UContainerComponent::ServerReceiveItemFrom_Implementation(UInventoryComponent* SourceInventory, int32 ItemIndex, int32 Count)
{
	if (Inventory && SourceInventory)
	{
		SourceInventory->TransferTo(Inventory, ItemIndex, Count);
	}
}

