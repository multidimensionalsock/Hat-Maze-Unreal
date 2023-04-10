// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionLibrary.h"

// Sets default values for this component's properties
UCollisionLibrary::UCollisionLibrary()
{
	
}

void UCollisionLibrary::AddHat_Implementation(AActor* other, UStaticMeshComponent* _staticMesh)
{
	if (other->Tags[0] == "Hat")
	{
	   if (_sockets.IsEmpty())
	   {
	   		_sockets = _staticMesh->GetAllSocketNames();
	   		maxHatNumber = _sockets.Num();
	   }
	   FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true);
	   if (hatNumber < maxHatNumber)
	   {
		  other->AttachToComponent(_staticMesh, rules, _sockets[hatNumber]);
		  hatNumber++;
	   }
	  
	}
}



// Called when the game starts
void UCollisionLibrary::BeginPlay()
{
	Super::BeginPlay();

	// ...
}




