// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Npc.h"
#include "NpcLucy.generated.h"

/**
 * 
 */
UCLASS()
class FUTILITY_API ANpcLucy : public ANpc
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANpcLucy();

	// Tick is enabled
	virtual void Tick(float DeltaTime);
	
	
	
	
};
