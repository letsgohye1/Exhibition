// Fill out your copyright notice in the Description page of Project Settings.


#include "Flower.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/GameStateBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AFlower::AFlower()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));


	// ISM 10개 예시
	for (int32 i = 0; i < 10; ++i)
	{
		FString Name = FString::Printf(TEXT("FlowerISM_%d"), i);

		UInstancedStaticMeshComponent* ISM =
			CreateDefaultSubobject<UInstancedStaticMeshComponent>(*Name);

		ISM->SetupAttachment(RootComponent);
		ISM->SetMobility(EComponentMobility::Movable);
		ISM->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		ISM->SetCastShadow(false);

		FlowerISMs.Add(ISM);
	}

}

// Called when the game starts or when spawned
void AFlower::BeginPlay()
{
	Super::BeginPlay();
	SpawnRandomFlowers();
	SpawnRandomLights();
}

// Called every frame
void AFlower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlower::SpawnRandomFlowers()
{
	if (FlowerISMs.Num() == 0) return;

	const int32 PickCount = FMath::Min(5, FlowerISMs.Num());

	// 인덱스 셔플
	TArray<int32> Indices;
	for (int32 i = 0; i < FlowerISMs.Num(); ++i)
	{
		Indices.Add(i);
	}

	for (int32 i = Indices.Num() - 1; i > 0; --i)
	{
		int32 SwapIndex = FMath::RandRange(0, i);
		Indices.Swap(i, SwapIndex);
	}

	// ?? 선택된 ISM들
	for (int32 i = 0; i < PickCount; ++i)
	{
		UInstancedStaticMeshComponent* ISM = FlowerISMs[Indices[i]];
		if (!ISM) continue;

		// ?? 이 꽃 종류에서 몇 송이 피울지
		int32 PerFlowerCount = FMath::RandRange(1, 3);

		for (int32 j = 0; j < PerFlowerCount; ++j)
		{
			// 위치
			FVector Location(
				FMath::RandRange(-40.f, 40.f),
				FMath::RandRange(-40.f, 40.f),
				0.f
			);

			// 회전
			FRotator Rotation(0.f, FMath::RandRange(0.f, 360.f), 0.f);

			// 스케일
			float ScaleValue = FMath::RandRange(0.8f, 1.2f);
			FVector Scale(ScaleValue);

			FTransform Transform(Rotation, Location, Scale);

			// ? 여기서 실제로 꽃 추가
			ISM->AddInstance(Transform);
		}
	}
}

void AFlower::SpawnRandomLights()
{
	if (!LightOrbMesh) return; // 블루프린트에서 할당

	const int32 OrbCount = 2;

	for (int32 i = 0; i < OrbCount; ++i)
	{
		// 새 구슬 컴포넌트 생성
		UStaticMeshComponent* Orb = NewObject<UStaticMeshComponent>(this);
		Orb->RegisterComponent();
		Orb->SetStaticMesh(LightOrbMesh);

		// 랜덤 위치
		FVector Location(
			FMath::RandRange(-40.f, 40.f),
			FMath::RandRange(-40.f, 40.f),
			FMath::RandRange(20.f, 60.f)
		);

		Orb->SetWorldLocation(GetActorLocation() + Location);
		Orb->SetWorldRotation(FRotator::ZeroRotator);
		Orb->SetWorldScale3D(FVector(0.5f));

		Orb->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		// Root에 붙이기
		Orb->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

		// 배열에 담기 (필요하면)
		LightOrbs.Add(Orb);
	}
}

