// Copyright FairgroundPanda Studios by Jordan J Craig

#include "Inventory.h"
#include "Item.h"

UInventory::UInventory() {

	LoadDebugItems();

}

UItem* UInventory::GetItemAtIndex(int32 Index) const {

	if ((Index < 0) || (Index >= Items.Num())) { return nullptr; }
	return Items[Index];

}

bool UInventory::AddItemToInventory(UItem* Item) {

	if (!Item) { return false; }
	// TODO Potentially check for Inventory limit
	Items.Add(Item);
	return true;
}

void UInventory::LoadDebugItems() {


}
