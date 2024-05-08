// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CasualCharacterInterface.h"
#include "GameFramework/Character.h"
#include "ActionCasualCameraActor.h"
#include "CasualCharacterInterface.h"
#include "ActionCasualCharacter.generated.h"

UCLASS()
class ACTIONCASUALPLAYER_API AActionCasualCharacter : public ACharacter, public ICasualCharacterInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AActionCasualCharacter();

	UPROPERTY(EditAnywhere, Category = "Stats")
	bool isDead;
	
	UPROPERTY(EditAnywhere, Category = "Stats")
	int health;

	UPROPERTY(EditAnywhere, Category = "Stats")
	float timeToShoot;

	UPROPERTY(VisibleAnywhere, Category = "Stats")
	float timerToShoot;

	UPROPERTY(EditAnywhere, Category = "Stats")
	float speed;
	
	UPROPERTY(EditAnywhere, Category = "State")
	bool isMoving;
	

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActionCasualCameraActor> cameraclass;
	
	UPROPERTY(VisibleAnywhere)
	AActionCasualCameraActor* cameraActor;

	UPROPERTY(EditAnywhere)
	FTransform cameraWorldPos;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void CharMoveBidimensional(FVector2D axis);

	virtual void GetDamage(int damage) override;

	UFUNCTION()
	virtual void FindEnemy();

	UFUNCTION()
	virtual void AutoDirection(FVector targetLocation);
};
