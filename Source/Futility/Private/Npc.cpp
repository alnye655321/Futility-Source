// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "Kismet/KismetMathLibrary.h"
#include "Npc.h"


// Sets default values
ANpc::ANpc()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isWalking = false;
	isOutside = true; // !!! have a check, all npcs may not start outside
	inKitchen = false;
	inFamilyRoom = false;
	inLivingRoom = false;

}

// Called when the game starts or when spawned
void ANpc::BeginPlay()
{
	Super::BeginPlay();
	
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
bool ANpc::getIsOutside()
{
	return isOutside;
}

void ANpc::setIsOutside(bool outside)
{
	isOutside = outside;
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