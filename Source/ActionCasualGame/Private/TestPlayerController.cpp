// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerController.h"

void ATestPlayerController::OnHorizontal(const FInputActionValue& Value)
{
	input = Value.Get<float>();
}

void ATestPlayerController::OnVertical(const FInputActionValue& Value)
{
	input = Value.Get<float>();
}

void ATestPlayerController::OnMove(const FInputActionValue& Value)
{
	InputVector = Value.Get<FVector2D>();
}

void ATestPlayerController::ShowInputMessage(FString Message)
{
}

void ATestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(inputContext, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	
	//Input->BindAction(horizontalInput, ETriggerEvent::Ongoing, this,&AActionCasualPlayerController::OnHorizontal);
	//Input->BindAction(verticalInput, ETriggerEvent::Ongoing, this,&AActionCasualPlayerController::OnVertical);
	Input->BindAction(moveInput, ETriggerEvent::Ongoing, this,&ATestPlayerController::OnMove);
}
