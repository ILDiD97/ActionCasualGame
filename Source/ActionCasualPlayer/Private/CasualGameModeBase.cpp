// Fill out your copyright notice in the Description page of Project Settings.


#include "CasualGameModeBase.h"

#include "ActionCasualPlayerController.h"
#include "Kismet/GameplayStatics.h"

void ACasualGameModeBase::StartPlay()
{
	Super::StartPlay();

	
	Cast<AActionCasualPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0))->playedChar->isDead = false;
}
