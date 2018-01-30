// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BedRoomBox.generated.h"

UCLASS()
class FUTILITY_API ABedRoomBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABedRoomBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// root component for everything else to be attached to
	// A SceneComponent has a transform and supports attachment, but has no rendering or collision capabilities. Useful as a 'dummy' component in the hierarchy to offset others
	UPROPERTY(EditAnywhere)
		USceneComponent* BedRoomBoxRoot;

	// collision box
	UPROPERTY(EditAnywhere)
		UShapeComponent* CollisionBox;

	UFUNCTION(BlueprintCallable, Category = "BedRoomTriggerBox")
		FVector getLocationVec();

	// called when player enters the box
	UFUNCTION()
		void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// called when player leaves the box
	UFUNCTION()
		void OnPlayerLeavePickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void FindSeat(float HealValue);


private:

	FVector LocationVec;



};
