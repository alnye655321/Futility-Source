// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BTServiceCheckForWaypoints.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAI.h"
#include "Npc.h"
#include "TriggerBox_Futility.h"
#include "BTService_CheckForPlayer.h"

UBTServiceCheckForWaypoints::UBTServiceCheckForWaypoints()
{
	bCreateNodeInstance = true; // create new nodes
}

// checking for new waypoint on every tick
void UBTServiceCheckForWaypoints::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	ANpcAI *NpcPC = Cast<ANpcAI>(OwnerComp.GetAIOwner()); // get AI controller class

	if (NpcPC) 
	{
		//ATriggerBox_Futility * TargetBox = Cast<ATriggerBox_Futility>(GetWorld()->Get

		// need to split up into multiple trigger box classes later (for different rooms etc.), or fine way to target the one
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATriggerBox_Futility::StaticClass(), FoundActors);

		for (AActor* Actor : FoundActors)
		{
			// OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(NpcPC->TargetEnemyKeyName, Actor); // set the blackboard value to the target player !!! need to use getter/setter from AI here
			//Actor->SomeActorFunc();
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg found acotrs");
		}

	}
														  

}