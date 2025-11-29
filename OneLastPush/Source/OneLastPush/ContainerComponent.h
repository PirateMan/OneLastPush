// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContainerComponent.generated.h"

class UInventoryComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONELASTPUSH_API UContainerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UContainerComponent();

    // Initialize the internal inventory dimensions (optional)
    UFUNCTION(BlueprintCallable, Category = "Container")
    void InitializeContainer(int32 Width, int32 Height);

    // Transfer an item from this container to another inventory
    UFUNCTION(BlueprintCallable, Category = "Container")
    bool TransferItemTo(UInventoryComponent* Destination, int32 ItemIndex, int32 Count = 0);

    // Transfer an item from another inventory into this container
    UFUNCTION(BlueprintCallable, Category = "Container")
    bool ReceiveItemFrom(UInventoryComponent* SourceInventory, int32 ItemIndex, int32 Count = 0);

    // Expose internal inventory for UI
    UFUNCTION(BlueprintPure, Category = "Container")
    UInventoryComponent* GetInventory() const { return Inventory; }

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

private:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Embedded inventory component instance (created at runtime if not present)
    UPROPERTY(VisibleAnywhere, Category = "Container")
    UInventoryComponent* Inventory = nullptr;

    // Desired initial size if Inventory is auto-created
    UPROPERTY(EditAnywhere, Category = "Container")
    int32 InitialWidth = 6;

    UPROPERTY(EditAnywhere, Category = "Container")
    int32 InitialHeight = 4;

    // Server RPCs for client requests
    UFUNCTION(Server, Reliable)
    void ServerTransferItemTo(UInventoryComponent* Destination, int32 ItemIndex, int32 Count);

    UFUNCTION(Server, Reliable)
    void ServerReceiveItemFrom(UInventoryComponent* SourceInventory, int32 ItemIndex, int32 Count);
};
