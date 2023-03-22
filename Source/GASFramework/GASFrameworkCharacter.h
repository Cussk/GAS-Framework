// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemInterface.h"
#include "GAS_GameTypes.h"
#include "GASFrameworkCharacter.generated.h"

class UGAS_AbilitySystemComponentBase;
class UGAS_AttributeSetBase;

class UGameplayEffect;
class UGameplayAbility;


UCLASS(config=Game)
class AGASFrameworkCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Crouch Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CrouchAction;

	/** Sprint Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* SprintAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:
	AGASFrameworkCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void PostInitializeComponents() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	bool ApplyGameplayEffectToSelf(TSubclassOf<UGameplayEffect> Effect, FGameplayEffectContextHandle InEffectContext);

	virtual void Landed(const FHitResult& Hit) override;

	virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

	virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

protected:

	void GiveAbilities();
	void ApplyStartupEffects();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditDefaultsOnly)
		UGAS_AbilitySystemComponentBase* AbilitySystemComponent;

	UPROPERTY(Transient)
		UGAS_AttributeSetBase* AttributeSet;
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void Jump(const FInputActionValue& Value);

	void OnCrouchActionStarted(const FInputActionValue& Value);

	void OnCrouchActionEnded(const FInputActionValue& Value);

	void OnSprintActionStarted(const FInputActionValue& Value);

	void OnSprintActionEnded(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

public:

	UFUNCTION(BlueprintCallable)
		FCharacterData GetCharacterData() const;

	UFUNCTION(BlueprintCallable)
		void SetCharacterData(const FCharacterData& InCharacterData);

	class UFootstepsComponent* GetFootstepsComponent() const;

	void OnMaxMovementSpeedChanged(const FOnAttributeChangeData& Data);

protected:

	UPROPERTY(ReplicatedUsing = OnRep_CharacterData)
		FCharacterData CharacterData;

	UFUNCTION()
		void OnRep_CharacterData();

	virtual void InitFromCharacterData(const FCharacterData& InCharacterData, bool bFromReplication = false);

	UPROPERTY(EditDefaultsOnly)
		class UCharacterDataAsset* CharacterDataAsset;

	UPROPERTY(BlueprintReadOnly)
		class UFootstepsComponent* FootstepsComponent;

	// Gameplay Events

protected:

	UPROPERTY(EditDefaultsOnly)
		FGameplayTag JumpEventTag;


	// Gameplay Tags

protected:

	UPROPERTY(EditDefaultsOnly)
		FGameplayTagContainer InAirTags;

	UPROPERTY(EditDefaultsOnly)
		FGameplayTagContainer CrouchTags;

	UPROPERTY(EditDefaultsOnly)
		FGameplayTagContainer SprintTags;

	// Gameplay Effects

protected:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UGameplayEffect> CrouchStateEffect;

	// Delegates

protected:

	FDelegateHandle MaxMovementSpeedChangedDelegateHandle;
};

