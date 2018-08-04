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
	if(GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		//Get world location of linetrace through crosshair
		//If hits landscape
		//tell controlled tank to aim at this point	
	}

}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		WorldLocation, 
		WorldDirection);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hit_location) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY + CrossHairYLocation);

	// De-project the sceen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("World Direction: %s"), *LookDirection.ToString());
	}
	
	// line trace along that look direction and see what we hit (up to max range)
	hit_location = FVector(1.0);
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}