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
	
	static void PrintFunctionName(const FString& Message, const bool bLog = true)
	{
		const FString String = FString::Printf(TEXT("Called by : %s"), *Message);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Purple, String);
		}
		if (bLog)
		{
			LogMsg(String);
		}
	}
	static void OneSlot_FunctionName(const UWorld* InWorld, const FString& Message, const float Duration = 5.f,const bool bLog = true)
	{
		const FString String = FString::Printf(TEXT("Called by : %s"), *Message);
		if (!InWorld) {return;}
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s"), *String),
			true, 
			bLog,
			FColor::Purple, 
			Duration, 
			FName(String)
		);
		if (bLog)
		{
			LogMsg(String);
		}
	}
	
#pragma endregion	Essential Logs
	
#pragma region One Slot Debugs
	
	static void OneSlot_String(const UWorld* InWorld, const FName Title, const FString Message, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
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
		if (!InWorld) {return;}
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
		if (!InWorld) {return;}
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
		if (!InWorld) {return;}
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
		if (!InWorld) {return;}
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
		if (!InWorld) {return;}
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
	
	static void OneSlot_Rotator(const UWorld* InWorld, const FName Title, const FRotator Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
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
	
#pragma region One Slot Debugs Multiplayer
	
	static void OneSlotM_String(const UWorld* InWorld, const FName Title, const FString Message, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
		FName NewTitle = FName(FString::Printf(TEXT("%d - %s"),InWorld->GetUniqueID(),*Title.ToString()));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *Message),
			true, 
			bLog,
			Color, 
			Duration, 
			NewTitle
		);
	}
	
	static void OneSlotM_Bool(const UWorld* InWorld, const FName Title, const bool Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
		FName NewTitle = FName(FString::Printf(TEXT("%d - %s"),InWorld->GetUniqueID(),*Title.ToString()));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *FString(Value? "true": "false")),
			true, 
			bLog,
			Color, 
			Duration, 
			NewTitle
		);
	}
	
	static void OneSlotM_Float(const UWorld* InWorld, const FName Title, const float Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
		FName NewTitle = FName(FString::Printf(TEXT("%d - %s"),InWorld->GetUniqueID(),*Title.ToString()));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %f"), *Title.ToString(), Value),
			true, 
			bLog,
			Color, 
			Duration, 
			NewTitle
		);
	}
	
	static void OneSlotM_Int(const UWorld* InWorld, const FName Title, const int32 Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
		FName NewTitle = FName(FString::Printf(TEXT("%d - %s"),InWorld->GetUniqueID(),*Title.ToString()));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %d"), *Title.ToString(), Value),
			true, 
			bLog,
			Color, 
			Duration, 
			NewTitle
		);
	}
	
	template<typename TEnum>
	static void OneSlotM_Enum(const UWorld* InWorld, const FName Title, const TEnum Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
		static_assert(TIsEnum<TEnum>::Value, "OneSlot_Enum requires an enum type");
		const UEnum* EnumPtr = StaticEnum<TEnum>();
		check(EnumPtr);

		FName NewTitle = FName(FString::Printf(TEXT("%d - %s"),InWorld->GetUniqueID(),*Title.ToString()));
		const FString EnumString = EnumPtr->GetNameStringByValue(static_cast<int64>(Value));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *EnumString),
			true, 
			bLog,
			Color, 
			Duration, 
			NewTitle
		);
	}
	
	static void OneSlotM_Vector(const UWorld* InWorld, const FName Title, const FVector Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
		FName NewTitle = FName(FString::Printf(TEXT("%d - %s"),InWorld->GetUniqueID(),*Title.ToString()));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *Value.ToCompactString()),
			true, 
			bLog,
			Color, 
			Duration, 
			NewTitle
		);
	}
	
	static void OneSlotM_Rotator(const UWorld* InWorld, const FName Title, const FRotator Value, const float Duration = -1.f, const FColor Color = FColor::MakeRandomColor(), const bool bLog = true)
	{
		if (!InWorld) {return;}
		FName NewTitle = FName(FString::Printf(TEXT("%d - %s"),InWorld->GetUniqueID(),*Title.ToString()));
		UKismetSystemLibrary::PrintString(
			InWorld, 
			FString::Printf(TEXT("%s: %s"), *Title.ToString(), *Value.ToCompactString()),
			true, 
			bLog,
			Color, 
			Duration, 
			NewTitle
		);
	}
	
#pragma endregion One Slot Debugs Multiplayer
	
