// Fill out your copyright notice in the Description page of Project Settings.

#include "TombGrinder.h"
#include "TombGrinderGameModeBase.h"

void ATombGrinderGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("TombGrinder game mode"));
	}
}
