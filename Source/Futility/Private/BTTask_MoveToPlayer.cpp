// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAI.h"
#include "FutilityVRCharacter.h"
#include "Npc.h"
#include "BTTask_MoveToPlayer.h"



EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANpcAI *NpcPC = Cast<ANpcAI>(OwnerComp.GetAIOwner());

	// cast it from the blackboard key
	// value is set in BTService_CheckForPlayer, which is run in engine Behavior Tree, and controlled by NpcAI
	// accessed in engine in BehaviorTree through tasks, MoveToPlayer. Called after check for player
	//AFutilityVRCharacter *TargetPlayer = Cast<AFutilityVRCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(NpcPC->TargetEnemyKeyName)); // !!! need to use getter/setter from AI here

	//if (TargetPlayer)
	//{
	//	NpcPC->MoveToActor(TargetPlayer, 5.f, true, true, true, 0, true);
	//	return EBTNodeResult::Succeeded;
	//}
	//else
	//{
		return EBTNodeResult::Failed;
	//}
}
