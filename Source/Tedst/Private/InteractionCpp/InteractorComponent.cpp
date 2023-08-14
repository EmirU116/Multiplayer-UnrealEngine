// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionCpp/InteractorComponent.h"

#include "InteractionCpp/InterfaceInteractor.h"

// Sets default values for this component's properties
UInteractorComponent::UInteractorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	TraceSphere = FCollisionShape::MakeSphere(Radius);

	// ...
}



// Called every frame
void UInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const AActor* Owner = GetOwner();

	TArray<FOverlapResult> CandidateActor;

	GetWorld()->OverlapMultiByChannel(CandidateActor,
		Owner-> GetActorLocation(),
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		TraceSphere);

	for (int i = 0; i < CandidateActor.Num(); i++)
	{
		AActor* ActorReference = CandidateActor[i].GetActor();

		if (ActorReference->Implements<UInterfaceInteractor>())
		{
			IInterfaceInteractor::Execute_Interact(ActorReference);
		}
	}
}

