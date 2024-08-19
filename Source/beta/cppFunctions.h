// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Quat.h"
#include "Engine/World.h"

#include "cppFunctions.generated.h"


UCLASS(BlueprintType)
class BETA_API UcppFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    static bool SweepComponent(UPrimitiveComponent* ComponentToSweep, const FVector& Start, const FVector& End, const FQuat& Rot, TArray<FHitResult>& OutHits);
};
