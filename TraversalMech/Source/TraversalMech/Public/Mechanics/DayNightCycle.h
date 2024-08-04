// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DayNightCycle.generated.h"

UCLASS()
class TRAVERSALMECH_API ADayNightCycle : public AActor
{
	GENERATED_BODY()
private:
	float Hour;
	float OneHour;
	float OneDay;
	float DayInMinutes;
	float SunAngle;
	
public:	
	ADayNightCycle();
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

	class ADirectionalLight* FindDirectionalLight();

public:	

};
