// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

#include "MovieSceneSequenceID.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AMyPlayer::ToggleFlash(USceneComponent* target)
{

	if (isFlashOn)
	{
		target->SetVisibility(true);
		isFlashOn = false;
	}
	else
	{
		target->SetVisibility(false);
		isFlashOn = true;
	}
}


void AMyPlayer::Move(FVector2D AxisValue)
{
	// Define movement rules
	auto MoveVector = FVector(AxisValue.X, AxisValue.Y, 0);

	// calculating direction change
	auto TransformVector = UKismetMathLibrary::TransformDirection(
		GetActorTransform(),
		MoveVector);

	// deltatime 
	auto deltaTime = GetWorld()-> GetDeltaSeconds();

	// making movement happen with speed
	MoveVector *= moveSpeed * deltaTime;

	// executing the move
	SetActorLocation(
		GetActorLocation()
		+ MoveVector);
}

