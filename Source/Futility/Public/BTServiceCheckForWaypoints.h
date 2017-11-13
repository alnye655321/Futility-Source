// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTServiceCheckForWaypoints.generated.h"

/**
 * 
 */
UCLASS()
class FUTILITY_API UBTServiceCheckForWaypoints : public UBTService
{
	GENERATED_BODY()
	

public:

	UBTServiceCheckForWaypoints();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	


	
	
};
