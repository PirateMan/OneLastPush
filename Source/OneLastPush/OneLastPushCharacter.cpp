// Copyright Epic Games, Inc. All Rights Reserved.

#include "OneLastPushCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Components/InventoryComponent.h"
#include "Components/ContainerComponent.h"
#include "Inventory/InventoryUIWidget.h"
#include "Engine/CollisionProfile.h"
#include "Engine/OverlapResult.h"
#include "TwinStickGameMode.h"
#include "TwinStickAoEAttack.h"
#include "Kismet/KismetMathLibrary.h"
#include "TwinStickProjectile.h"
#include "Engine/World.h"
#include "TimerManager.h"

AOneLastPushCharacter::AOneLastPushCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// create the spring arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->SetRelativeRotation(FRotator(-50.0f, 0.0f, 0.0f));

	SpringArm->TargetArmLength = 2200.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 0.5f;

	// create the camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Camera->SetFieldOfView(75.0f);

	// create the inventory component
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));

	// configure the character movement
	GetCharacterMovement()->GravityScale = 1.5f;
	GetCharacterMovement()->MaxAcceleration = 1000.0f;
	GetCharacterMovement()->BrakingFrictionFactor = 1.0f;
	GetCharacterMovement()->bCanWalkOffLedges = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
}

void AOneLastPushCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Create and setup the inventory widget
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (InventoryWidgetClass)
		{
			InventoryWidget = CreateWidget<UInventoryUIWidget>(PC, InventoryWidgetClass);
			if (InventoryWidget)
			{
				InventoryWidget->AddToViewport(100);
				InventoryWidget->SetInventoryVisible(false);
				InventoryWidget->InitializeInventory(InventoryComponent, nullptr);
			}
		}
	}
}

void AOneLastPushCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AOneLastPushCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// set the player controller reference
	PlayerController = Cast<APlayerController>(GetController());
}

void AOneLastPushCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// get the current rotation
	const FRotator OldRotation = GetActorRotation();

	// are we aiming with the mouse?
	if (bUsingMouse)
	{
		if (PlayerController)
		{
			// get the cursor world location
			FHitResult OutHit;
			PlayerController->GetHitResultUnderCursorByChannel(MouseAimTraceChannel, true, OutHit);

			// find the aim rotation 
			const FRotator AimRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), OutHit.Location);

			// save the aim angle
			AimAngle = AimRot.Yaw;

			// update the yaw, reuse the pitch and roll
			SetActorRotation(FRotator(OldRotation.Pitch, AimAngle, OldRotation.Roll));

		}

	}
	else {

		// use quaternion interpolation to blend between our current rotation
		// and the desired aim rotation using the shortest path
		const FRotator TargetRot = FRotator(OldRotation.Pitch, AimAngle, OldRotation.Roll);

		SetActorRotation(TargetRot);
	}
}

void AOneLastPushCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up the enhanced input action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AOneLastPushCharacter::Move);
		EnhancedInputComponent->BindAction(StickAimAction, ETriggerEvent::Triggered, this, &AOneLastPushCharacter::StickAim);
		EnhancedInputComponent->BindAction(MouseAimAction, ETriggerEvent::Triggered, this, &AOneLastPushCharacter::MouseAim);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AOneLastPushCharacter::Sprint);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &AOneLastPushCharacter::Shoot);
		
		if (OpenInventoryAction)
		{
			EnhancedInputComponent->BindAction(OpenInventoryAction, ETriggerEvent::Triggered, this, &AOneLastPushCharacter::ToggleInventory);
		}

		if (InteractAction)
		{
			EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AOneLastPushCharacter::Interact);
		}
	}

}

void AOneLastPushCharacter::Move(const FInputActionValue& Value)
{
	// save the input vector
	FVector2D InputVector = Value.Get<FVector2D>();

	// route the input
	DoMove(InputVector.X, InputVector.Y);
}

void AOneLastPushCharacter::StickAim(const FInputActionValue& Value)
{
	// get the input vector
	FVector2D InputVector = Value.Get<FVector2D>();

	// route the input
	DoAim(InputVector.X, InputVector.Y);
}

void AOneLastPushCharacter::MouseAim(const FInputActionValue& Value)
{
	// raise the mouse controls flag
	bUsingMouse = true;

	// show the mouse cursor
	if (PlayerController)
	{
		PlayerController->SetShowMouseCursor(true);
	}
}

