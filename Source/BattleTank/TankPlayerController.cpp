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

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if(!GetControlledTank()) {return;}

	FVector HitLocation; // Out parameter
	UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
	if(GetSightRayHitLocation(HitLocation))
	{
		//Get world location of linetrace through crosshair
		//If hits landscape
		//tell controlled tank to aim at this point	
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hit_location) const
{
	//find dot, cast from camera to dot to see where it hits
	hit_location = FVector(1.0);
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}