// Fill out your copyright notice in the Description page of Project Settings.


#include "XoneMovementComponent.h"

void UXoneMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Broadcast the delegate for anyone who is bound to it (like an ability)
    OnComponentTick.Broadcast(DeltaTime);
}
