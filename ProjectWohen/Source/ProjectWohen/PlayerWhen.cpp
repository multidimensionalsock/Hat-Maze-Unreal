// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWhen.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
APlayerWhen::APlayerWhen()
{
	_staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh"));
	_staticMesh->SetupAttachment(GetCapsuleComponent());
}

// Called when the game starts or when spawned
void APlayerWhen::BeginPlay()
{
	if (APlayerController* pcref = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* subsyt = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pcref->GetLocalPlayer()))
		{
			subsyt->AddMappingContext(_mappingContext, 0);
		}
	}
	
	Super::BeginPlay();
	
}



// Called to bind functionality to input
void APlayerWhen::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* _InputComp = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		_InputComp->BindAction(_moveAction, ETriggerEvent::Triggered, this, &APlayerWhen::Move);
	}
	
}

void APlayerWhen::Move(const FInputActionValue& Value)
{
	FVector2d vValue = Value.Get<FVector2d>();
	if (Controller != nullptr)
	{
		FRotator controlRot = GetControlRotation();
		AddMovementInput(UKismetMathLibrary::GetRightVector(controlRot),vValue.X);
		AddMovementInput(UKismetMathLibrary::GetForwardVector(controlRot),vValue.Y);
	}
}

