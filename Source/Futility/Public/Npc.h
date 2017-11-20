// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Npc.generated.h"

UCLASS()
class FUTILITY_API ANpc : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANpc();

	UPROPERTY(EditAnywhere, Category = Behavior)
		class UBehaviorTree *BotBehavior;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool isWalking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool isOutside;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool inKitchen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool inFamilyRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool inLivingRoom;

	UFUNCTION(BlueprintCallable, Category = "FutilityAI")
		void facePlayer();

	// getters & setters
	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		bool getIsOutside();

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void setIsOutside(bool outside);

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		bool getInKitchen();

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void setInKitchen(bool kitchen);

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		bool getInFamilyRoom();

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void setInFamilyRoom(bool familyRoom);

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		bool getInLivingRoom();

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void setInLivingRoom(bool livingRoom);

	
	
};
