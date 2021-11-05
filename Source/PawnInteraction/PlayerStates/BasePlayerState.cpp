// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerState.h"
#include "PawnInteraction/Actors/InteractableActor.h"

/**
 * When player start interacting with an AInteractableActor this function is being called so the current interact would be stored.
 */
void ABasePlayerState::StartInteract(AInteractableActor* InteractableActor)
{
    CurrentInteract = InteractableActor;
}

/**
 * When player stop interacting with an AInteractableActor this function is being called so the current interact would be emptied.
 */
void ABasePlayerState::StopInteract(AInteractableActor* InteractableActor)
{
    // Check if the stop interact is being called for current interact
    if(InteractableActor == CurrentInteract)
    {
        CurrentInteract = nullptr;
    }
}

/**
 * Get current interact,
 */
AInteractableActor* ABasePlayerState::GetCurrentInteract()
{
    return CurrentInteract;
}

/**
 * When player pickup an interactable actor this function stores that interactable in case player need to drop it or use it.
 */
AInteractableActor* ABasePlayerState::PickUpInteractable()
{
    //Check to be sure player is in interaction with an actor right now
    if(CurrentInteract)
    {
        PickedUpInteractable.Add(CurrentInteract);
    }
    return CurrentInteract;
}

/**
 * Returning the number of pickedup interactable.
 */
int32 ABasePlayerState::PickedUpIteractableCount() const
{
    return PickedUpInteractable.Num();
}
