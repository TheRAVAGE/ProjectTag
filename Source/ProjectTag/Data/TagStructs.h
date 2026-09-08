// Copyright © 2026 TheRAVAGE (Akhil Mathew Mathew). All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "TagEnums.h"
#include "Engine/DataTable.h" 

#include "TagStructs.generated.h"


class ITraversalInterface;
class ATraversableBase;
enum class EMovementGait : uint8;

#pragma region Player Settings
#pragma region Player Camera Settings

USTRUCT(BlueprintType)
struct FPlayerCameraSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Camera")
	bool bAllowCameraMovementWithSpeed{true};
};

#pragma endregion Player Camera Settings

#pragma region Player Control Settings

USTRUCT(BlueprintType)
struct FPlayerMovementControlSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Movement")
	bool bIsSprintToggle{false};
	
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
	bool bIsLookVerticalInverted{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Look")
	bool bIsLookHorizontalInverted{false};
};

#pragma endregion Player Control Settings
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
	USoundConcurrency* SoundConcurrency = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	USoundAttenuation* SoundAttenuation = nullptr;
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
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Gait Data")
	EMovementGait PreviousMovementGait{EMovementGait::E_Idle};
	
	//Stance Data
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Gait Data")
	EMovementStance MovementStance{EMovementStance::E_None};
	
	//Aim Offset Data
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Aim Offset Data")
	float AO_Yaw{0.f};
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Aim Offset Data")
	float AO_Pitch{0.f};
	
	//Foot Placement
	UPROPERTY(BlueprintReadOnly, Category="Animation Properties | Foot Placement")
	float FootPlacementAlpha{0.0f};
};

#pragma endregion Animation Properties

#pragma region Debug
USTRUCT(BlueprintType)
struct FDebugOptions
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugMessages{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Locomotion")
	bool bShowInputDeviceData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Locomotion")
	bool bShowControlsData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Locomotion")
	bool bShowCharacterLocomotionData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Locomotion")
	bool bShowCharacterLocomotionVisuals{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Slide")
	bool bShowCharacterSlideData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Transition")
	bool bShowTransitionBlendTimeData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Aim")
	bool bShowAimData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Trajectory")
	bool bShowMotionWarpingVisuals{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Trajectory")
	bool bShowTrajectoryVisuals{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Traversal")
	bool bShowTraversalData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Traversal | Points")
	bool bShowTraversalPoints{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Traversal | Points")
	bool bShowTraversalTraces{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	float DebugArrowLength{100.f};
	
};
#pragma endregion Debug

#pragma region Traversable Data

USTRUCT(BlueprintType)
struct FTraversalCheckResults
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
	E_TraversableType TraversableType{E_TraversableType::E_None};
	
	UPROPERTY(BlueprintReadWrite)
	float DistanceToTraversalObject{0.0f};
	
	UPROPERTY(BlueprintReadWrite)
	bool bHasFrontLedge{false};
	
	UPROPERTY(BlueprintReadWrite)
	FVector FrontLedgeLocation{FVector::ZeroVector};
	
	UPROPERTY(BlueprintReadWrite)
	FVector FrontLedgeNormal{FVector::ZeroVector};
	
	UPROPERTY(BlueprintReadWrite)
	bool bHasBackLedge{false};
	
	UPROPERTY(BlueprintReadWrite)
	FVector BackLedgeLocation{FVector::ZeroVector};
	
	UPROPERTY(BlueprintReadWrite)
	FVector BackLedgeNormal{FVector::ZeroVector};
	
	UPROPERTY(BlueprintReadWrite)
	bool bHasBackFloor{false};
	
	UPROPERTY(BlueprintReadWrite)
	FVector BackFloorLocation{FVector::ZeroVector};
	
	UPROPERTY(BlueprintReadWrite)
	float ObstacleHeight{0.0f};
	
	UPROPERTY(BlueprintReadWrite)
	float ObstacleDepth{0.0f};
	
	UPROPERTY(BlueprintReadWrite)
	float BackLedgeHeight{0.0f};
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<AActor> TraversalActor{nullptr};
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UAnimMontage> ChosenMontage;
	
	UPROPERTY(BlueprintReadWrite)
	float StartTime{0.0f};
	
	UPROPERTY(BlueprintReadWrite)
	float PlayRate{0.0f};
};

#pragma endregion Traversable Data