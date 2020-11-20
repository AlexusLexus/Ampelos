// yes


#include "AssetActions_Prop.h"

AssetActions_Prop::AssetActions_Prop(EAssetTypeCategories::Type InAssetCategory) : PropCategory(InAssetCategory)
{
}

FText AssetActions_Prop::GetName() const
{
	return FText::FromString(TEXT("Prop"));
}

FColor AssetActions_Prop::GetTypeColor() const
{
	return FColor(250, 210, 140);
}

UClass* AssetActions_Prop::GetSupportedClass() const
{
	return UAmpelosPropItemDefinition::StaticClass();
}

uint32 AssetActions_Prop::GetCategories()
{
	return PropCategory;
}
