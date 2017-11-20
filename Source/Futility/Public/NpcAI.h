// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "AIController.h"
#include "NpcAI.generated.h"

/**
 * 
 */
UCLASS()
class FUTILITY_API ANpcAI : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(transient) // initilize to 0 at the start
		class UBlackboardComponent *BlackbaordComp;

	UPROPERTY(transient)
		class UBehaviorTreeComponent *BehaviorComp;
	
public:

	ANpcAI();

	virtual void Possess(APawn *InPawn) override;

	uint8 EnemyKeyID; // to get blackboard objects in cpp by uint8 key
	uint8 WayPointLocationID;
	uint8 EntryPointID;

	int32 getRandOutdoorEntry(); // set random int for picking from entry box array at the moment
	void setRandOutdoorEntry(int32 setInt);

	UFUNCTION(BlueprintCallable, Category = "FutilityAI")
		FVector getLocationVec();

	UFUNCTION(BlueprintCallable, Category = "FutilityAI")
		void setLocationVec(FVector location);

private:

	FVector LocationVec;
	int32 randEntry; // for choosing entrance to building
	
	
};
