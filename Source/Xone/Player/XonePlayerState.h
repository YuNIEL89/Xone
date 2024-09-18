// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "XonePlayerState.generated.h"

class UXoneAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class XONE_API AXonePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AXonePlayerState();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	UXoneAbilitySystemComponent* AbilitySystemComponent;

};
