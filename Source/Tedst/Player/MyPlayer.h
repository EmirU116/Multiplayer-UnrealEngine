// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class TEDST_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* flashlight;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void ToggleFlash(TArray<USceneComponent>* target);
	
	UFUNCTION(BlueprintCallable)
	void Move(FVector2D AxisValue);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float moveSpeed = 25;

	bool isFlashOn = true;
	
};
