// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TriggerBox_Futility.h"
#include "OutdoorTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class FUTILITY_API AOutdoorTriggerBox : public ATriggerBox_Futility
{
	GENERATED_BODY()
	
public:
	AOutdoorTriggerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:


	
};
