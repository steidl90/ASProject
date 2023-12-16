// Fill out your copyright notice in the Description page of Project Settings.


#include "ASPlayerCharacter.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Animation/AnimInstance.h"

// Sets default values
AASPlayerCharacter::AASPlayerCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;

	{
		CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
		CapsuleComponent->InitCapsuleSize(34.0f, 88.0f);
		CapsuleComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

		CapsuleComponent->CanCharacterStepUpOn = ECB_No;
		CapsuleComponent->SetShouldUpdatePhysicsVolume(true);
		CapsuleComponent->SetCanEverAffectNavigation(false);
		CapsuleComponent->bDynamicObstacle = true;
		RootComponent = CapsuleComponent;
	}

	{
		CharacterMovement = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("MovementComp"));
		CharacterMovement->UpdatedComponent = RootComponent;
	}

	{
		Mesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
		Mesh->AlwaysLoadOnClient = true;
		Mesh->AlwaysLoadOnServer = true;
		Mesh->bOwnerNoSee = false;
		Mesh->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
		Mesh->bCastDynamicShadow = true;
		Mesh->bAffectDynamicIndirectLighting = true;
		Mesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Mesh->SetupAttachment(RootComponent);
		Mesh->SetCollisionProfileName(TEXT("CharacterMesh"));
		Mesh->SetGenerateOverlapEvents(false);
		Mesh->SetCanEverAffectNavigation(false);
		Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));
		//Mesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

		static ConstructorHelpers::FObjectFinder<USkeletalMesh> MashAsset(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny"));
		if (true == MashAsset.Succeeded())
		{
			Mesh->SetSkeletalMesh(MashAsset.Object);
		}

		static ConstructorHelpers::FObjectFinder<UClass> Anim(TEXT("/Game/PlayerCharacter/Animation/ABP_PlayerCharacter.ABP_PlayerCharacter_C"));
		if (true == Anim.Succeeded())
		{
			Mesh->SetAnimInstanceClass(Anim.Object);
		}
	}

	{
		SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
		SpringArmComponent->SetupAttachment(RootComponent);
		SpringArmComponent->SetWorldRotation(FRotator(-40.0f, 0.0f, 0.0f));
		SpringArmComponent->TargetArmLength = 700.0f;

		CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
		CameraComponent->SetupAttachment(SpringArmComponent);
	}
}

// Called when the game starts or when spawned
void AASPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AASPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AASPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
}

void AASPlayerCharacter::SetSpringArmLength(float InLength)
{
	if (true == IsValid(SpringArmComponent))
	{
		SpringArmComponent->TargetArmLength = FMath::Clamp(SpringArmComponent->TargetArmLength + InLength, MinArmLength, MaxArmLength);
	}
}
