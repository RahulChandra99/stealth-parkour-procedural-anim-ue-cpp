// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanics/DayNightCycle.h"

#include "Engine/DirectionalLight.h"
#include "Kismet/GameplayStatics.h"
#include "TraversalMech/DebugHelper.h"

ADayNightCycle::ADayNightCycle()
{
	PrimaryActorTick.bCanEverTick = true;


}

void ADayNightCycle::BeginPlay()
{
	Super::BeginPlay();

	FindDirectionalLight();

	
	OneDay = DayInMinutes * 60;
	OneHour = DayInMinutes / 24;
}



void ADayNightCycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Hour = Hour + (DeltaTime/OneHour);
	SunAngle = ((Hour / 6) * 90 ) + 90 ;

	if(FindDirectionalLight())
	{
		FindDirectionalLight()->SetActorRotation(FRotator(SunAngle,0,0));

	}
	
}


ADirectionalLight* ADayNightCycle::FindDirectionalLight()
{
	UWorld* World = GetWorld();
	if (World)
	{

		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsWithTag(World, FName("DirectionalLight"), FoundActors);

		for (AActor* Actor : FoundActors)
		{
			ADirectionalLight* DirectionalLight = Cast<ADirectionalLight>(Actor);
			if (DirectionalLight)
			{
				return DirectionalLight;
				break; 
			}
		}
	}
	return nullptr;
}
