// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "Npc.h"
#include "FamilyRoomBox.h"


// Sets default values
AFamilyRoomBox::AFamilyRoomBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FamilyRoomBoxRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FamilyRoomTriggerBox")); // initialize a component
	RootComponent = FamilyRoomBoxRoot; // set the root component --> Collision primitive that defines the transform (location, rotation, scale) of this Actor

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); // set world scale according to new vector, relative to parent root
	CollisionBox->SetRelativeLocation(FVector(1.0f, 1.0f, 1.0f));// relative to parent root
	CollisionBox->bGenerateOverlapEvents = true; // set overlap events to true	
	CollisionBox->AttachToComponent(FamilyRoomBoxRoot, FAttachmentTransformRules::KeepRelativeTransform); // attach to root component of PickupRoot

}

// Called when the game starts or when spawned
void AFamilyRoomBox::BeginPlay()
{
	//Super::BeginPlay();

	LocationVec = GetActorLocation();

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AFamilyRoomBox::OnPlayerEnterPickupBox); // on the overlap
	
}

// Called every frame
void AFamilyRoomBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AFamilyRoomBox::getLocationVec()
{
	return LocationVec;
}

// triggers in family room change in npc character
void AFamilyRoomBox::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, OtherActor->GetName() + "family room box");

	ANpc* PossibleNpc = Cast<ANpc>(OtherActor);

	if (PossibleNpc != NULL)
	{
		PossibleNpc->setInFamilyRoom(true);
	}


}
