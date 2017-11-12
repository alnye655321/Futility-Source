// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Npc.h"
#include "NpcAI.h"

ANpcAI::ANpcAI()
{
	BlackbaordComp = CreateAbstractDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorComp = CreateAbstractDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void ANpcAI::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	ANpc *Char = Cast<ANpc>(InPawn);

	if (Char && Char->BotBehavior) // if both are not null
	{
		BlackbaordComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset); // init blackboard

		EnemyKeyID = BlackbaordComp->GetKeyID("Target"); // target is name for id in blackboard, can store anything waypoints etc.

		BehaviorComp->StartTree(*Char->BotBehavior); // start the tree to decide actions
	}
}
