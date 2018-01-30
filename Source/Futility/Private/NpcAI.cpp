// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "NpcAI.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Npc.h"
#include "OutdoorTriggerBox.h"
#include "TriggerBox_Futility.h"


ANpcAI::ANpcAI(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComp"));

	BrainComponent = BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));

	bWantsPlayerState = true;

	/* Match with the AI/Blackboard */
	//TargetEnemyKeyName = "Target";
	//WaypiontActorKeyName = "WaypointActor";
	//EntryPointActorKeyName = "EntryPointActor";
	
	LocationVec = FVector(0.0f, 0.0f, 0.0f);

	// for setting the outdoor AI entry point to house
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOutdoorTriggerBox::StaticClass(), FoundActors);
	randEntry = FMath::RandRange(0, FoundActors.Num() - 1); // at the moment should be 0 or 1 for the 2 boxes in play !!! needs changing for more entry boxes
}

void ANpcAI::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	ANpc *Bot = Cast<ANpc>(InPawn);

	// start behavior
	if (Bot && Bot->BotBehavior)
	{
		if (Bot->BotBehavior->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*Bot->BotBehavior->BlackboardAsset);
		}

		// Define blackboard keys
		OutdoorBoxID = BlackboardComp->GetKeyID("OutdoorBox");
		IndoorBoxID = BlackboardComp->GetKeyID("IndoorBox");
		SelfActor = BlackboardComp->GetKeyID("SelfActor");
		IsInside = BlackboardComp->GetKeyID("IsInside");

		BehaviorComp->StartTree(*(Bot->BotBehavior));

		if (BlackboardComp)
		{
			BlackboardComp->SetValue<UBlackboardKeyType_Object>(SelfActor, Bot); // add SelfObject ref in Blackboard to this NPC Bot
		}
	}
}


int32 ANpcAI::getRandOutdoorEntry()
{
	return randEntry;
}


void ANpcAI::setRandOutdoorEntry(int32 setInt)
{
	randEntry = setInt;
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

void ANpcAI::setIsInside(bool inside)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValue<UBlackboardKeyType_Bool>(IsInside, inside);
	}
}


void ANpcAI::SetOutdoorBox(class AOutdoorTriggerBox* InActor)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValue<UBlackboardKeyType_Object>(OutdoorBoxID, InActor);
		SetFocus(InActor);
	}
}


class AOutdoorTriggerBox* ANpcAI::GetOutdoorBox() const
{
	if (BlackboardComp)
	{
		return Cast<AOutdoorTriggerBox>(BlackboardComp->GetValue<UBlackboardKeyType_Object>(OutdoorBoxID));
	}

	return NULL;
}

void ANpcAI::SetIndoorBox(class ATriggerBox_Futility* InActor)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValue<UBlackboardKeyType_Object>(IndoorBoxID, InActor);
		SetFocus(InActor);
	}
}

class ATriggerBox_Futility* ANpcAI::GetIndoorBox() const
{
	if (BlackboardComp)
	{
		return Cast<ATriggerBox_Futility>(BlackboardComp->GetValue<UBlackboardKeyType_Object>(IndoorBoxID));
	}

	return NULL;
}


