// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UFloatingPawnMovement;
class UCapsuleComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PAWNINTERACTION_API APawnBase : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    APawnBase();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
private:
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
    UFloatingPawnMovement* PawnMovement;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
    UStaticMeshComponent* BaseMesh;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
    USpringArmComponent* SpringArmComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
    UCameraComponent* CameraComponent;

};
