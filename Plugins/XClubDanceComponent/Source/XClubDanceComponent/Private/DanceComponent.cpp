// Fill out your copyright notice in the Description page of Project Settings.


#include "DanceComponent.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"

// Sets default values for this component's properties
UDanceComponent::UDanceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Get Skeletal Mesh
	AActor* Owner = GetOwner();
	if (Owner)
	{
		OwnerCharacter = Cast<ACharacter>(Owner);
		OwnerSkeletalMesh = OwnerCharacter->GetMesh();
		OwnerAnimInstance = OwnerSkeletalMesh->GetAnimInstance();
	}


	// ...
}


// Called when the game starts
void UDanceComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}


// Called every frame
void UDanceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FString CharVelocity = OwnerCharacter->GetCharacterMovement()->Velocity.ToCompactString();
	
	UE_LOG(LogTemp, Display, TEXT(" Message here : %s"), *CharVelocity);

	if (OwnerCharacter->GetCharacterMovement()->Velocity != FVector::Zero())
	{
		OwnerAnimInstance->StopAllMontages(0.25f);
	}

	// ...
}

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

