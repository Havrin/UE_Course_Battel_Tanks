// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

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
	
	void AimAt(FVector WorldSpaceAim);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000; // 500/s

	double LastFireTime = 0;

	void MoveBarrelTowards(FVector AimDirection);
};
