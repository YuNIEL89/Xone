// Fill out your copyright notice in the Description page of Project Settings.


#include "XoneAbilitySet.h"
#include "GameplayAbilitySpecHandle.h"
#include "AbilitySystem/XoneAbilitySystemComponent.h"
#include "AbilitySystem/Ability/XoneGameplayAbility.h"

void FXoneAbilitySet_GrantedHandles::AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& Handle)
{
	if (Handle.IsValid())
	{
		AbilitySpecHandles.Add(Handle);
	}
}

void UXoneAbilitySet::GiveToAbilitySystem(UXoneAbilitySystemComponent* InASC, FXoneAbilitySet_GrantedHandles* OutGrantedHandles, UObject* SourceObject) const
{
	check(InASC);

	if (!InASC->IsOwnerActorAuthoritative())
	{
		// Must be authoritative to give or take ability sets.
		return;
	}

	for (int32 AbilityIndex = 0; AbilityIndex < GrantedGameplayAbilities.Num(); ++AbilityIndex)
	{
		const FXoneAbilitySet_GameplayAbility& AbilityToGrant = GrantedGameplayAbilities[AbilityIndex];

		if (!IsValid(AbilityToGrant.Ability))
		{
			UE_LOG(LogTemp, Error, TEXT("GrantedGameplayAbilities[%d] on ability set [%s] is not valid."), AbilityIndex, *GetNameSafe(this));
			continue;
		}

		UXoneGameplayAbility* AbilityCDO = AbilityToGrant.Ability->GetDefaultObject<UXoneGameplayAbility>();

		FGameplayAbilitySpec AbilitySpec(AbilityCDO, AbilityToGrant.AbilityLevel);
		AbilitySpec.SourceObject = SourceObject;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilityToGrant.InputTag);

		const FGameplayAbilitySpecHandle AbilitySpecHandle = InASC->GiveAbility(AbilitySpec);

		if (OutGrantedHandles)
		{
			OutGrantedHandles->AddAbilitySpecHandle(AbilitySpecHandle);
		}
	}
}
