// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "XoneMovementComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComponentTickSignature, float, DeltaTime);

/**
 * 
 */
UCLASS()
class XONE_API UXoneMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
	// Called every frame to simulate ticking behavior
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	// Delegate that can be bound to in the ability
	FOnComponentTickSignature OnComponentTick;

};
