// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "TombGrinderGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOMBGRINDER_API ATombGrinderGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
};
