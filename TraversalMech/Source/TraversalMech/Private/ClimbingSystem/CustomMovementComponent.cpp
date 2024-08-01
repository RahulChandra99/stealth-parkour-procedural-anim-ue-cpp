// Fill out your copyright notice in the Description page of Project Settings.


#include "ClimbingSystem/CustomMovementComponent.h"
#include "TraversalMech/TraversalMechCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TraversalMech/DebugHelper.h"

TArray<FHitResult> UCustomMovementComponent::DoCapsuleTraceMultiByObject(const FVector& Start, const FVector& End,
                                                                         bool bShowDebugShape, bool bDrawPersistantShapes)
{
	TArray<FHitResult> OutCapsuleTraceHitResults;
	EDrawDebugTrace::Type DebugTraceType = EDrawDebugTrace::None;

	if(bShowDebugShape)
	{
		DebugTraceType = EDrawDebugTrace::ForOneFrame;
		if(bDrawPersistantShapes)
		{
			DebugTraceType = EDrawDebugTrace::Persistent;
		}
	}
	UKismetSystemLibrary::CapsuleTraceMultiForObjects(
		this,
		Start,
		End,
		ClimbCapsuleTraceRadius,
		ClimbCapsuleTraceHalfHeight,
		ClimbableSurfaceTraceTypes,
		false,
		TArray<AActor*>(),
		DebugTraceType,
		OutCapsuleTraceHitResults,
		false
	);

	return OutCapsuleTraceHitResults;
	
}

FHitResult UCustomMovementComponent::DoLineTraceSingleByObject(const FVector& Start, const FVector& End,
	bool bShowDebugShape, bool bDrawPersistantShapes )
{
	FHitResult OutHit;
	EDrawDebugTrace::Type DebugTraceType = EDrawDebugTrace::None;

	if(bShowDebugShape)
	{
		DebugTraceType = EDrawDebugTrace::ForOneFrame;
		if(bDrawPersistantShapes)
		{
			DebugTraceType = EDrawDebugTrace::Persistent;
		}
	}
	UKismetSystemLibrary::LineTraceSingleForObjects(
		this,
		Start,
		End,
		ClimbableSurfaceTraceTypes,
		false,
		TArray<AActor*>(),
		DebugTraceType,
		OutHit,
		false
	);
	return OutHit;
}

bool UCustomMovementComponent::TraceClimbableSurfaces()
{
	const FVector StartOffset = UpdatedComponent->GetForwardVector() * 30.f;
	const FVector Start = UpdatedComponent->GetComponentLocation() + StartOffset;
	const FVector End = Start + UpdatedComponent->GetForwardVector();
	ClimbableSurfacesTracedResults = DoCapsuleTraceMultiByObject(Start,End,true,true);

	return !ClimbableSurfacesTracedResults.IsEmpty();
}

FHitResult UCustomMovementComponent::TraceFromEyeHeight(float TraceDistance, float TraceStartOffset)
{
	const FVector ComponentLocation = UpdatedComponent->GetComponentLocation();
	const FVector EyeHeightOffset = UpdatedComponent->GetUpVector() * (CharacterOwner->BaseEyeHeight + TraceStartOffset);
	const FVector Start = ComponentLocation + EyeHeightOffset;
	const FVector End = Start + UpdatedComponent->GetForwardVector() * TraceDistance;

	return DoLineTraceSingleByObject(Start,End,true,true);
}



bool UCustomMovementComponent::CanStartClimbing()
{
	if(IsFalling()) return false;
	if(!TraceClimbableSurfaces()) return false;
	if(!TraceFromEyeHeight(100.f).bBlockingHit) return false;

	return true;
}

void UCustomMovementComponent::ToggleClimbing(bool bEnableClimb)
{
	if(bEnableClimb)
	{
		if(CanStartClimbing())
		{
			Debug::Print(TEXT("Can Start Climbing"));
		}
		else
		{
			Debug::Print(TEXT("Cannot Start Climbing"));
		}
	}
	else
	{
		//stop clinbing
	}
}

bool UCustomMovementComponent::IsClimbing() const
{
	return MovementMode == MOVE_Custom && CustomMovementMode == ECustomMovementMode::Move_Climb;
}


