// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Flower.generated.h"

UCLASS()
class EXHIBITION_API AFlower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// ?? 꽃 Instanced Static Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower")
	TArray<UInstancedStaticMeshComponent*> FlowerISMs;

	// ?? 구슬(StaticMeshComponent) 저장
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower")
	TArray<UStaticMeshComponent*> LightOrbs;

	// ?? 구슬용 메쉬 (블루프린트에서 지정)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flower")	
	UStaticMesh* LightOrbMesh;

	// 생성 개수
	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 MinFlowerCount = 2;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 MaxFlowerCount = 5;


	// 꽃 피우기
	UFUNCTION(BlueprintCallable)
	void SpawnRandomFlowers();

	// 라이트 피우기
	UFUNCTION(BlueprintCallable)
	void SpawnRandomLights();

};
