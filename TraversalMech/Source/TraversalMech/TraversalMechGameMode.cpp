// Copyright Epic Games, Inc. All Rights Reserved.

#include "TraversalMechGameMode.h"
#include "TraversalMechCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATraversalMechGameMode::ATraversalMechGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
