// Copyright FairgroundPanda Studios by Jordan J Craig

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Skill.generated.h"

/**
 * 
 */
UCLASS()
class STRENGTH_API USkill : public UObject
{
	GENERATED_BODY()
		
};

USTRUCT(BlueprintType)
struct FSkillData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FSkillData()
		: ID(0)
		, Name("")
		, Description ("")
		, BaseDamage (0)
	{}

	/** The 'Name' column is the same as the XP Level */

	/** XP to get to the given level from the previous level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	int32 ID;

	/** Extra HitPoints gained at this level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	int32 BaseDamage;

};