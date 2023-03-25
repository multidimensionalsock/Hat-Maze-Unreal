// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComponentDeadSignature, AController*, causer);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTWOHEN_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable, Category="Components")
	FComponentDeadSignature onComponentDead;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Health")
	float m_CurrentHealth;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Health")
	float m_Maxhealth;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Shield")
	float m_CurrentShield;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Shield")
	float m_MaxShield;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Shield")
	bool m_CanRegenShield;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Shield")
	float m_ShieldRecoverDelayTimer;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Shield")
	float m_ShieldRecoverRate;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Shield")
	float m_ShieldRecoverDelay;
	
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType, AController* instigator, AActor* causer);
	

	
		
};
