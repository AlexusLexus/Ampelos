// yes


#include "AssetActions_Gadget.h"

AssetActions_Gadget::AssetActions_Gadget(EAssetTypeCategories::Type InAssetCategory) : GadgetCategory(InAssetCategory)
{
}

FText AssetActions_Gadget::GetName() const
{
	return FText::FromString(TEXT("Gadget"));
}

FColor AssetActions_Gadget::GetTypeColor() const
{
	return FColor(250, 210, 10);
}

UClass * AssetActions_Gadget::GetSupportedClass() const
{
	return UAmpelosGadgetItemDefinition::StaticClass();
}

uint32 AssetActions_Gadget::GetCategories()
{
	return GadgetCategory;
}
