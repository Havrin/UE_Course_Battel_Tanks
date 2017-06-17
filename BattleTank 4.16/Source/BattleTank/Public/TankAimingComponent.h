// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;

// Enum for Aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Ready
};

// Holds Barrels Properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	// TODO add SetTurrentReference
	
	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

private:

	void MoveBarrelTowards(FVector AimDirection);
};
