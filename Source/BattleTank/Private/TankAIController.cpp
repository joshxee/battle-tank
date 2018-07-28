// Copyright Josh Cleland 2018

#include "TankAIController.h"
#include "BattleTank/TankPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "BattleTank/Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* tank = GetPlayerTank();
	if (tank) {
		UE_LOG(LogTemp, Warning, TEXT("Player possessing %s"), *tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank possessed"));
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	ATankPlayerController* player = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
	if (!player) { return nullptr; }
	return player->GetControlledTank();
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}