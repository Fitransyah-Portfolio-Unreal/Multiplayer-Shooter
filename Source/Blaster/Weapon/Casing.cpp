


#include "Casing.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "TimerManager.h"

ACasing::ACasing()
{
	PrimaryActorTick.bCanEverTick = false;

	CasingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CasingMesh"));
	SetRootComponent(CasingMesh);

	CasingMesh->SetCollisionResponseToAllChannels(ECR_Block);
	CasingMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	CasingMesh->SetSimulatePhysics(true);
	CasingMesh->SetEnableGravity(true);
	CasingMesh->SetNotifyRigidBodyCollision(true);
	ShellEjectionImpulse = 5.f;
}

void ACasing::BeginPlay()
{
	Super::BeginPlay();

	CasingMesh->OnComponentHit.AddDynamic(this, &ACasing::OnHit);
	// CasingMesh->AddImpulse(GetActorForwardVector() * ShellEjectionImpulse);
	float CasingY = FMath::RandRange(-1, 1);
	float CasingZ = FMath::RandRange(0.5, 1.5);
	CasingMesh->AddImpulse(FVector(GetActorForwardVector().X * ShellEjectionImpulse, CasingY, CasingZ));

}

void ACasing::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (ShellSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ShellSound, GetActorLocation());
	}
	
	CasingMesh->SetNotifyRigidBodyCollision(false);
	GetWorldTimerManager().SetTimer(InterpTimer, this, &ACasing::DestroyActor, 2.f, false);
	CasingMesh->AddImpulseAtLocation(FMath::VRand() * 2.f, GetActorLocation() + FMath::VRand());
}

void ACasing::DestroyActor()
{
	Destroy();
}


