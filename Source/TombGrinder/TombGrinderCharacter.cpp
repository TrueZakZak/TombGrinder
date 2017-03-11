// Fill out your copyright notice in the Description page of Project Settings.

#include "TombGrinder.h"
#include "TombGrinderCharacter.h"


// Sets default values
ATombGrinderCharacter::ATombGrinderCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCameraComponent"));
	FPSCameraComponent->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	FPSCameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ATombGrinderCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("TombGrinder character are spawned"));
	}
}

// Called every frame
void ATombGrinderCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATombGrinderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ATombGrinderCharacter::StartJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ATombGrinderCharacter::StopJump);

	PlayerInputComponent->BindAxis(TEXT("MoveStraight"), this, &ATombGrinderCharacter::MoveStraight);
	PlayerInputComponent->BindAxis(TEXT("MoveStrafe"), this, &ATombGrinderCharacter::MoveStrafe);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATombGrinderCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATombGrinderCharacter::AddControllerPitchInput);
}

void ATombGrinderCharacter::MoveStraight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void ATombGrinderCharacter::MoveStrafe(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ATombGrinderCharacter::StartJump()
{
	bPressedJump = true;
}

void ATombGrinderCharacter::StopJump()
{
	bPressedJump = false;
}
