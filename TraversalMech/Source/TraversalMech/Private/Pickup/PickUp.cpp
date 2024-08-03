// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup/PickUp.h"

APickUp::APickUp()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

