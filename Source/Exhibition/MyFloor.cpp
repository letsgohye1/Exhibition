// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFloor.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/GameStateBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMyFloor::AMyFloor()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(Root);

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Root);

    SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    SkeletalMesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AMyFloor::BeginPlay()
{
    Super::BeginPlay();

    StartRootRotation = Root->GetRelativeRotation();

    if (HasAuthority())
    {
        if (AGameStateBase* GS = GetWorld()->GetGameState())
        {
            StartServerTime = GS->GetServerWorldTimeSeconds();
        }
    }
}

// Called every frame
void AMyFloor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AGameStateBase* GS = GetWorld()->GetGameState();
    if (!GS) return;

    const float ServerTime = GS->GetServerWorldTimeSeconds();
    const float Elapsed = ServerTime - StartServerTime;

    FRotator NewRotation = StartRootRotation;
    NewRotation.Yaw += Elapsed * RotationSpeed;

    Root->SetRelativeRotation(NewRotation);
}

void AMyFloor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(AMyFloor, StartServerTime);
}


