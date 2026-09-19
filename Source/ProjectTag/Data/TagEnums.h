// Copyright © 2026 TheRAVAGE (Akhil Mathew Mathew). All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "TagEnums.generated.h"

#pragma region Settings
UENUM(BlueprintType)
enum class E_QualityType : uint8
{
	E_None UMETA(Hidden),
	E_Low UMETA(DisplayName = "Low"),
	E_Medium UMETA(DisplayName = "Medium"),
	E_High UMETA(DisplayName = "High"),
	E_Epic UMETA(DisplayName = "Epic"),
	E_Ultra UMETA(DisplayName = "Ultra"),
	E_MAX UMETA(Hidden)
};
#pragma endregion Settings

#pragma region Input Device

UENUM(BlueprintType)
enum class E_InputDeviceType : uint8
{
	E_Unknown UMETA(DisplayName = "Unknown"),
	E_Keyboard UMETA(DisplayName = "Keyboard"),
	E_Gamepad UMETA(DisplayName = "Gamepad"),
	E_MAX UMETA(Hidden)
};
#pragma endregion Input Device

#pragma region Player Types

#pragma region Role Enums

UENUM(BlueprintType)
enum class ERoleType : uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Runner UMETA(DisplayName = "Runner"),
	E_Catcher UMETA(DisplayName = "Catcher"),
	E_MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ERoleInstigatorType : uint8
{
	E_None UMETA(DisplayName = "None"),
	E_GameMode UMETA(DisplayName = "GameMode"),
	E_Catcher UMETA(DisplayName = "Catcher"),
	E_MAX UMETA(Hidden)
};

#pragma endregion Role Enums

#pragma region Movement Enums

UENUM(BlueprintType)
enum class EMovementGait : uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Idle UMETA(DisplayName = "Idle"),
	E_Walking UMETA(DisplayName = "Walking"),
	E_Running UMETA(DisplayName = "Running"),
	E_Sprinting UMETA(DisplayName = "Sprinting"),
	E_Crouching UMETA(DisplayName = "Crouching"),
	E_Sliding UMETA(DisplayName = "Sliding"),
	E_Traversal UMETA(DisplayName = "Traversal"),
	E_Falliing UMETA(DisplayName = "Falling"),
	E_MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EMovementStance : uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Stand UMETA(DisplayName = "Stand"),
	E_Crouch UMETA(DisplayName = "Crouching"),
	E_Traversal UMETA(DisplayName = "Traversal"),
	E_MAX UMETA(Hidden)
};

#pragma endregion Movement Enums

#pragma region Traversable

UENUM(BlueprintType)
enum class E_TraversableType : uint8
{
	E_None UMETA(DisplayName = "None"),
	E_Hurdle UMETA(DisplayName = "Hurdle"),
	E_Vault UMETA(DisplayName = "Vault"),
	E_Mantle UMETA(DisplayName = "Mantle"),
	E_Climb UMETA(DisplayName = "Climb"),
	E_MAX UMETA(Hidden)
};

#pragma endregion Traversable

#pragma endregion Player Types