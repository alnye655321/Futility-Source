// Fill out your copyright notice in the Description page of Project Settings.

#include "Futility.h"
#include "MyPickup.h"


// Sets default values
AMyPickup::AMyPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot")); // initialize a component
	RootComponent = PickupRoot; // set the root component --> Collision primitive that defines the transform (location, rotation, scale) of this Actor

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	PickupMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale); // attach to root component of PickupRoot, "->" dereferences a pointer to select a field

	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupBox"));
	PickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); // set world scale according to new vector
	PickupBox->bGenerateOverlapEvents = true; // set overlap events to true
	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &AMyPickup::OnPlayerEnterPickupBox); // on the overlap of this call APickup OnPlayerEnterPickupBox function
	PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale); // attach to root component of PickupRoot



}

// Called when the game starts or when spawned
void AMyPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPickup::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Destroy();
}

