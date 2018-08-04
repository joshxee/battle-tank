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
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;

	void GetSightRayHitLocation(FVector* hit_location) const;
	/**
	 * \brief Finds what is at crosshair position. Move the tank barrel to mimic.
	 */
	void AimTowardsCrosshair();

	virtual void Tick(float DeltaSeconds) override;
};
