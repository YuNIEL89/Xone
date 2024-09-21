// Copyright Epic Games, Inc. All Rights Reserved.

#include "XoneGameMode.h"
#include "Character/XoneCharacter.h"
#include "UObject/ConstructorHelpers.h"

AXoneGameMode::AXoneGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Xone/BP_XoneCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
