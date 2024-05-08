// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CasualGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONCASUALPLAYER_API ACasualGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	virtual void StartPlay() override;
};
