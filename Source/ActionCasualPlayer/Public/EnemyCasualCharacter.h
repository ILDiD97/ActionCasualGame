// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCasualCharacter.h"
#include "EnemyCasualCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONCASUALPLAYER_API AEnemyCasualCharacter : public AActionCasualCharacter
{
	GENERATED_BODY()

public:
	
	virtual void CharMoveBidimensional(FVector2D axis) override;
	
	virtual void GetDamage(int damage) override;
};
