// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InterfaceInteractor.h"
#include "GameFramework/Actor.h"
#include "StatueActor.generated.h"

UCLASS()
class TEDST_API AStatueActor : public AActor,
	public IInterfaceInteractor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStatueActor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact(); virtual void Interact_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
