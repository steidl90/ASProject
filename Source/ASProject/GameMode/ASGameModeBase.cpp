// Fill out your copyright notice in the Description page of Project Settings.


#include "ASGameModeBase.h"

#include "ASProject/Character/ASPlayerCharacter.h"
#include "ASProject/Controller/ASPlayerController.h"

AASGameModeBase::AASGameModeBase(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	DefaultPawnClass = AASPlayerCharacter::StaticClass();
	PlayerControllerClass = AASPlayerController::StaticClass();
}
