// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "SphereComp.generated.h"

/**
 * 
 */

class ATraversalMechCharacter;
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))

class TRAVERSALMECH_API USphereComp : public USphereComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	ACharacter* MyActorReference;
public:
	USphereComp();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void ToggleTorchInteract(bool CanPickupTorch);

private:
	AActor* Owner;
	class ATraversalMechCharacter* Character;
	class UWidgetComponent* InteractWidgetComponent; // Declare the member variable here
};
