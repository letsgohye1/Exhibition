// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFloor.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class USkeletalMeshComponent;


UCLASS()
class EXHIBITION_API AMyFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


    /** 회전의 기준이 되는 루트 */
    UPROPERTY(VisibleAnywhere)
    USceneComponent* Root;

    /** 바닥 / 플랫폼 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
    UStaticMeshComponent* StaticMesh;

    /** 위에 올라가는 캐릭터 */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
    USkeletalMeshComponent* SkeletalMesh;

    /** 서버 기준 시작 시간 */
    UPROPERTY(Replicated)
    float StartServerTime;

    /** 시작 회전 */
    FRotator StartRootRotation;

public:
    /** 초당 회전 각도 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    float RotationSpeed = 90.f;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
