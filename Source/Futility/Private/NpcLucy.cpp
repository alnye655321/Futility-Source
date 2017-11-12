// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "NpcLucy.h"


// Sets default values
ANpcLucy::ANpcLucy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANpcLucy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); // Call parent class tick function 
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "lucy debug msg");
}

