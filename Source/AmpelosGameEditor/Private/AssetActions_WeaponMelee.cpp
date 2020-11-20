// yes


#include "AssetActions_WeaponMelee.h"

AssetActions_WeaponMelee::AssetActions_WeaponMelee(EAssetTypeCategories::Type InAssetCategory) : WeaponMeleeCategory(InAssetCategory)
{
}

FText AssetActions_WeaponMelee::GetName() const
{
	return FText::FromString(TEXT("Weapon Melee"));
}

FColor AssetActions_WeaponMelee::GetTypeColor() const
{
	return FColor(102, 178, 255);
}

UClass* AssetActions_WeaponMelee::GetSupportedClass() const
{
	return UAmpelosWeaponMeleeDefinition::StaticClass();
}

uint32 AssetActions_WeaponMelee::GetCategories()
{
	return WeaponMeleeCategory;
}
