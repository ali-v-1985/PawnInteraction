// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IntractableGameModeBase.generated.h"


class APawnBase;

UCLASS()
class PAWNINTERACTION_API AIntractableGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


protected:
    
    virtual void BeginPlay() override;
	
};
