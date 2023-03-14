// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/GAS_AnimInstance.h"

#include "GASFrameworkCharacter.h"
#include "GAS_GameTypes.h"
#include "Animation/AnimSequenceBase.h"
#include "Animation/BlendSpace.h"
#include "DataAssets/CharacterDataAsset.h"
#include "DataAssets/CharacterAnimDataAsset.h"

UBlendSpace* UGAS_AnimInstance::GetLocomotionBlendspace() const
{
	if (AGASFrameworkCharacter* GASFrameworkCharacter = Cast<AGASFrameworkCharacter>(GetOwningActor()))
	{
		FCharacterData Data = GASFrameworkCharacter->GetCharacterData();

		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.MovementBlendspace : nullptr;
}

UAnimSequenceBase* UGAS_AnimInstance::GetIdleAnimation() const
{
	if (AGASFrameworkCharacter* GASFrameworkCharacter = Cast<AGASFrameworkCharacter>(GetOwningActor()))
	{
		FCharacterData Data = GASFrameworkCharacter->GetCharacterData();

		if (Data.CharacterAnimDataAsset)
		{
			return Data.CharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset;
		}
	}

	return DefaultCharacterAnimDataAsset ? DefaultCharacterAnimDataAsset->CharacterAnimationData.IdleAnimationAsset: nullptr;
}

