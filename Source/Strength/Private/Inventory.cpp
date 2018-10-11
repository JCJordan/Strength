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

bool UInventory::RemoveItemFromInventory(UItem* Item) {
	if (!Item) { return false; }
	Items.Remove(Item);
	return true;
}

bool UInventory::RemoveItemFromInventoryByIndex(int32 Index) {
	if (!GetItemAtIndex(Index)) { return false; }
	Items.RemoveAt(Index);
	return true;
}

void UInventory::LoadDebugItems() {

	FItemFactory ItemFactory;
	
	for (int i = 0; i < 3; i++) {
		AddItemToInventory(ItemFactory.CreateNewItem(0));
	}

}
