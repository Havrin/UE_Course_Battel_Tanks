// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		auto ControlledTank = Cast<ATank>(GetPawn());

		// Aim towards player and fire
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//ControlledTank->Fire(); // TODO Don't fire every frame
	}
}