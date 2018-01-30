// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NpcAI.h"
#include "Npc.h"
#include "OutdoorTriggerBox.h"
#include "BTServiceCheckForOutdoorEntry.h"



UBTServiceCheckForOutdoorEntry::UBTServiceCheckForOutdoorEntry()
{
	bCreateNodeInstance = true; // create new nodes
}

void UBTServiceCheckForOutdoorEntry::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{

	ANpcAI *NpcPC = Cast<ANpcAI>(OwnerComp.GetAIOwner()); // get AI controller class

	if (NpcPC)
	{		
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOutdoorTriggerBox::StaticClass(), FoundActors);

		if (FoundActors.Num() > 0)
		{
			int32 randIndex = NpcPC->getRandOutdoorEntry();
			AActor* Actor = FoundActors[randIndex];
			//OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(NpcPC->EntryPointID, Actor); // set the blackboard value to the target player !!! need to use getter/setter from AI here
		}

	}
}