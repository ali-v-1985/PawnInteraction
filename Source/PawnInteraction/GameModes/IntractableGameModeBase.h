// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IntractableGameModeBase.generated.h"

/*
 The base game mode to be used as the game's game mode.
 */
UCLASS()
class PAWNINTERACTION_API AIntractableGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


protected:
    
    virtual void BeginPlay() override;
    
private:
    
    UPROPERTY(EditAnywhere, Category="Spawning", meta=(AllowPrivateAccess="true"))
    int32 NumberOfActors = 10;
    
    UPROPERTY(EditAnywhere, Category="Spawning", meta=(AllowPrivateAccess="true"))
    float MapSize = 200;
    
    UPROPERTY(EditAnywhere, Category="Spawning", meta=(AllowPrivateAccess="true"))
    TArray<TSubclassOf<AActor>> SpawnableActorTypes;
    
    void SpawnActors();
	
};
