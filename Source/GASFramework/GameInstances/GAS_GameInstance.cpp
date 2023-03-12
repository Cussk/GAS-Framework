// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstances/GAS_GameInstance.h"

#include  "AbilitySystemGlobals.h"

void UGAS_GameInstance::Init()
{
	Super::Init();

	UAbilitySystemGlobals::Get().InitGlobalData();
}

