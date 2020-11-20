// yes


#include "AssetActions_ItemDefinition.h"

AssetActions_ItemDefinition::AssetActions_ItemDefinition(EAssetTypeCategories::Type InAssetCategory) : ItemDefinitionCategory(InAssetCategory)
{

}

FText AssetActions_ItemDefinition::GetName() const
{
	return FText::FromString(TEXT("Item Definition"));
}

FColor AssetActions_ItemDefinition::GetTypeColor() const
{
	return FColor(30, 230, 100);
}

UClass* AssetActions_ItemDefinition::GetSupportedClass() const
{
	return UAmpelosItemDefinition::StaticClass();
}

uint32 AssetActions_ItemDefinition::GetCategories()
{
	return ItemDefinitionCategory;
}