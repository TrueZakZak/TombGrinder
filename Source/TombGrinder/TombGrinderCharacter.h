// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "TombGrinderCharacter.generated.h"

UCLASS()
class TOMBGRINDER_API ATombGrinderCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATombGrinderCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent *FPSCameraComponent;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveStraight(float Value);

	UFUNCTION()
	void MoveStrafe(float Value);

	UFUNCTION()
	void StartJump();
	
	UFUNCTION()
	void StopJump();
};
