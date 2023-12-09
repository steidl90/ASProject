// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ASPlayerCharacter.generated.h"


class USkeletalMeshComponent;
class UCharacterMovementComponent;
class UCapsuleComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ASPROJECT_API AASPlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AASPlayerCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetMesh() const { return Mesh; }
	FORCEINLINE TObjectPtr<UCharacterMovementComponent> GetCharacterMovement() const { return CharacterMovement; }
	FORCEINLINE TObjectPtr<UCapsuleComponent> GetCapsuleComponent() const { return CapsuleComponent; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent>		Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCharacterMovementComponent>	CharacterMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent>			CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent>			CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent>			SpringArmComponent;

private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	float MaxArmLength;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	float MinArmLength;

private:
	void SetSpringArmLength(float InLength);
};
