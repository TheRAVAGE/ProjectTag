// Copyright © 2026 TheRAVAGE (Akhil Mathew Mathew). All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "TagEnums.h"
#include "Engine/DataTable.h" 

#include "TagStructs.generated.h"

enum class EMovementGait : uint8;

#pragma region Player Settings

USTRUCT(BlueprintType)
struct FPlayerMovementControlSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Movement")
	bool bIsRunToggle{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Movement")
	bool bIsWalkToggle{false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Movement")
	bool bIsCrouchToggle{false};
};

USTRUCT(BlueprintType)
struct FPlayerLookControlSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Look")
	float LookSensitivity{1.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Look")
	bool bIsLookInverted{false};
};

#pragma endregion Player Settings

#pragma region Movement Values

USTRUCT(BlueprintType)
struct FMovementConfig
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MaxWalkSpeed = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MaxAcceleration = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float BrakingDeceleration = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float BrakingFrictionFactor = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float BrakingFriction = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bUseSeperateBrakingFriction = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float Volume = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float AttenuationRadius = 0.f;
};

USTRUCT(BlueprintType)
struct FGaitMoveConfig : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	EMovementGait MovementGait {EMovementGait::E_None};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FMovementConfig MovementConfig;
	
};

#pragma endregion Movement Values

#pragma region Animation Properties

USTRUCT(BlueprintType)
struct FAnimationProperties
{
	GENERATED_BODY()
	//Speed Data
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Speed Data")
	FVector Velocity {FVector::ZeroVector};
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Speed Data")
	float Speed {0.f};
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Speed Data")
	FVector Acceleration{FVector::ZeroVector};
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Speed Data")
	bool bIsAccelerating{false};
	
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Speed Data")
	bool bIsFalling{false};
	
	//Gait Data
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Gait Data")
	EMovementGait MovementGait{EMovementGait::E_Idle};
	//Stance Data
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Gait Data")
	EMovementStance MovementStance{EMovementStance::E_None};
	
	//Foot Placement
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Foot Placement")
	float FootPlacementAlpha{0.0f};
};

#pragma endregion Movement Values

#pragma region Debug
USTRUCT(BlueprintType)
struct FDebugOptions
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugMessages{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowCharacterLocomotionData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowCharacterLocomotionVisuals{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	float DebugArrowLength{0.35f};
	
};
#pragma endregion Debug