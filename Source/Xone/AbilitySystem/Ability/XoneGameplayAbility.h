// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "XoneGameplayAbility.generated.h"

class AXoneCharacter;

/**
 * Defines how ability is meant to activate
 */
UENUM(BlueprintType)
enum class EXoneAbilityActivationPolicy : uint8
{
	// Try to activate the ability when the input is triggered.
	OnInputTriggered,

	// Continually try to activate the ability while the input is active.
	WhileInputActive
};

/**
 * 
 */
UCLASS()
class XONE_API UXoneGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	EXoneAbilityActivationPolicy GetActivationPolicy() const { return ActivationPolicy; }

	UFUNCTION(BlueprintCallable, Category = "GAS|Ability")
	AXoneCharacter* GetXoneCharacterFromActorInfo() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Xone|Ability Activation")
	EXoneAbilityActivationPolicy ActivationPolicy;
};
