// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterPawn.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyCharacterPawn::AMyCharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyCharacterPawn::Move(FVector2D AxisValue)
{
	auto MoveVector = FVector(AxisValue.X, AxisValue.Y, 0.f);

	auto TransformedVector = UKismetMathLibrary::TransformDirection(
		GetActorTransform(),
		MoveVector);

	auto deltaTime = GetWorld() -> GetDeltaSeconds();
	
	MoveVector *= moveSpeed;

	SetActorLocation(
		GetActorLocation()
		+ MoveVector);
}

