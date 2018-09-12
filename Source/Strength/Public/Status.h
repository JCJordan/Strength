// Copyright FairgroundPanda Studios by Jordan J Craig

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Status.generated.h"

/**
 * 
 */
UCLASS()
class STRENGTH_API UStatus : public UObject
{
	GENERATED_BODY()

private:

	int32 Level = 1;

	int32 MaxHealth = 1;
	int32 CurrentHealth = 1;

	int32 MaxMana = 1;
	int32 CurrentMana = 1;

	int32 Strength = 1;
	int32 Vitality = 1;
	int32 Defence = 1;
	int32 Speed = 1;
	int32 Agility = 1;
	int32 Accuracy = 1;
	int32 Luck = 1;

	int32 CurrentXP = 0;
	int32 XPToNextLevel = 1000;

public:

	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetLevel() const { return Level; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetMaxHealth() const { return MaxHealth; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetCurrentHealth() const { return CurrentHealth; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetMaxMana() const { return MaxMana; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetCurrentMana() const { return CurrentMana; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetStrength() const { return Strength; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetVitality() const { return Vitality; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetDefence() const { return Defence; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetSpeed() const { return Speed; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetAgility() const { return Agility; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetAccuracy() const { return Accuracy; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetLuck() const { return Luck; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetCurrentXP() const { return CurrentXP; };
	UFUNCTION(BlueprintPure, Category = "Status")
	int32 GetXPToNextLevel() const { return XPToNextLevel; };
	
	
};
