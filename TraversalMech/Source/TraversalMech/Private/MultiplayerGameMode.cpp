// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerGameMode.h"

void AMultiplayerGameMode::HostGame()
{
	GetWorld()->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?Listen");
}

void AMultiplayerGameMode::JoinGame()
{
	if(APlayerController *PC = GetGameInstance()->GetFirstLocalPlayerController())
	{
		PC->ClientTravel("10.83.134.125", TRAVEL_Absolute);
	}
}
