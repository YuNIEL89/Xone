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

	UFUNCTION(BlueprintCallable, Category = "Xone|Ability")
	AXoneCharacter* GetXoneCharacterFromActorInfo() const;

	// Custom tick function bound to the movement component delegate
	UFUNCTION(BlueprintImplementableEvent, Category = "Xone|Ability")
	void OnAbilityTick(float DeltaTime);

	// Enable ticking by binding to the movement component's tick delegate
	UFUNCTION(BlueprintCallable, Category = "Xone|Ability")
	void EnableAbilityTick();

	// Disable ticking by unbinding from the movement component's tick delegate
	UFUNCTION(BlueprintCallable, Category = "Xone|Ability")
	void DisableAbilityTick();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Xone|Ability Activation")
	EXoneAbilityActivationPolicy ActivationPolicy;
};
