// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BasePlayerState.generated.h"

class AInteractableActor;
/**
 * 
 */
UCLASS()
class PAWNINTERACTION_API ABasePlayerState : public APlayerState
{
	GENERATED_BODY()
    
public:
    
    UFUNCTION(BlueprintCallable)
    void StartInteract(AInteractableActor* InteractableActor);

    UFUNCTION(BlueprintCallable)
    void StopInteract(AInteractableActor* InteractableActor);
    
    UFUNCTION(BlueprintCallable)
    AInteractableActor* GetCurrentInteract();

    UFUNCTION(BlueprintCallable)
    AInteractableActor* PickUpInteractable();

    UFUNCTION(BlueprintCallable)
    int32 PickedUpIteractableCount() const;

private:
    AInteractableActor* CurrentInteract;
    
    TArray<AInteractableActor*> PickedUpInteractable;
};
