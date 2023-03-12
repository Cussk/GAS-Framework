// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GAS_GameTypes.h"
#include "CharacterDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GASFRAMEWORK_API UCharacterDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
		FCharacterData CharacterData;
	
};
