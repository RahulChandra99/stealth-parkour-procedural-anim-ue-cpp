// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

UCLASS()
class TRAVERSALMECH_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	APickUp();
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Pickup Properties")
	USkeletalMeshComponent* PickUpMesh;

	
public:	

};
