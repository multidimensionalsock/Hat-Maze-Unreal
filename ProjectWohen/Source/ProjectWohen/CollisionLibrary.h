// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollisionLibrary.generated.h"

class aHat;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTWOHEN_API UCollisionLibrary : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCollisionLibrary();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddHat(AActor* other, UStaticMeshComponent* _staticMesh);
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	int hatNumber = 0;
	int maxHatNumber;
	TArray<FName> _sockets;


public:	
	
};
