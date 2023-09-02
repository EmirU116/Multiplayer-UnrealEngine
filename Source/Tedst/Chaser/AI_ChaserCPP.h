// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI_ChaserCPP.generated.h"

UCLASS()
class TEDST_API AAI_ChaserCPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_ChaserCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
