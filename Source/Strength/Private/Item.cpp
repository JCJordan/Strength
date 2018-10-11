// Copyright FairgroundPanda Studios by Jordan J Craig

#include "Item.h"
#include "UObject/ConstructorHelpers.h"
#include "UObject/UObjectGlobals.h"

UItem::UItem() {

}

void UItem::Initialise(FItemData* ItemData) {

	this->ID = ItemData->ID;
	this->Name = ItemData->Name;
	this->Description = ItemData->Description;
	this->Category = ItemData->Category;
	this->Usage = ItemData->Usage;

}

FItemFactory::FItemFactory() {

	LoadItemDatabase();

}

bool FItemFactory::LoadItemDatabase() {

	// Try to read from .csv if datatable not loaded/inaccurate
	FString DataTablePath = "DataTable '/Game/Data/ItemDatabase.ItemDatabase'";

	UDataTable* DataTable = ConstructorHelpersInternal::FindOrLoadObject<UDataTable>(DataTablePath);

	if (!DataTable) { UE_LOG(LogTemp, Error, TEXT("Datatable not loaded!")); return false; }
	DataTable->GetAllRows(FString("Test"), ItemDatabase);

	return true;

}

UItem* FItemFactory::CreateNewItem(int32 ItemID) {

	if (ItemID >= ItemDatabase.Num() || ItemID < 0){ UE_LOG(LogTemp, Error, TEXT("ItemID %i is out of range!"), ItemID); return nullptr; }
	FItemData* ItemData = ItemDatabase[ItemID];
	if (!ItemData) { UE_LOG(LogTemp, Error, TEXT("ItemData for ItemID %i is Null!"), ItemID); return nullptr; }
	UItem* Item = NewObject<UItem>();
	Item->Initialise(ItemData);
	//UE_LOG(LogTemp, Warning, TEXT("Created object with name: %s"), *ItemData->Name);
	return Item;

}
