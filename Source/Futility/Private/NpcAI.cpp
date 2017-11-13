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

	LocationVec = FVector(0.0f, 0.0f, 0.0f);
}

void ANpcAI::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	ANpc *Char = Cast<ANpc>(InPawn);

	if (Char && Char->BotBehavior) // if both are not null
	{
		BlackbaordComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset); // init blackboard

		EnemyKeyID = BlackbaordComp->GetKeyID("Target"); // target is name for id in blackboard, can store anything waypoints etc.
		WayPointLocationID = BlackbaordComp->GetKeyID("WayPointLocActor"); // !!! need another if check here, assuming at least one waypoint exisiting

		BehaviorComp->StartTree(*Char->BotBehavior); // start the tree to decide actions
	}
}

// should perform some additional validity check here !!!
FVector ANpcAI::getLocationVec()
{
	return LocationVec;
}

void ANpcAI::setLocationVec(FVector location)
{
	LocationVec = location;
}