#pragma region Draw Debugs
	
	static void DrawLine(const UWorld* InWorld, const FVector& LineStart, const FVector& LineEnd, const FColor& Color = FColor::MakeRandomColor(), const bool bOneShot = false, const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0)
	{
		if (!InWorld) {return;}
		float ActualLifeTime = LifeTime;
		if (!bPersistentLines)
		{
			ActualLifeTime = (LifeTime<1.f) ?  5.f : LifeTime;
		}
		DrawDebugLine( InWorld, 
			LineStart, 
			LineEnd, 
			Color, 
			bPersistentLines, 
			bOneShot? 0.f: ActualLifeTime, 
			DepthPriority, 
			Thickness
		);
	}
	
	static void DrawSphere(const UWorld* InWorld, const FVector& Center, const float Radius = 10.f, const FColor& Color = FColor::MakeRandomColor(), const bool bOneShot = false, const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0, const int32 Segments = 12)
	{
		if (!InWorld) {return;}
		float ActualLifeTime = LifeTime;
		if (!bPersistentLines)
		{
			ActualLifeTime = (LifeTime<1.f) ?  5.f : LifeTime;
		}
		DrawDebugSphere(
			InWorld,
			Center,
			Radius,
			Segments,
			Color,
			bPersistentLines,
			bOneShot? 0.f: ActualLifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawBox(const UWorld* InWorld, const FVector& Center, const FVector& Extent, const FColor& Color = FColor::MakeRandomColor(), const bool bOneShot = false, const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0)
	{
		if (!InWorld) {return;}
		float ActualLifeTime = LifeTime;
		if (!bPersistentLines)
		{
			ActualLifeTime = (LifeTime<1.f) ?  5.f : LifeTime;
		}
		DrawDebugBox(
			InWorld,
			Center,
			Extent,
			Color,
			bPersistentLines,
			bOneShot? 0.f: ActualLifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawCapsule(const UWorld* InWorld, const FVector& Center, const float HalfHeight, const float Radius, const FQuat& Rotation = FQuat::Identity, const FColor& Color = FColor::MakeRandomColor(), const bool bOneShot = false, const bool bPersistentLines = false, const float LifeTime = -1.f, const float Thickness = 1.f, const int32 DepthPriority = 0)
	{
		if (!InWorld) {return;}
		float ActualLifeTime = LifeTime;
		if (!bPersistentLines)
		{
			ActualLifeTime = (LifeTime<1.f) ?  5.f : LifeTime;
		}
		DrawDebugCapsule(
			InWorld,
			Center,
			HalfHeight,
			Radius,
			Rotation,
			Color,
			bPersistentLines,
			bOneShot? 0.f: ActualLifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawArrow(const UWorld* InWorld, const FVector& LineStart, const FVector& LineEnd, const float Thickness = 1.f,const FColor& Color = FColor::MakeRandomColor(), const bool bOneShot = false, const bool bPersistentLines = false, const float LifeTime = -1.f,const float ArrowSize = 1.f, const int32 DepthPriority = 0)
	{
		if (!InWorld) {return;}
		float ActualLifeTime = LifeTime;
		if (!bPersistentLines)
		{
			ActualLifeTime = (LifeTime<1.f) ?  5.f : LifeTime;
		}
		DrawDebugDirectionalArrow(
			InWorld,
			LineStart,
			LineEnd,
			ArrowSize,
			Color,
			bPersistentLines,
			bOneShot? 0.f: ActualLifeTime,
			DepthPriority,
			Thickness
		);
	}
	
	static void DrawString(const UWorld* InWorld, const FVector& TextLocation, const FString& Text, const float FontScale = 1.f, const FColor& Color = FColor::MakeRandomColor(), const bool bOneShot = false, const bool bPersistentLines = false, const float LifeTime = -1.f, const int32 DepthPriority = 0)
	{
		if (!InWorld) {return;}
		float ActualLifeTime = LifeTime;
		if (!bPersistentLines)
		{
			ActualLifeTime = (LifeTime<1.f) ?  5.f : LifeTime;
		}
		DrawDebugString(
			InWorld,
			TextLocation,
			Text,
			nullptr,
			Color,
			bOneShot? 0.f: ActualLifeTime,
			bPersistentLines,
			FontScale
		);
	}
	static void DrawPoint(const UWorld* InWorld, const FVector& Location, const float Size = 5.f, const FColor& Color = FColor::MakeRandomColor(), const bool bOneShot = false, const bool bPersistentLines = false, const float LifeTime = -1.f, const int32 DepthPriority = 0)
	{
		if (!InWorld) {return;}
		float ActualLifeTime = LifeTime;
		if (!bPersistentLines)
		{
			ActualLifeTime = (LifeTime<1.f) ?  5.f : LifeTime;
		}
		DrawDebugPoint(
			InWorld,
			Location, 
			Size, 
			Color, 
			bPersistentLines, 
			bOneShot? 0.f: ActualLifeTime, 
			DepthPriority
			);
	}
#pragma endregion Draw Debugs
		
#pragma region Character Referenced Debug
	static void DrawStringFromCharacter(const UWorld* InWorld, const ACharacter* Character,const FString Value, const FColor Color, const float OffSet)
	{
		if (!Character)	{return;}
		if (!InWorld) {return;}
		
		const float HalfHeight = Character->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		const FVector Location = Character->GetActorLocation() + FVector{0.f,0.f,HalfHeight+OffSet};
		Debug::DrawString(InWorld, Location, Value, 0.75f, Color, true);
	}

	static void DrawArrowFromCharacter(const UWorld* InWorld, const APlayerCharacter* Character,const FString Name,const FVector Value, const float MaxValue, const FColor Color)
	{
		if (!Character)	{return;}
		if (!InWorld) {return;}
		
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
	
		Debug::DrawString(InWorld, EndLocation, Name, 0.75f, Color, true);
		Debug::DrawArrow(InWorld, StartLocation, EndLocation,3.f,Color, true);
	}
	
#pragma endregion Character Referenced Debug
}
