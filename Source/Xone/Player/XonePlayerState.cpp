// Fill out your copyright notice in the Description page of Project Settings.


#include "XonePlayerState.h"
#include "AbilitySystem/XoneAbilitySystemComponent.h"

AXonePlayerState::AXonePlayerState()
{
	// Create ability system component, set it to be replicated
	AbilitySystemComponent = CreateDefaultSubobject<UXoneAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// Mixed mode means we only are replicated the GEs to ourself, not the GEs to simulated proxies.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Set PlayerState's NetUpdateFrequency to the same as the Character,
	// default is very low and will introduce perceived lag in the ability system.
	// 100 may be way too high for a shipping game, you will need to adjust it to your needs.
	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AXonePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
