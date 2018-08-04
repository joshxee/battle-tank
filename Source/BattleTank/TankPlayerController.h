// Copyright Josh Cleland 2018

#pragma once

#include "CoreMinimal.h"
#include "BattleTank/Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	ATank * GetControlledTank() const;

private:	

	bool GetSightRayHitLocation(FVector& hit_location) const;
	/**
	 * \brief Finds what is at crosshair position. Move the tank barrel to mimic.
	 */
	void AimTowardsCrosshair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const;


	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333333;
};
