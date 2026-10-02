// Copyright © 2026 TheRAVAGE (Akhil Mathew Mathew). All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "TagEnums.h"
#include "Engine/DataTable.h" 

#include "TagStructs.generated.h"


class UDataAsset_AbilitySet;
class UGameplayAbilityBase;
class ITraversalInterface;
class ATraversableBase;
enum class EMovementGait : uint8;

#pragma region Player Settings

#pragma region Player Graphics
USTRUCT(BlueprintType)
struct FPlayerGraphicsLevels
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Graphics")
	int32 OverallQuality{4};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Graphics")
	int32 MaterialQuality{4};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Graphics")
	int32 ParticleQuality{4};
	
	int32 MatchOverallQuality(const int32 newLevel)
	{
		if (newLevel > OverallQuality)
		{
			OverallQuality = newLevel;
		}
		return FMath::Clamp(newLevel,0,OverallQuality);
	}
	void OverallQualityChanged()
	{
		//Add all the new audio settings here
		ParticleQuality = FMath::Clamp(ParticleQuality,0,OverallQuality);
		MaterialQuality = FMath::Clamp(MaterialQuality,0,OverallQuality);
	}
};

#pragma endregion Player Graphics

#pragma region Player Audio
USTRUCT(BlueprintType)
struct FPlayerAudioLevels
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Camera")
	float MasterAudio{1.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Camera")
	float ParticleEffectAudio{1.0f};
	
	float MatchMasterAudio(const float newAudioLevel)
	{
		if (newAudioLevel > MasterAudio)
		{
			MasterAudio = newAudioLevel;
		}
		return FMath::Clamp(newAudioLevel,0.0f,MasterAudio);
	}
	void MasterAudioChanged()
	{
		//Add all the new audio settings here
		ParticleEffectAudio = FMath::Clamp(ParticleEffectAudio,0.0f,MasterAudio);
	}
};

#pragma endregion Player Audio

#pragma region Player Gameplay Settings

USTRUCT(BlueprintType)
struct FPlayerGameplaySettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Camera")
	bool bAllowCameraMovementWithSpeed{true};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Catch Marker")
	FLinearColor CatchMarker_Can{FLinearColor::Yellow};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings | Catch Marker")
	FLinearColor CatchMarker_Cannot{FLinearColor::White};
};

#pragma endregion Player Gameplay Settings

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

#pragma region Player Types

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

#pragma region Role Specifics

USTRUCT(BlueprintType)
struct FRoleValues
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Role Data | Movement")
	float MovementSpeedMultiplier{0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Role Data | Traversal")
	float TraversalPlayrateMultiplier{0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Role Data | Traversal")
	float ReturnControlTimer{0.0f};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Role Data | GameplayAbilities")
	TObjectPtr<UDataAsset_AbilitySet> AbilitySet{nullptr};
	
};

USTRUCT(BlueprintType)
struct FRoleAssignment
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	ERoleType CurrentRole{ERoleType::E_None};
	
	UPROPERTY(BlueprintReadWrite)
	bool bShouldStartTimer{true};
};

#pragma endregion Role Specifics

#pragma endregion Player Types

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Traversal")
	bool bShowTraversalMontageData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Traversal | Points")
	bool bShowTraversalPoints{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Traversal | Points")
	bool bShowTraversalTraces{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Role")
	bool bShowRoleData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Role")
	bool bShowRoleVisuals{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Role")
	bool bShowRoleTimelineMessages{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Catcher")
	bool bShowCatchCheckTraces{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Catcher")
	bool bShowCatchCheckVisuals{false};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug | Catcher")
	bool bShowCatchCheckData{false};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	float DebugArrowLength{100.f};
	
};
#pragma endregion Debug