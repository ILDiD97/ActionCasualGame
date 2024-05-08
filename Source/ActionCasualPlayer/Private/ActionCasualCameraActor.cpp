// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCasualCameraActor.h"

#include "VectorUtil.h"
#include "Camera/CameraComponent.h"

AActionCasualCameraActor::AActionCasualCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	springArm->SetupAttachment(RootComponent);
	GetCameraComponent()->SetupAttachment(springArm);
}

void AActionCasualCameraActor::SetCameraLocation(FVector2D axis)
{
	float limit = limitX * distanceBetween;
	float clampX = FMath::Clamp(axis.X, 0, limit);
	FVector location(clampX, GetActorLocation().Y, GetActorLocation().Z);
	SetActorLocation(location);
}
