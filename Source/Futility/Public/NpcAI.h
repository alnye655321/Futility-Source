// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Npc.h"
#include "Kismet/KismetMathLibrary.h"
#include "OutdoorTriggerBox.h"
#include "TriggerBox_Futility.h"
#include "NpcAI.generated.h"

class UBehaviorTreeComponent;
class UBlackboardComponent;

/**
 * 
 */
UCLASS()
class ANpcAI : public AAIController
{
	GENERATED_UCLASS_BODY()

private:
	UPROPERTY(transient)
		UBlackboardComponent* BlackboardComp;

	/* Cached BT component */
	UPROPERTY(transient)
		UBehaviorTreeComponent* BehaviorComp;

	FVector LocationVec;
	int32 randEntry; // for choosing entrance to building
	
public:

	virtual void Possess(class APawn *InPawn) override;

	void SetOutdoorBox(class AOutdoorTriggerBox* InActor);

	class AOutdoorTriggerBox* GetOutdoorBox() const;

	void SetIndoorBox(ATriggerBox_Futility * InActor);

	ATriggerBox_Futility * GetIndoorBox() const;

	void setIsInside(bool inside);

	int32 getRandOutdoorEntry(); // set random int for picking from entry box array at the moment
	void setRandOutdoorEntry(int32 setInt);

	UFUNCTION(BlueprintCallable, Category = "FutilityAI")
		FVector getLocationVec();

	UFUNCTION(BlueprintCallable, Category = "FutilityAI")
		void setLocationVec(FVector location);

protected:
	// Check of we have LOS to a character
	//bool LOSTrace(AShooterCharacter* InEnemyChar) const;

	int32 OutdoorBoxID;
	int32 IndoorBoxID;
	int32 SelfActor;
	int32 IsInside;

	/** Handle for efficient management of Respawn timer */
	//FTimerHandle TimerHandle_Respawn;

public:
	/** Returns BlackboardComp subobject **/
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }
	
	
};
