// Copyright FairgroundPanda Studios by Jordan J Craig

#include "Item.h"
#include "UObject/ConstructorHelpers.h"

UItem::UItem() {

	LoadItemDatabase();

}

bool UItem::LoadItemDatabase() {

	FString DataTablePath = "DataTable '/Game/Data/ItemDatabase.ItemDatabase'";

	UDataTable* DataTable = ConstructorHelpersInternal::FindOrLoadObject<UDataTable>(DataTablePath);

	TArray<FItemData*> ItemData;
	if (!DataTable) { UE_LOG(LogTemp, Error, TEXT("Datatable not loaded!")); return false; }
	DataTable->GetAllRows(FString("Test"), ItemData);

	for (FItemData* Item : ItemData) {
		UE_LOG(LogTemp, Warning, TEXT("ItemData: %s"), *Item->Name);
	}

	return true;

}
