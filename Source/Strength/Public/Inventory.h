// Copyright FairgroundPanda Studios by Jordan J Craig

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory.generated.h"

class UItem;

/**
 * 
 */
UCLASS()
class STRENGTH_API UInventory : public UObject
{
	GENERATED_BODY()
	
public:

	UInventory();

	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<UItem*> GetAllItems() const { return Items; };
	UFUNCTION(BlueprintPure, Category = "Inventory")
	UItem* GetItemAtIndex(int32 Index) const;
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool AddItemToInventory(UItem* Item);
	void LoadDebugItems();

private:

	TArray<UItem*> Items;	
	
};
