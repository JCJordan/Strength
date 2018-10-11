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
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemToInventory(UItem* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItemFromInventory(UItem* Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItemFromInventoryByIndex(int32 Index);
	void LoadDebugItems();

private:

	TArray<UItem*> Items;	
	
};
