// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS_GameTypes.generated.h"

USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GAS")
		TArray<TSubclassOf<class UGameplayEffect>> Effects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GAS")
		TArray<TSubclassOf<class UGameplayAbility>> Abilities;
};
