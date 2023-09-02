// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyCharacterPawn.generated.h"

UCLASS()
class TEDST_API AMyCharacterPawn : public APawn
{
	GENERATED_BODY()

	
public:
	// Sets default values for this pawn's properties
	AMyCharacterPawn();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* flashlight;

	UFUNCTION(BlueprintCallable)
	void Move(FVector2D AxisValue);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float moveSpeed = 12.f;
};
