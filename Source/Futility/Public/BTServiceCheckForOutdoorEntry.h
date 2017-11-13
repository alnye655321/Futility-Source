// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTServiceCheckForOutdoorEntry.generated.h"

/**
 * 
 */
UCLASS()
class FUTILITY_API UBTServiceCheckForOutdoorEntry : public UBTService
{
	GENERATED_BODY()
	
public:

	UBTServiceCheckForOutdoorEntry();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	
};
