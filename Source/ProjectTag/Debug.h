// Copyright © 2026 TheRAVAGE (Akhil Mathew Mathew). All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProjectTag/Characters/PlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

namespace Debug
{
#pragma region Essential Logs
	
	static void LogMsg(const FString& Message)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
	}
	
	static void PrintMsg(const FString& Message, const bool bLog = true)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Purple, Message);
		}
		if (bLog)
		{
			LogMsg(Message);
		}
	}
	
	static void PrintMsg(const FString& Message, float Duration = 10.f, FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Duration, Color, Message);
		}
		if (bLog)
		{
			LogMsg(Message);
		}
	}
	
#pragma endregion	Essential Logs
	
#pragma region One Slot Debugs
	
	static void OneSlot_String(const UWorld* InWorld, const FName Title, const FString Message, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *Message),
			true, 
			bLog,
			Color, 
			Duration, 
			Title
		);
	}
	
	static void OneSlot_Bool(const UWorld* InWorld, const FName Title, const bool Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *FString(Value? "true": "false")),
			true, 
			bLog,
			Color, 
			Duration, 
			Title
		);
	}
	
	static void OneSlot_Float(const UWorld* InWorld, const FName Title, const float Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %f"), *Title.ToString(), Value),
			true, 
			bLog,
			Color, 
			Duration, 
			Title
		);
	}
	
	static void OneSlot_Int(const UWorld* InWorld, const FName Title, const int32 Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %d"), *Title.ToString(), Value),
			true, 
			bLog,
			Color, 
			Duration, 
			Title
		);
	}
	
	template<typename TEnum>
	static void OneSlot_Enum(const UWorld* InWorld, const FName Title, const TEnum Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		static_assert(TIsEnum<TEnum>::Value, "OneSlot_Enum requires an enum type");
		const UEnum* EnumPtr = StaticEnum<TEnum>();
		check(EnumPtr);

		const FString EnumString = EnumPtr->GetNameStringByValue(static_cast<int64>(Value));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *EnumString),
			true, 
			bLog,
			Color, 
			Duration, 
			Title
		);
	}
	
	static void OneSlot_Vector(const UWorld* InWorld, const FName Title, const FVector Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *Value.ToCompactString()),
			true, 
			bLog,
			Color, 
			Duration, 
			Title
		);
	}
	
#pragma endregion One Slot Debugs
	
#pragma region Draw Debugs
	
	static void DrawLine(const UWorld* InWorld, const FVector& LineStart, const FVector& LineEnd, const FColor& Color = FColor::MakeRandomColor(), const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0)
	{
		DrawDebugLine( InWorld, 
	LineStart, 
	LineEnd, 
	Color, 
	bPersistentLines, 
	LifeTime, 
	DepthPriority, 
	Thickness
	);
	}
	
	static void DrawSphere(const UWorld* InWorld, const FVector& Center, const float Radius = 10.f, const FColor& Color = FColor::MakeRandomColor(), const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0, const int32 Segments = 12)
	{
		DrawDebugSphere(
			InWorld,
			Center,
			Radius,
			Segments,
			Color,
			bPersistentLines,
			LifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawBox(const UWorld* InWorld, const FVector& Center, const FVector& Extent, const FColor& Color = FColor::MakeRandomColor(), const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0)
	{
		DrawDebugBox(
			InWorld,
			Center,
			Extent,
			Color,
			bPersistentLines,
			LifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawCapsule(const UWorld* InWorld, const FVector& Center, const float HalfHeight, const float Radius, const FQuat& Rotation = FQuat::Identity, const FColor& Color = FColor::MakeRandomColor(), const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0)
	{
		DrawDebugCapsule(
			InWorld,
			Center,
			HalfHeight,
			Radius,
			Rotation,
			Color,
			bPersistentLines,
			LifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawArrow(const UWorld* InWorld, const FVector& LineStart, const FVector& LineEnd, const float Thickness = 1.f,const FColor& Color = FColor::MakeRandomColor(), const bool bPersistentLines = false, const float LifeTime = -1.f,const float ArrowSize = 1.f, const int32 DepthPriority = 0)
	{
		DrawDebugDirectionalArrow(
			InWorld,
			LineStart,
			LineEnd,
			ArrowSize,
			Color,
			bPersistentLines,
			LifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawString(const UWorld* InWorld, const FVector& TextLocation, const FString& Text, const float FontScale = 1.f, const FColor& Color = FColor::MakeRandomColor(), const bool bPersistentLines = false, const float LifeTime = 0.f, const int32 DepthPriority = 0)
	{
		DrawDebugString(
			InWorld,
			TextLocation,
			Text,
			nullptr,
			Color,
			LifeTime,
			bPersistentLines,
			FontScale
		);
	}
#pragma endregion Draw Debugs
	
#pragma region Character Referenced Debug
	static void DrawStringFromCharacter(const UWorld* InWorld, const ACharacter* Character,const FString Value, const FColor Color, const float OffSet)
	{
		if (!Character)	{return;}
		const float HalfHeight = Character->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		const FVector Location = Character->GetActorLocation() + FVector{0.f,0.f,HalfHeight+OffSet};
		Debug::DrawString(InWorld, Location, Value, 0.75f, Color);
	}

	static void DrawArrowFromCharacter(const UWorld* InWorld, const APlayerCharacter* Character,const FString Name,const FVector Value, const float MaxValue, const FColor Color)
	{
		if (!Character)	{return;}
		const float HalfHeight = Character->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		const FVector StartLocation = Character->GetActorLocation() - FVector{0.f,0.f,HalfHeight};
		const float ValueMagnitude = Value.Size();

		const float ArrowLength = FMath::GetMappedRangeValueClamped(
			FVector2D(0.f, MaxValue),
			FVector2D(0.f, Character->DebugOptions.DebugArrowLength),
			ValueMagnitude
		);

		const FVector Direction = Value.GetSafeNormal();
		const FVector EndLocation =
			StartLocation + Direction * ArrowLength;
	
		Debug::DrawString(InWorld, EndLocation, Name, 0.75f, Color);
		Debug::DrawArrow(InWorld, StartLocation, EndLocation,3.f,Color);
	}
	
#pragma endregion Character Referenced Debug
}
