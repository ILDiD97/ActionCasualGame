// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionCasualCharacter.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ActionCasualPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class ACTIONCASUALPLAYER_API AActionCasualPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Context")
	class UInputMappingContext* inputContext;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Horizontal")
	UInputAction* horizontalInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Vartical")
	UInputAction* verticalInput;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", DisplayName = "Input Move")
	UInputAction* moveInput;

	
	static void ShowInputMessage(FString Message);

	UPROPERTY(VisibleAnywhere)
	float input;

	UPROPERTY(VisibleAnywhere)
	FVector2D InputVector;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActionCasualCharacter> characterClass;

	UPROPERTY(VisibleAnywhere)
	AActionCasualCharacter* playedChar;
	
	UPROPERTY(EditAnywhere)
	FTransform worldPos;
	
protected:
	
	void OnMove(const FInputActionValue& Value);

	void StopMove(const FInputActionValue& Value);
	
	virtual void SetupInputComponent() override;

	
};
