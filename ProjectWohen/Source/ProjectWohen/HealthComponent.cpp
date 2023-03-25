// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	m_Maxhealth = 100.f;
	m_MaxShield = 100.f;
	m_CanRegenShield = true;
	m_ShieldRecoverRate = 10.f;
	m_ShieldRecoverDelay = 2.f;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
	m_CurrentHealth = m_Maxhealth;
	m_CurrentShield = m_MaxShield;
	
}

void UHealthComponent::DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType,
	AController* instigator, AActor* causer)
{
	float leftOverDamage = FMath::Max(damage- m_CurrentShield, 0.f);
	m_CurrentShield = FMath::Max(m_CurrentShield - damage, 0.f);
	m_ShieldRecoverDelayTimer = m_ShieldRecoverDelay;

	if (leftOverDamage > 0.f){ m_CurrentHealth = FMath::Max(m_CurrentHealth - leftOverDamage, 0.f);}

	if(m_CurrentHealth <= 0.f) {onComponentDead.Broadcast(instigator);}
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (m_CurrentShield == m_MaxShield || !m_CanRegenShield) { return; }
	
	if (m_ShieldRecoverDelay > 0.f)
	{
		m_ShieldRecoverDelayTimer -= DeltaTime;
	}
	else
	{
		m_CurrentShield = FMath::Min(m_MaxShield, m_CurrentShield + (m_ShieldRecoverRate * DeltaTime));
	}
	
}

