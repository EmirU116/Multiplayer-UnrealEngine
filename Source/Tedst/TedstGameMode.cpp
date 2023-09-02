// Copyright Epic Games, Inc. All Rights Reserved.

#include "TedstGameMode.h"
#include "TedstCharacter.h"
#include "UObject/ConstructorHelpers.h"

 ATedstGameMode::ATedstGameMode()
 {
 	// set default pawn class to our Blueprinted character
 	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/InteractCpp/Character/BP_Player"));
 	static ConstructorHelpers::FClassFinder<ACharacter> MyPlayerCharacterBPClass(TEXT("/Game/Player/BP_MYPLayer"));
 	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/InteractCpp/BP_Controller"));
 	if (PlayerPawnBPClass.Class != NULL)
 	{
		DefaultPawnClass = MyPlayerCharacterBPClass.Class;
 		PlayerControllerClass = PlayerControllerBPClass.Class;
 	}
}
