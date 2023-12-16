// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ASPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputActionInstance;

/**
 * 
 */
UCLASS()
class ASPROJECT_API AASPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AASPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY()
	UInputMappingContext*	IMCPlayerInput;

	UPROPERTY()
	TObjectPtr<UInputAction>			MoveAction;

public:
	UFUNCTION()
	void Test(const FInputActionInstance& InInstance);

};
