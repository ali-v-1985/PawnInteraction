// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerState.h"
#include "PawnInteraction/Actors/InteractableActor.h"

void ABasePlayerState::StartInteract(AInteractableActor* InteractableActor)
{
    CurrentInteract = InteractableActor;
}

void ABasePlayerState::StopInteract(AInteractableActor* InteractableActor)
{
    if(InteractableActor == CurrentInteract)
    {
        CurrentInteract = nullptr;
    }
}

AInteractableActor* ABasePlayerState::GetCurrentInteract()
{
    return CurrentInteract;
}

AInteractableActor* ABasePlayerState::PickUpInteractable()
{
    if(CurrentInteract)
    {
        PickedUpInteractable.Add(CurrentInteract);
    }
    return CurrentInteract;
}

int32 ABasePlayerState::PickedUpIteractableCount() const
{
    return PickedUpInteractable.Num();
}
