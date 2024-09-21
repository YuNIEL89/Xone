// Fill out your copyright notice in the Description page of Project Settings.


#include "XoneGameplayAbility.h"
#include "Character/XoneCharacter.h"
#include "Character/XoneMovementComponent.h"

AXoneCharacter* UXoneGameplayAbility::GetXoneCharacterFromActorInfo() const
{
    return (CurrentActorInfo ? Cast<AXoneCharacter>(CurrentActorInfo->AvatarActor.Get()) : nullptr);
}

void UXoneGameplayAbility::EnableAbilityTick()
{
    if (!GetXoneCharacterFromActorInfo())
    {
        // XoneCharacter is null
        return;
    }

    UXoneMovementComponent* MovementComponent = Cast<UXoneMovementComponent>(GetXoneCharacterFromActorInfo()->GetCharacterMovement());
    if (MovementComponent)
    {
        // Bind the movement component's tick delegate to the ability's custom tick
        MovementComponent->OnComponentTick.AddDynamic(this, &UXoneGameplayAbility::OnAbilityTick);
    }
}

void UXoneGameplayAbility::DisableAbilityTick()
{
    if (!GetXoneCharacterFromActorInfo())
    {
        // XoneCharacter is null
        return;
    }

    UXoneMovementComponent* MovementComponent = Cast<UXoneMovementComponent>(GetXoneCharacterFromActorInfo()->GetCharacterMovement());

    if (MovementComponent)
    {
        // Unbind the movement component's tick delegate to stop the tick function
        MovementComponent->OnComponentTick.RemoveDynamic(this, &UXoneGameplayAbility::OnAbilityTick);
    }
}
