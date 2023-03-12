// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Attribute/GAS_AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UGAS_AttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
}

UFUNCTION()
void UGAS_AttributeSetBase::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_AttributeSetBase, Health, OldHealth);
}

UFUNCTION()
void UGAS_AttributeSetBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAS_AttributeSetBase, Health, OldMaxHealth);
}

void UGAS_AttributeSetBase::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_AttributeSetBase, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAS_AttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always);
}