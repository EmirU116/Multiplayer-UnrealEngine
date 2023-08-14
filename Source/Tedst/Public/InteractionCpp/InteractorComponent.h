// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEDST_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	FCollisionShape TraceSphere;

public:	
	// Sets default values for this component's properties
	UInteractorComponent();

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Radius = 500.f;
protected:

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
