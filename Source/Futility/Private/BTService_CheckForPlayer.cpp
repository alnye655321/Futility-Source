// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BTService_CheckForPlayer.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FutilityVRCharacter.h"
#include "NpcAI.h"
#include "Npc.h"
#include "BTService_CheckForPlayer.h"

UBTService_CheckForPlayer::UBTService_CheckForPlayer()
{
	bCreateNodeInstance = true; // create new nodes, needed for multiple AIs
}

//checking for the player on every tick
void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	ANpcAI *NpcPC = Cast<ANpcAI>(OwnerComp.GetAIOwner()); // get AI controller class

	// check that we have both AI controller and player pawn
	if(NpcPC)
	{
		AFutilityVRCharacter *TargetPlayer = Cast<AFutilityVRCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()); // get the first player pawn, ie VR player

		if (TargetPlayer)
		{
			//OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(NpcPC->TargetEnemyKeyName, TargetPlayer); // set the blackboard value to the target player, !!! need to use a getter/setter here
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "player is here");
		}
	}
}
