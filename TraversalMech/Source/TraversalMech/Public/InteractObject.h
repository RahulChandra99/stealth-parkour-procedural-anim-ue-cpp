// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractObject.generated.h"

UENUM(BlueprintType)
enum class EInteractState : uint8
{
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),
	
	EWS_MAX UMETA(DisplayName = "DefaultMAX")
};



UCLASS()
class TRAVERSALMECH_API AInteractObject : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractObject();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult

	);

	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

private:

	UPROPERTY(EditAnywhere, Category="Interact Object Properties")
	UStaticMeshComponent* ObjectMesh;

	UPROPERTY(VisibleAnywhere, Category="Interact Object Properties")
	class USphereComponent* AreaSphere;

	UPROPERTY(VisibleAnywhere, Category="Interact Object Properties")
	EInteractState InteractState;

	UPROPERTY(VisibleAnywhere, Category="Interact Object Properties")
	class UWidgetComponent* InteractWidget;

protected:
	virtual void BeginPlay() override;

public:	

};
