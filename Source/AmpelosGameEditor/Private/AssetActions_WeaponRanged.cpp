// yes


#include "AssetActions_WeaponRanged.h"

AssetActions_WeaponRanged::AssetActions_WeaponRanged(EAssetTypeCategories::Type InAssetCategory) : WeaponRangedCategory(InAssetCategory)
{
}

FText AssetActions_WeaponRanged::GetName() const
{
	return FText::FromString(TEXT("Weapon Ranged"));
}

FColor AssetActions_WeaponRanged::GetTypeColor() const
{
	return FColor(0, 102, 204);
}

UClass* AssetActions_WeaponRanged::GetSupportedClass() const
{
	return UAmpelosWeaponRangedDefinition::StaticClass();
}

uint32 AssetActions_WeaponRanged::GetCategories()
{
	return WeaponRangedCategory;
}