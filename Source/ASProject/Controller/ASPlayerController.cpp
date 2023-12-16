// Fill out your copyright notice in the Description page of Project Settings.


#include "ASPlayerController.h"

#include "InputMappingContext.h"
#include "EnhancedActionKeyMapping.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"

AASPlayerController::AASPlayerController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC(TEXT("/Game/Input/DA_Player_InputMappingContext.DA_Player_InputMappingContext"));
	if (true == IMC.Succeeded())
	{
		IMCPlayerInput = IMC.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> Move(TEXT("/Game/Input/IA_MOVEMENT.IA_MOVEMENT"));
	if (true == Move.Succeeded())
	{
		MoveAction = Move.Object;
	}
}

void AASPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMCPlayerInput, 0);
	}
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (true == IsValid(EnhancedInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &AASPlayerController::Test);
	}
}

void AASPlayerController::Test(const FInputActionInstance& InInstance)
{
	UE_LOG(LogTemp, Error, TEXT("asd"));
}