void AOneLastPushCharacter::Sprint(const FInputActionValue& Value)
{
	// route the input
	DoSprint();
}

void AOneLastPushCharacter::Shoot(const FInputActionValue& Value)
{
	// route the input
	DoShoot();
}

void AOneLastPushCharacter::ToggleInventory(const FInputActionValue& Value)
{
	// Toggle inventory visibility
	if (InventoryWidget)
	{
		// Get current visibility
		ESlateVisibility CurrentVis = InventoryWidget->GetVisibility();
		
		// Toggle between visible and hidden
		if (CurrentVis == ESlateVisibility::Visible)
		{
			InventoryWidget->SetInventoryVisible(false);
		}
		else
		{
			InventoryWidget->SetInventoryVisible(true);
		}
	}
}

void AOneLastPushCharacter::Interact(const FInputActionValue& Value)
{
	// Find nearby containers and interact with them
	if (!GetWorld())
	{
		return;
	}

	// Sphere trace to find containers
	const FVector TraceStart = GetActorLocation();
	const FVector TraceEnd = TraceStart;
	const float InteractionRadius = 200.0f;

	FCollisionShape SphereShape;
	SphereShape.SetSphere(InteractionRadius);

	FCollisionObjectQueryParams QueryParams;
	QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);

	TArray<FOverlapResult> OutOverlaps;

	if (GetWorld()->OverlapMultiByObjectType(OutOverlaps, TraceStart, FQuat::Identity, QueryParams, SphereShape, TraceParams))
	{
		// Find the closest container
		float ClosestDistance = InteractionRadius;
		UContainerComponent* ClosestContainer = nullptr;

		for (const FOverlapResult& Overlap : OutOverlaps)
		{
			if (AActor* HitActor = Overlap.GetActor())
			{
				if (UContainerComponent* Container = HitActor->FindComponentByClass<UContainerComponent>())
				{
					float Distance = FVector::Dist(GetActorLocation(), HitActor->GetActorLocation());
					if (Distance < ClosestDistance)
					{
						ClosestDistance = Distance;
						ClosestContainer = Container;
					}
				}
			}
		}

		// Interact with the closest container
		if (ClosestContainer)
		{
			if (ClosestContainer->IsOpen())
			{
				// Close container
				ClosestContainer->CloseContainer();
				
				// Close entire inventory UI when closing container
				if (InventoryWidget)
				{
					InventoryWidget->SetInventoryVisible(false);
					InventoryWidget->InitializeInventory(InventoryComponent, nullptr);
				}
			}
			else
			{
				// Open container
				ClosestContainer->OpenContainer(this);
				
				// Update inventory widget to show container
				if (InventoryWidget)
				{
					InventoryWidget->SetInventoryVisible(true);
					InventoryWidget->InitializeInventory(InventoryComponent, ClosestContainer);
				}
			}
		}
	}
}

void AOneLastPushCharacter::DoMove(float AxisX, float AxisY)
{
	// save the input
	LastMoveInput.X = AxisX;
	LastMoveInput.Y = AxisY;

	// calculate the forward component of the input
	FRotator FlatRot = GetControlRotation();
	FlatRot.Pitch = 0.0f;

	// apply the forward input
	AddMovementInput(FlatRot.RotateVector(FVector::ForwardVector), AxisX);

	// apply the right input
	AddMovementInput(FlatRot.RotateVector(FVector::RightVector), AxisY);
}

void AOneLastPushCharacter::DoAim(float AxisX, float AxisY)
{
	// calculate the aim angle from the inputs
	AimAngle = FMath::RadiansToDegrees(FMath::Atan2(AxisY, -AxisX));

	// lower the mouse controls flag
	bUsingMouse = false;

	// hide the mouse cursor
	if (PlayerController)
	{
		PlayerController->SetShowMouseCursor(false);
	}

	// are we on autofire cooldown?
	if (!bAutoFireActive)
	{
		// set ourselves on cooldown
		bAutoFireActive = true;

		// fire a projectile
		DoShoot();

		// schedule autofire cooldown reset
		GetWorld()->GetTimerManager().SetTimer(AutoFireTimer, this, &AOneLastPushCharacter::ResetAutoFire, AutoFireDelay, false);
	}
}

void AOneLastPushCharacter::DoShoot()
{

}

void AOneLastPushCharacter::DoSprint()
{

}

void AOneLastPushCharacter::ResetAutoFire()
{
	// reset the autofire flag
	bAutoFireActive = false;
}