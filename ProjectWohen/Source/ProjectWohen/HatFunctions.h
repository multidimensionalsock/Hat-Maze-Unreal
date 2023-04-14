



// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HatFunctions.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTWOHEN_API UHatFunctions : public UActorComponent
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this component's properties
	UHatFunctions();
	

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	//int MazeArray[5][2] = {{0, 0, 0, 0, 0, 0},
                           //{1, 0, 0, 0, 0, 0},
						   //{1, 1, 0, 1, 0, 1}};

public:
	UPROPERTY(EditAnywhere, Category = "HatSpawning")
	AActor* objectToBeSpawned;
	
	UFUNCTION(BlueprintCallable, Category = "HatSpawning")
		void SpawnNewHat(bool hatSpawned, FVector& newLoc);
};

