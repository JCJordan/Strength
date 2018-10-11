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

bool UInventory::SortByField(FString Field, bool Ascending = true) {

	if (Field == "ID") { Items.Sort([Ascending](const UItem& LHS, const UItem& RHS) { return ! ((LHS.GetID() < RHS.GetID()) ^ Ascending); }); }
	else if (Field == "Name") { Items.Sort([Ascending](const UItem& LHS, const UItem& RHS) { return !((LHS.GetName() < RHS.GetName()) ^ Ascending); }); }
	else if (Field == "Category") { Items.Sort([Ascending](const UItem& LHS, const UItem& RHS) { return !((LHS.GetCategory() < RHS.GetCategory()) ^ Ascending); }); }
	else if (Field == "Usage") { Items.Sort([Ascending](const UItem& LHS, const UItem& RHS) { return !((LHS.GetUsage() < RHS.GetUsage()) ^ Ascending); }); }
	else { UE_LOG(LogTemp, Error, TEXT("Invalid field given for inventory sort!")); return false; }
	return true;
}

void UInventory::LoadDebugItems() {

	FItemFactory ItemFactory;
	
	for (int i = 0; i < 20; i++) {
		AddItemToInventory(ItemFactory.CreateNewItem(i % 4));
	}

}
