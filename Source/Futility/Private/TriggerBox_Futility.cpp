// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "Npc.h"
#include "TriggerBox_Futility.h"

// Sets default values
ATriggerBox_Futility::ATriggerBox_Futility()
{

	PrimaryActorTick.bCanEverTick = true;

	FutilityTriggerRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FutilityTriggerBox")); // initialize a component
	RootComponent = FutilityTriggerRoot; // set the root component --> Collision primitive that defines the transform (location, rotation, scale) of this Actor

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); // set world scale according to new vector, relative to parent root
	CollisionBox->SetRelativeLocation(FVector(1.0f, 1.0f, 1.0f));// relative to parent root
	CollisionBox->bGenerateOverlapEvents = true; // set overlap events to true	
	CollisionBox->AttachToComponent(FutilityTriggerRoot, FAttachmentTransformRules::KeepRelativeTransform); // attach to root component of PickupRoot



}

void ATriggerBox_Futility::BeginPlay()
{
	LocationVec = GetActorLocation();

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATriggerBox_Futility::OnPlayerEnterPickupBox); // on the overlap
}

// Called every frame
void ATriggerBox_Futility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ATriggerBox_Futility::getLocationVec()
{
	return LocationVec;
}

// triggers present in indoor location for npc character
void ATriggerBox_Futility::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "collision log2");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, OtherActor->GetName());
	ANpc* PossibleNpc = Cast<ANpc>(OtherActor);

	if (PossibleNpc != NULL)
	{
		//PossibleNpc->setIsOutside(false); // inside now
	}


}