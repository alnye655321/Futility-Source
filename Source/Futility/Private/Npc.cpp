// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "NpcAI.h"
#include "OutdoorTriggerBox.h"
#include "Kismet/KismetMathLibrary.h"
#include "Npc.h"


// Sets default values
ANpc::ANpc()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isWalking = false;
	isInside = false; // !!! have a check, all npcs may not start outside
	inKitchen = false;
	inFamilyRoom = false;
	inLivingRoom = false;
	inBedRoom = false;

}

// Called when the game starts or when spawned
void ANpc::BeginPlay()
{
	Super::BeginPlay();

	ANpcAI* AIController = Cast<ANpcAI>(GetController());

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOutdoorTriggerBox::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		int32 randIndex = AIController->getRandOutdoorEntry();
		AActor* Actor = FoundActors[randIndex];
		AOutdoorTriggerBox* outdoorTriggerBox = Cast<AOutdoorTriggerBox>(Actor);
		//AIController->SetWaypoint(outdoorTriggerBox);
		
	}
	
}

// Called every frame
void ANpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANpc::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// getters & setters
bool ANpc::getIsInside()
{
	return isInside;
}

void ANpc::setIsInside(bool inside)
{
	isInside = inside; // update local npc

	ANpcAI* AIController = Cast<ANpcAI>(GetController()); // update AI which sets BlackBoard key
	AIController->setIsInside(inside);
}

bool ANpc::getInKitchen()
{
	return inKitchen;
}

void ANpc::setInKitchen(bool kitchen)
{
	inKitchen = kitchen;
}

bool ANpc::getInFamilyRoom()
{
	return inFamilyRoom;
}

void ANpc::setInFamilyRoom(bool familyRoom)
{
	inFamilyRoom = familyRoom;
}

bool ANpc::getInLivingRoom()
{
	return inLivingRoom;
}

void ANpc::setInLivingRoom(bool livingRoom)
{
	inLivingRoom = livingRoom;
}

bool ANpc::getInBedRoom()
{
	return inBedRoom;
}

void ANpc::setInBedRoom(bool bedRoom)
{
	inBedRoom = bedRoom;
}

void ANpc::facePlayer()
{
	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (PlayerChar != NULL)
	{
		FVector PlayerLocation = PlayerChar->GetActorLocation();
		FVector NpcLocation = this->GetActorLocation();

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(NpcLocation, PlayerLocation);
		LookAtRotation.Pitch = LookAtRotation.Pitch + 20.0f; // increase pitch to look at player
		this->SetActorRotation(LookAtRotation); // set new zombie rotation
	}

}