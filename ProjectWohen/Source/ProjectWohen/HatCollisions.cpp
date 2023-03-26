// Fill out your copyright notice in the Description page of Project Settings.


#include "HatCollisions.h"

#include "Components/BoxComponent.h"

// Sets default values for this component's properties
UHatCollisions::UHatCollisions()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	boxCollision->InitBoxExtent(FVector(1.f));
	boxCollision->OnComponentBeginOverlap.AddDynamic(this, &UHatCollisions::OnBeginOverlap);

}


// Called when the game starts
void UHatCollisions::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHatCollisions::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHatCollisions::OnBeginOverlap(UPrimitiveComponent* overlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Collision"));
	if (!OtherActor->ActorHasTag("EnemyAI") || !OtherActor->ActorHasTag("Player")){ return; }

	//need to add a y offset to this so the hat is on their head and when hats stack 
	this->GetOwner()->SetActorLocation(OtherActor->GetActorLocation());
	this->GetOwner()->SetOwner(OtherActor);

	//add score ui
	//spawn new hat 
}

