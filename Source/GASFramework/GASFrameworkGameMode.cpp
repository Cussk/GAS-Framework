// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASFrameworkGameMode.h"
#include "GASFrameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASFrameworkGameMode::AGASFrameworkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
