// Copyright FairgroundPanda Studios by Jordan J Craig

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class STRENGTH_API UItem : public UObject
{
	GENERATED_BODY()

public:

	UItem();

private:

	int32 ID = 0;
	FString Name = "";
	FString Description = "";
	int32 Category = 0;

	bool LoadItemDatabase();

};

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FItemData()
		: ID(0)
		, Name("")
		, Description("")
		, Category("")
	{}

	/** The 'Name' column is the same as the XP Level */

	/** XP to get to the given level from the previous level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
		int32 ID;

	/** Extra HitPoints gained at this level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
		FString Category;

};