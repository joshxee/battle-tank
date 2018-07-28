// Copyright Josh Cleland 2018

#include "TankPlayerController.h"
#include "BattleTank/Public/Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* tank = GetControlledTank();
	if (tank) {
		UE_LOG(LogTemp, Warning, TEXT("Possesing %s"), *tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank possessed"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}