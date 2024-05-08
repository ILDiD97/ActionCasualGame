// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "TestPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONCASUALGAME_API ATestPlayerController : public APlayerController
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
	
	void OnHorizontal(const FInputActionValue& Value);

	void OnVertical(const FInputActionValue& Value);

	void OnMove(const FInputActionValue& Value);
	
	static void ShowInputMessage(FString Message);

	UPROPERTY(VisibleAnywhere)
	float input;

	UPROPERTY(VisibleAnywhere)
	FVector2D InputVector;
protected:
	
	virtual void SetupInputComponent() override;
};
