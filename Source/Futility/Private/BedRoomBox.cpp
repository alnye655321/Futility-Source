// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "Npc.h"
#include "Chair.h"
#include "BedRoomBox.h"


// Sets default values
ABedRoomBox::ABedRoomBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BedRoomBoxRoot = CreateDefaultSubobject<USceneComponent>(TEXT("LivingRoomTriggerBox")); // initialize a component
	RootComponent = BedRoomBoxRoot; // set the root component --> Collision primitive that defines the transform (location, rotation, scale) of this Actor

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); // set world scale according to new vector, relative to parent root
	CollisionBox->SetRelativeLocation(FVector(1.0f, 1.0f, 1.0f));// relative to parent root
	CollisionBox->bGenerateOverlapEvents = true; // set overlap events to true	
	CollisionBox->AttachToComponent(BedRoomBoxRoot, FAttachmentTransformRules::KeepRelativeTransform); // attach to root component of PickupRoot

}

// Called when the game starts or when spawned
void ABedRoomBox::BeginPlay()
{
	//Super::BeginPlay();

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABedRoomBox::OnPlayerEnterPickupBox); // begin overlap
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ABedRoomBox::OnPlayerLeavePickupBox); // end overlap

}

// Called every frame
void ABedRoomBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ABedRoomBox::getLocationVec()
{
	return LocationVec;
}

// triggers enter bedroom room change in npc character
void ABedRoomBox::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, OtherActor->GetName() + "bedroom");

	ANpc* PossibleNpc = Cast<ANpc>(OtherActor);

	if (PossibleNpc != NULL)
	{
		PossibleNpc->setInBedRoom(true);

		int32 randomActorClass = 0;//!!! set to random number here when adding more interactable actors

		if (randomActorClass == 0)
		{
			TArray <AActor*> OverlappingActors;
			GetOverlappingActors(OverlappingActors);
			//should set another random number here based on total number of actors
			for (auto Chair : OverlappingActors)
			{
				AChair* PossibleChair = Cast<AChair>(Chair);
				if (PossibleChair != NULL)
				{
					PossibleNpc->SetTarget(Chair);
					FVector ChairSitdownLocation = PossibleChair->GetLocationVec();
					PossibleNpc->SetTargetVector(ChairSitdownLocation);
				}
				
			}
			

		}
	}

	//GetOverlappingActors(OverlappingActors);//return all overlapping actors
	
}

// triggers leave bedroom room change in npc character
void ABedRoomBox::OnPlayerLeavePickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, OtherActor->GetName() + "leave bedroom");

	ANpc* PossibleNpc = Cast<ANpc>(OtherActor);

	if (PossibleNpc != NULL)
	{
		PossibleNpc->setInBedRoom(false);
	}

}

void ABedRoomBox::FindSeat(float HealValue)
{
	TArray<AActor*> SeatsInZone;

	GetOverlappingActors(SeatsInZone, TSubclassOf<ANpc>()); // need to change & crate Seat class

	for (auto Seat : SeatsInZone)
	{

	}
}