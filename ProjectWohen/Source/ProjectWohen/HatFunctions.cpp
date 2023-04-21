// Fill out your copyright notice in the Description page of Project Settings.


#include "HatFunctions.h"

#include "CollisionLibrary.h"
#include "CollisionLibrary.h"

// Sets default values for this component's properties
UHatFunctions::UHatFunctions()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UHatFunctions::BeginPlay()
{
	Super::BeginPlay();
}

void UHatFunctions::SpawnNewHat(bool hatSpawned, FVector& newLoc)
{
	while (hatSpawned == false)
	{
		int randomx = rand() % 33; // 34
		int randomy = rand() % 29; //30

		if (MazeArray2[randomy][randomx] != 1)
		{
			newLoc.X = randomx * 100;
			newLoc.Y = randomy * 100;
            		
			hatSpawned = true;
		}
		
		//inform UI and AI of new location
	}
}





