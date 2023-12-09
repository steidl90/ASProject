// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ASSingletonManager.generated.h"

/**
 * 
 */
UCLASS()
class ASPROJECT_API UASSingletonManager : public UObject
{
	GENERATED_BODY()
	
public:
	UASSingletonManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	void Initialize();

};
