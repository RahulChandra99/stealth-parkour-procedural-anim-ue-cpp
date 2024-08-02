// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereComp.h"


#include "Components/WidgetComponent.h"
#include "TraversalMech/DebugHelper.h"
#include "TraversalMech/TraversalMechCharacter.h"

USphereComp::USphereComp()
{
	// Initialize member variables
	Owner = nullptr;
	Character = nullptr;
	InteractWidgetComponent = nullptr; // Initialize InteractWidgetComponent here
}

void USphereComp::BeginPlay()
{
	Super::BeginPlay();

	// Initialize pointers
	Owner = GetOwner();
	if (Owner)
	{
		
		InteractWidgetComponent = Owner->FindComponentByClass<UWidgetComponent>();
	}
}

void USphereComp::ToggleTorchInteract(bool CanPickupTorch)
{

	if (InteractWidgetComponent)
	{
		InteractWidgetComponent->SetVisibility(CanPickupTorch);
	}
	if (MyActorReference)
	{
		Debug::Print("Hello");
		
		ATraversalMechCharacter* MyClass = Cast<ATraversalMechCharacter>(MyActorReference);
		MyClass->bCanPickTorch = CanPickupTorch;
	}
}


