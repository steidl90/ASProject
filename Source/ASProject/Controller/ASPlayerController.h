// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ASPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ASPROJECT_API AASPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AASPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};
