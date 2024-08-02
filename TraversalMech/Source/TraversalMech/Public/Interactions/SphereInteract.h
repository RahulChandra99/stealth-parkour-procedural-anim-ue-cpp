// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "SphereInteract.generated.h"

/**
 * 
 */
UCLASS()
class TRAVERSALMECH_API USphereInteract : public USphereComponent
{
	GENERATED_BODY()

public:

	void OnGenerateOverlapEventsChanged() override;

	
	
};
