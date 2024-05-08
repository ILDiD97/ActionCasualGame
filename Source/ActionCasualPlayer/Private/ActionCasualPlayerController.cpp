// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCasualPlayerController.h"

#include "GameFramework/CharacterMovementComponent.h"

void AActionCasualPlayerController::ShowInputMessage(FString Message)
{
	GEngine->AddOnScreenDebugMessage(FMath::Rand(), 0.2f, FColor::Magenta, Message);
}


void AActionCasualPlayerController::OnMove(const FInputActionValue& Value)
{
	if(!playedChar->isDead)
	{
		InputVector = Value.Get<FVector2D>();
		playedChar->CharMoveBidimensional(InputVector);
		playedChar->isMoving = true;
	}
}

void AActionCasualPlayerController::StopMove(const FInputActionValue& Value)
{
	playedChar->isMoving = false;
}

void AActionCasualPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(inputContext, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	
	Input->BindAction(moveInput, ETriggerEvent::Triggered, this, &AActionCasualPlayerController::OnMove);
	Input->BindAction(moveInput, ETriggerEvent::Completed, this, &AActionCasualPlayerController::StopMove);
	
	UWorld* world = GetWorld();
	if(world)
	{
		FActorSpawnParameters SpawnParameters;
		playedChar = Cast<AActionCasualCharacter>(world->SpawnActor(characterClass, &worldPos, SpawnParameters));
		playedChar->PossessedBy(this);
	}
}
