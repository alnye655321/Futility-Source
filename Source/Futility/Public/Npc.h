// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
		bool isInside;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool inKitchen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool inFamilyRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool inLivingRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCAttr)
		bool inBedRoom;

	UFUNCTION(BlueprintCallable, Category = "FutilityAI")
		void facePlayer();

	// getters & setters

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void SetTarget(class AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void SetTargetVector(FVector TargetVec);

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		bool getIsInside();

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void setIsInside(bool outside);

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

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		bool getInBedRoom();

	UFUNCTION(BlueprintCallable, Category = "FutilityNPC")
		void setInBedRoom(bool bedRoom);

	
	
};
