// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalSendoffGameMode.h"
#include "FinalSendoffCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinalSendoffGameMode::AFinalSendoffGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
