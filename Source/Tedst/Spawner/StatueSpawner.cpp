// Fill out your copyright notice in the Description page of Project Settings.


#include "StatueSpawner.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UStatueSpawner::UStatueSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UStatueSpawner::Spawner()
{
	auto owner = GetOwner();

	FVector RandomUnitVector = UKismetMathLibrary::RandomUnitVector();
	RandomUnitVector.Z = 0.f;

	const FVector RandomSpawn = RandomUnitVector * Radius;

	owner->SetActorLocation(owner->GetActorLocation() + RandomSpawn);
}

// Called when the game starts
void UStatueSpawner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatueSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//make timer

	Timer += DeltaTime;	// +1

	if (Timer > Interval)
	{
		Timer -= Interval;
		Spawner();
	}
}

