// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PawnInteraction/Interfaces/Interactable.h"
#include "InteractableActor.generated.h"
/*
 The Interactable Actor which is implementing the IInteract interface.
 */
UCLASS(Blueprintable, Category="MyGame")
class PAWNINTERACTION_API AInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
