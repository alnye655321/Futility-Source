// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAI.h"
#include "Npc.h"
#include "TriggerBox_Futility.h"
#include "BTTask_MoveToWaypoint.h"


UBTTask_MoveToWaypoint::UBTTask_MoveToWaypoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

EBTNodeResult::Type UBTTask_MoveToWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANpcAI* MyController = Cast<ANpcAI>(OwnerComp.GetAIOwner());

	// need to split up into multiple trigger box classes later (for different rooms etc.), or find way to target the one
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATriggerBox_Futility::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		// never changing the blackboard key value here
		// should be different random selection method, there is one inline func in another project... !!!
		int32 randIndex = MyController->getRandOutdoorEntry(); // this should not be getRandOutdoorEntry
		AActor* Actor = FoundActors[randIndex];
		ATriggerBox_Futility* indoorBox = Cast<ATriggerBox_Futility>(Actor);
		MyController->SetIndoorBox(indoorBox);

		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed; // if no TriggerActors it is failure
	}

}

