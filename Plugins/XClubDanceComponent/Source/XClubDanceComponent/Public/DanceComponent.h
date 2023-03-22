// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DanceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XCLUBDANCECOMPONENT_API UDanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDanceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category = "Dance Montages Map")
	TMap<FString,class UAnimMontage*> DanceMontageMap;

	UFUNCTION(BlueprintCallable)
	void Dance(FString MontageSelected);

private:
    
	class USkeletalMeshComponent* OwnerSkeletalMesh;
	class ACharacter* OwnerCharacter;
	class UAnimInstance* OwnerAnimInstance;

		
};
