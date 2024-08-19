// Fill out your copyright notice in the Description page of Project Settings.


#include "cppFunctions.h"
#include <DocObj.h>
#include "Engine/GameEngine.h"
#include "Engine/World.h"
#include "Math/Quat.h"
#include "CollisionQueryParams.h"
#include "Components/PrimitiveComponent.h"

bool UcppFunctions::SweepComponent(UPrimitiveComponent* ComponentToSweep, const FVector& Start, const FVector& End, const FQuat& Rot, TArray<FHitResult>& OutHits)
{
    UWorld* CurrentWorld = ComponentToSweep->GetOwner()->GetWorld();
    if (!CurrentWorld) {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Didn't find World"));
        return false;
    }

    FComponentQueryParams ComponentQueryParams;

    //ComponentQueryParams.AddIgnoredActor(ActorToIgnore);
    bool bHit = CurrentWorld->ComponentSweepMulti(
        OutHits,
        ComponentToSweep,
        Start,
        End,
        Rot,
        ComponentQueryParams
    );

    return bHit;
}