// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAI.h"
#include "Npc.h"
#include "OutdoorTriggerBox.h"
#include "BTTask_MoveToOutdoorWaypoint.h"


EBTNodeResult::Type UBTTask_MoveToOutdoorWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANpcAI *NpcPC = Cast<ANpcAI>(OwnerComp.GetAIOwner());

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOutdoorTriggerBox::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		int32 randIndex = NpcPC->getRandOutdoorEntry();
		AActor* Actor = FoundActors[randIndex];
		NpcPC->MoveToActor(Actor, 5.f, true, true, true, 0, true);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed; // if no TriggerActors it is failure
	}	
	

}

