// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "OneLastPushCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInventoryComponent;
struct FInputActionValue;
class APlayerController;
class UInputAction;
class ATwinStickAoEAttack;
class ATwinStickProjectile;

/**
 *  A controllable top-down perspective character
 */
UCLASS(abstract)
class AOneLastPushCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom spring arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** Player Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	/** Player inventory component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UInventoryComponent* InventoryComponent;

protected:

	/** Movement input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	/** Gamepad aim input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* StickAimAction;

	/** Mouse aim input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MouseAimAction;

	/** Sprint input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SprintAction;

	/** Shooting input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ShootAction;

	/** Inventory input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* OpenInventoryAction;

	/** Interact input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* InteractAction;

	/** Trace channel to use for mouse aim */
	UPROPERTY(EditAnywhere, Category = "Input")
	TEnumAsByte<ETraceTypeQuery> MouseAimTraceChannel;

	/** Speed to blend between our current rotation and the target aim rotation when stick aiming */
	UPROPERTY(EditAnywhere, Category = "Aim", meta = (ClampMin = 0, ClampMax = 100, Units = "s"))
	float AimRotationInterpSpeed = 10.0f;

	/** Aim Yaw Angle in degrees */
	float AimAngle = 0.0f;

	/** Pointer to the player controller assigned to this character */
	TObjectPtr<APlayerController> PlayerController;

	/** If true, the player is using mouse aim */
	bool bUsingMouse = false;

	/** Last held move input */
	FVector2D LastMoveInput;

	/** If true, the player is auto firing while stick aiming */
	bool bAutoFireActive = false;

	/** Time to wait between autofire attempts */
	UPROPERTY(EditAnywhere, Category = "Aim", meta = (ClampMin = 0, ClampMax = 5, Units = "s"))
	float AutoFireDelay = 0.2f;

	/** Timer to handle stick autofire */
	FTimerHandle AutoFireTimer;

public:

	/** Constructor */
	AOneLastPushCharacter();

protected:

	/** Gameplay Initialization */
	virtual void BeginPlay() override;

	/** Gameplay cleanup */
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	/** Possessed by controller initialization */
	virtual void NotifyControllerChanged() override;

public:

	/** Updates the character's rotation to face the aim direction */
	virtual void Tick(float DeltaTime) override;

	/** Adds input bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Handles movement inputs */
	void Move(const FInputActionValue& Value);

	/** Handles joypad aim */
	void StickAim(const FInputActionValue& Value);

	/** Handles mouse aim */
	void MouseAim(const FInputActionValue& Value);

	/** Performs a dash */
	void Sprint(const FInputActionValue& Value);

	/** Shoots projectiles */
	void Shoot(const FInputActionValue& Value);

	/** Open/close inventory */
	void ToggleInventory(const FInputActionValue& Value);

	/** Interact with nearby containers */
	void Interact(const FInputActionValue& Value);

public:

	/** Handles move inputs from both input actions and touch interface */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void DoMove(float AxisX, float AxisY);

	/** Handles aim inputs from both input actions and touch interface */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void DoAim(float AxisX, float AxisY);

	/** Handles sprint inputs from both input actions and touch interface */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void DoSprint();

	/** Handles shoot inputs from both input actions and touch interface */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void DoShoot();

	/** Get player inventory */
	UFUNCTION(BlueprintPure, Category = "Inventory")
	UInventoryComponent* GetInventory() const { return InventoryComponent; }

protected:

	/** Resets stick the aim autofire flag after the autofire timer has expired */
	void ResetAutoFire();
};
