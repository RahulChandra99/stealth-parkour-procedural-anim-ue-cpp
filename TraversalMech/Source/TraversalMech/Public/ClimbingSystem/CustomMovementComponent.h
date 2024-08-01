// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomMovementComponent.generated.h"

UENUM(BlueprintType)
namespace ECustomMovementMode
{
	enum Type
	{
		Move_Climb UMETA(DisplayName = "Climb Mode")
	};
}


/**
 * 
 */
UCLASS()
class TRAVERSALMECH_API UCustomMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

private:
	
#pragma region ClimbTraces

	TArray<FHitResult> DoCapsuleTraceMultiByObject(const FVector& Start, const FVector& End, bool bShowDebugShape = false, bool bDrawPersistantShapes = false);
	FHitResult DoLineTraceSingleByObject(const FVector& Start, const FVector& End, bool bShowDebugShape = false, bool bDrawPersistantShapes = false);
#pragma endregion 

#pragma region ClimbCore

bool TraceClimbableSurfaces();
FHitResult TraceFromEyeHeight(float TraceDistance, float TraceStartOffset = 0.f);
bool CanStartClimbing();

TArray<FHitResult> ClimbableSurfacesTracedResults;
	
#pragma endregion 
	
#pragma region ClimbVariables

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character Movement: Climbing", meta= (AllowPrivateAccess = true))
	TArray<TEnumAsByte<EObjectTypeQuery> > ClimbableSurfaceTraceTypes;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character Movement: Climbing", meta= (AllowPrivateAccess = true))
	float ClimbCapsuleTraceRadius = 50.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character Movement: Climbing", meta= (AllowPrivateAccess = true))
	float ClimbCapsuleTraceHalfHeight = 72.f;
	
#pragma endregion

public:

	void ToggleClimbing(bool bEnableClimb);
	bool IsClimbing() const;
};
