// Copyright © 2026 TheRAVAGE (Akhil Mathew Mathew). All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "TagEnums.generated.h"

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

#pragma region Anim Montage

UENUM(BlueprintType)
enum class E_AnimMontageType : uint8
{
	E_None UMETA(DisplayName = "None"),
	E_IdleBreak UMETA(DisplayName = "Idle Break"),
	E_MAX UMETA(Hidden)
};
#pragma endregion Anim Montage

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