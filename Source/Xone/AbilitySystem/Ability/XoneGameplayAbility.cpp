// Fill out your copyright notice in the Description page of Project Settings.


#include "XoneGameplayAbility.h"
#include "XoneCharacter.h"

AXoneCharacter* UXoneGameplayAbility::GetXoneCharacterFromActorInfo() const
{
    return (CurrentActorInfo ? Cast<AXoneCharacter>(CurrentActorInfo->AvatarActor.Get()) : nullptr);
}
