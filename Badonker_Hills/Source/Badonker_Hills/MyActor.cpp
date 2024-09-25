// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <iostream>
#include "EngineUtils.h"
#include "Engine/Engine.h"
#include "Engine/StaticMeshActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	for (TActorIterator<AStaticMeshActor> SMItr(GetWorld()); SMItr; ++SMItr)
	{
		AStaticMeshActor* SM = *SMItr;
		UE_LOG(LogTemp, Display, TEXT("Have StaticMesh %s"), *SM->GetActorGuid().ToString());

		FString uuid = *SM->GetActorGuid().ToString();

		if (uuid == "4BB738E142081FB00FDA3A909EDB285E") {
			UE_LOG(LogTemp, Display, TEXT("POPALSA!"));
			SM->SetMobility(EComponentMobility::Movable);
			FVector location = SM->GetActorLocation();
			location.Z += 1;
			SM->SetActorLocation(location);
		}
	}
//	for (TActorIterator<AActor> It(World); It; ++It)
//	{
		if (GEngine) {
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "!!My Actor Hello UE5");
		}
//	}

	std::cout << "Tick" << std::endl;
	Super::Tick(DeltaTime);

}

