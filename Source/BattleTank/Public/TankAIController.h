// Copyright Josh Cleland 2018

#pragma once

#include "CoreMinimal.h"
#include "BattleTank/Public/Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;
	
	ATank * GetPlayerTank() const;
};
