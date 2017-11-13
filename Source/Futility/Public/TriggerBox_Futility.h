// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TriggerBox_Futility.generated.h"

/**
 * 
 */
UCLASS()
class FUTILITY_API ATriggerBox_Futility : public ATriggerBox
{
	GENERATED_BODY()

public:
		ATriggerBox_Futility();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// root component for everything else to be attached to
	// A SceneComponent has a transform and supports attachment, but has no rendering or collision capabilities. Useful as a 'dummy' component in the hierarchy to offset others
	UPROPERTY(EditAnywhere)
		USceneComponent* PickupRoot;

	
};
