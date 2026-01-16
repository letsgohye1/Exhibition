// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCameraManager.h"
#include "MyCharacter.h"

AMyPlayerCameraManager::AMyPlayerCameraManager()
{

}

void AMyPlayerCameraManager::UpdateCamera(float DeltaTime)
{
	Super::UpdateCamera(DeltaTime);

	AMyCharacter* Pawn = Cast<AMyCharacter>(GetOwningPlayerController()->GetPawn());

	if (Pawn)
	{
		//float TargetFOV = Pawn->bIsIronSight ? IronsightFOV : NormalFOV;
		//float CurrentFOV = FMath::FInterpTo(GetFOVAngle(), TargetFOV, DeltaTime, ZoomSpeed);
		//SetFOV(CurrentFOV);
	}
}
