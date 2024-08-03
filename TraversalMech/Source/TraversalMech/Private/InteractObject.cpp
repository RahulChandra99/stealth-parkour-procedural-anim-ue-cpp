// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractObject.h"

#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "TraversalMech/DebugHelper.h"
#include "TraversalMech/TraversalMechCharacter.h"

AInteractObject::AInteractObject()
{
	PrimaryActorTick.bCanEverTick = false;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	ObjectMesh->SetupAttachment(RootComponent);
	SetRootComponent(ObjectMesh);

	ObjectMesh->SetCollisionResponseToAllChannels(ECR_Block);
	ObjectMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	ObjectMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
	AreaSphere->SetupAttachment(RootComponent);

	AreaSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AreaSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &AInteractObject::OnOverlapBegin);
	AreaSphere->OnComponentEndOverlap.AddDynamic(this, &AInteractObject::OnOverlapEnd);

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractWidget"));
	InteractWidget->SetupAttachment(RootComponent);
}

void AInteractObject::BeginPlay()
{
	Super::BeginPlay();
	
	if(InteractWidget)
	{
		InteractWidget->SetVisibility(false);
	}
	
}

void AInteractObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AInteractObject::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		ATraversalMechCharacter* TraversalMechCharacter = Cast<ATraversalMechCharacter>(OtherActor);
		if (TraversalMechCharacter && InteractWidget)
		{
			InteractWidget->SetVisibility(true);
			TraversalMechCharacter->bCanPickTorch = true;
		}
	}
}

void AInteractObject::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Debug::Print("Working 1");
	if (OtherActor)
	{
		Debug::Print("Working 2");

		ATraversalMechCharacter* TraversalMechCharacter = Cast<ATraversalMechCharacter>(OtherActor);
		if (TraversalMechCharacter && InteractWidget)
		{
			Debug::Print("Working 3");

			InteractWidget->SetVisibility(false);
			TraversalMechCharacter->bCanPickTorch = false;
		}
	}
}




