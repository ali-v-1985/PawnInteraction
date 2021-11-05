// Fill out your copyright notice in the Description page of Project Settings.


#include "IntractableGameModeBase.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

void AIntractableGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    SpawnActors();
}

/**
 * Spawning Actors in the world
 */
void AIntractableGameModeBase::SpawnActors()
{
    // Check if SpawnableActorTypes are configured
    if(!SpawnableActorTypes.IsValidIndex(0))
    {
        UE_LOG(LogTemp, Warning, TEXT("No SpawnableActorTypes"))
        return;
    }
    for (auto Idx = 0; Idx < NumberOfActors; Idx++) {
        // Defining the boundry of the spawing for this iteration
        auto MapLowBound = MapSize * -1 * (Idx + 1);
        auto MapHighBound = MapSize * (Idx + 1);
        
        //Calculating the X, Y, Z coordinates of the spawning for this iteration
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        auto PosX = PlayerPawn->GetActorLocation().X + FMath::RandRange(MapLowBound, MapHighBound);
        auto PosY = PlayerPawn->GetActorLocation().Y + FMath::RandRange(MapLowBound, MapHighBound);
        auto PosZ = PlayerPawn->GetActorLocation().Z;
        
        // Preparing FVector and FRotator for SpawnLocation and SpawnRotation
        FVector SpawnLocation(PosX, PosY, PosZ);
        FRotator SpawnRotation(0.0f);
        
        //Spawning Actors using the types which has been set through the SpawnableActorTypes
        auto SpawnedActor = GetWorld()->SpawnActor<AActor>(SpawnableActorTypes[Idx % SpawnableActorTypes.Num()],
                                                                      SpawnLocation, SpawnRotation);
    }
}
