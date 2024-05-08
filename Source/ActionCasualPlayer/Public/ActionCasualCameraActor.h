// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameFramework/SpringArmComponent.h"
#include "ActionCasualCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONCASUALPLAYER_API AActionCasualCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:

	AActionCasualCameraActor();

	UPROPERTY(EditAnywhere)
	USpringArmComponent* springArm;
	
	UPROPERTY(EditAnywhere)
	int limitX;

	UPROPERTY(EditAnywhere)
	float distanceBetween;
	
	UFUNCTION()
	void SetCameraLocation(FVector2D axis);
};
