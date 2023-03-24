// Fill out your copyright notice in the Description page of Project Settings.


#include "DanceComponent.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"


UDanceComponent::UDanceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// Get Owner Character Skeletal Mesh and Anim Instance
	AActor* Owner = GetOwner();
	if (Owner)
	{
		OwnerCharacter = Cast<ACharacter>(Owner);
		OwnerSkeletalMesh = OwnerCharacter->GetMesh();
		OwnerAnimInstance = OwnerSkeletalMesh->GetAnimInstance();
	}
}



void UDanceComponent::BeginPlay()
{
	Super::BeginPlay();
		
}



void UDanceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// FString CharVelocity = OwnerCharacter->GetCharacterMovement()->Velocity.ToCompactString();
	// UE_LOG(LogTemp, Display, TEXT(" Message here : %s"), *CharVelocity);

	if (OwnerCharacter->GetCharacterMovement()->Velocity != FVector::Zero())
	{
		OwnerAnimInstance->StopAllMontages(0.25f);
	}

}

// Call this on blueprint for easier use
void UDanceComponent::Dance(FString MontageSelected)
{
	if (OwnerCharacter->GetCharacterMovement()->IsFalling())
	{
		return;
	}

	if (OwnerAnimInstance && DanceMontageMap.Num() > 0 && DanceMontageMap.Contains(MontageSelected))
	{
		OwnerAnimInstance->Montage_Play(DanceMontageMap[MontageSelected], 1.0f);
	}

}

