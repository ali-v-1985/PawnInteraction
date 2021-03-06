// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Interactable.generated.h"

/**
 *  Interactable interface to be implementated by different actors in case necessary/
 */
UINTERFACE()
class PAWNINTERACTION_API UInteractable : public UInterface
{
	GENERATED_BODY()
	
};

class IInteractable
{
    GENERATED_BODY()

public:
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Interactable")
    void Interact();
};
