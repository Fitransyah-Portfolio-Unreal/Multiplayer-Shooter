// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"
#include "Net/VoiceConfig.h"
#include "GameFramework/Actor.h"
#include "Blaster/Character/BlasterCharacter.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if (GameState)
	{
		// Track incoming player name
		APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
		if (PlayerState)
		{
			PlayerState->GetPlayerName();
			// This can be broadcast using delegates?
		}

		// Maximum player action
		int32 NumberOfPlayer = GameState.Get()->PlayerArray.Num();
		if (NumberOfPlayer == 2)
		{
			UWorld* World = GetWorld();
			if (World)
			{
				bUseSeamlessTravel = true;
				World->ServerTravel(FString("/Game/Maps/Windmills?listen"));
			}
		}

		// Maybe track incoming players using GameState.Get()->PlayerArray.Num();
	}


	// Make VOID Talker component in character class
	// Construct default when init
	
	// On Post Login 
	// PlayerController get parent actor
	// cast parent actor to BlasterCharacter
	// Take VOIP Component and register it with player state
	// Some setting like mic threshold, attenuation and bla bla bla
	

}
