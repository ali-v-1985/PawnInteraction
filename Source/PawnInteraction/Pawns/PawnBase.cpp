// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
APawnBase::APawnBase()
{
     // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    // Setting UCapsuleComponent as the root component of the pawn.
    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
    RootComponent = CapsuleComponent;
    
    // Creating 
    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
    BaseMesh->SetupAttachment(RootComponent);
    
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Spring Arm"));
    SpringArmComponent->SetupAttachment(RootComponent);
    
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent->SetupAttachment(SpringArmComponent);
    
    PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Pawn Movement"));

}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
