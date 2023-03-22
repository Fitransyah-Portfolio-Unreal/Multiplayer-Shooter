// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetRemoteRole();
	FString Role;

	switch (LocalRole)
	{
		case ENetRole::ROLE_Authority : 
		Role = FString("Authority");
		break;

		case ENetRole::ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;

		case ENetRole::ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;

		case ENetRole::ROLE_None:
		Role = FString("none");
		break;
	}

	FString LocalRoleString = FString::Printf(TEXT("Local role is : %s"), *Role);
	SetDisplayText(LocalRoleString);

	// Get Player Name / crash if same computer
	//LocalRoleString = InPawn->GetPlayerState()->GetPlayerName();
	//SetDisplayText(LocalRoleString);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
