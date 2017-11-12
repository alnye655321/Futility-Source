// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "FutilityVRCharacter.h"


AFutilityVRCharacter::AFutilityVRCharacter()
{
	PrimaryActorTick.bCanEverTick = true; //We won't be ticked by default


}

void AFutilityVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // Call parent class tick function 
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");
}

void AFutilityVRCharacter::myTestCall_Implementation()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "me test");
}


