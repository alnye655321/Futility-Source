// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAI.h"
#include "Npc.h"
#include "OutdoorTriggerBox.h"
#include "BTTask_MoveToOutdoorWaypoint.h"


UBTTask_MoveToOutdoorWaypoint::UBTTask_MoveToOutdoorWaypoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

EBTNodeResult::Type UBTTask_MoveToOutdoorWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANpcAI* MyController = Cast<ANpcAI>(OwnerComp.GetAIOwner());

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOutdoorTriggerBox::StaticClass(), FoundActors);
	AActor* nearestOutdoorBox = MyController->GetNearestActor(FoundActors);//get the nearest outdoor entry tirgger box

	if (FoundActors.Num() > 0)
	{
		//int32 randIndex = MyController->getRandOutdoorEntry();
		//AActor* Actor = FoundActors[randIndex];
		AOutdoorTriggerBox* outdoorbox = Cast<AOutdoorTriggerBox>(nearestOutdoorBox);
		MyController->SetOutdoorBox(outdoorbox);

		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed; // if no TriggerActors it is failure
	}	
	

}