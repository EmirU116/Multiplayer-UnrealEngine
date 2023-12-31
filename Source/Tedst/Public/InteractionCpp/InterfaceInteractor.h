// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InterfaceInteractor.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, BlueprintType)
class UInterfaceInteractor : public UInterface
{
     GENERATED_BODY()
};

class TEDST_API IInterfaceInteractor
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact();
};
