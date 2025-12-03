// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OneLastPushGameMode.generated.h"

class UTwinStickUI;

/**
 *  Simple Game Mode for a Twin Stick Shooter game.
 *  Manages the score and UI
 */
UCLASS(abstract)
class AOneLastPushGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Cleanup */
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
};

