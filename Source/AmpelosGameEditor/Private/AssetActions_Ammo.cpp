// yes


#include "AssetActions_Ammo.h"

AssetActions_Ammo::AssetActions_Ammo(EAssetTypeCategories::Type InAssetCategory) : AmmoCategory(InAssetCategory)
{
}

FText AssetActions_Ammo::GetName() const
{
	return FText::FromString(TEXT("Ammo"));
}

FColor AssetActions_Ammo::GetTypeColor() const
{
	return FColor(204, 0, 102);
}

UClass* AssetActions_Ammo::GetSupportedClass() const
{
	return UAmpelosAmmoItemDefinition::StaticClass();
}

uint32 AssetActions_Ammo::GetCategories()
{
	return AmmoCategory;
}
