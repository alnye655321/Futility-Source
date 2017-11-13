// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAI.h"
#include "Npc.h"
#include "TriggerBox_Futility.h"
#include "BTTask_MoveToWaypoint.h"

EBTNodeResult::Type UBTTask_MoveToWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANpcAI *NpcPC = Cast<ANpcAI>(OwnerComp.GetAIOwner());

	// need to split up into multiple trigger box classes later (for different rooms etc.), or fine way to target the one
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATriggerBox_Futility::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		// this key value isn't being stored properly i think, Blackboard object and actors? conversion?
		//OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(NpcPC->WayPointLocationID, Actor);
		NpcPC->MoveToActor(Actor, 5.f, true, true, true, 0, true);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed; // if no TriggerActors it is failure

}

