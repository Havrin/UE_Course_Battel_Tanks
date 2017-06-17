// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

		if (!ensure(AimingComponent)) { return; }
		// Aim towards player and fire
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		AimingComponent->Fire(); // TODO Don't fire every frame
	}
}