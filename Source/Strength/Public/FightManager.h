// Copyright FairgroundPanda Studios by Jordan J Craig

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FightManager.generated.h"

UCLASS()
class STRENGTH_API AFightManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightManager(); // Spawn new FightManager when fight starts, pass in fight variables such as location.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	void RunFight(); // Start the fight e.g. set camera, set level, mode, etc.
	TArray<AActor*> GetAvailableTargets(AActor* Character) const; // Get targets available to given player
	bool UseMoveOnTarget(AActor* Move, AActor* Target, AActor* Intigator); // Use FSkill on ACharacter target, return if hit
	bool AttemptToFlee(); // Attempt to flee the battle.	
	
};
