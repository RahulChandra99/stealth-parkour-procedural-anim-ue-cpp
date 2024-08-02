// Fill out your copyright notice in the Description page of Project Settings.


#include "ClimbingSystem/AnimInstance/CharacterAnimInstance.h"
#include "ClimbingSystem/CustomMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TraversalMech/TraversalMechCharacter.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	TraversalMechCharacter = Cast<ATraversalMechCharacter>(TryGetPawnOwner());
	if(TraversalMechCharacter)
	{
		CustomMovementComponent = TraversalMechCharacter->GetCustomMovementComponent();
	}
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(!TraversalMechCharacter || !CustomMovementComponent) return;
	GetGroundSpeed();
	GetAirSpeed();
	GetShouldMove();
	GetIsFalling();
}

void UCharacterAnimInstance::GetGroundSpeed()
{
	GroundSpeed = UKismetMathLibrary::VSizeXY(TraversalMechCharacter->GetVelocity());
}

void UCharacterAnimInstance::GetAirSpeed()
{
	AirSpeed = TraversalMechCharacter->GetVelocity().Z;
}

void UCharacterAnimInstance::GetShouldMove()
{
	bShouldMove = CustomMovementComponent->GetCurrentAcceleration().Size() > 0 && GroundSpeed > 0.5f && !bIsFalling;
}

void UCharacterAnimInstance::GetIsFalling()
{
	bIsFalling = CustomMovementComponent->IsFalling();
}
