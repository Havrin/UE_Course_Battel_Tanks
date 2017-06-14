// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"




void UTankTurret::Rotate(float RelativeSpeed)
{
	// move the barrel the right amoun this frame
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0.f, NewRotation, 0.f));
}