// yes


#include "AssetActions_AbilityKit.h"

AssetActions_AbilityKit::AssetActions_AbilityKit(EAssetTypeCategories::Type InAssetCategory) : AbilityKitCategory(InAssetCategory)
{
}

FText AssetActions_AbilityKit::GetName() const
{
	return FText::FromString(TEXT("Ability Kit"));
}

FColor AssetActions_AbilityKit::GetTypeColor() const
{
	return FColor(255, 25, 25);
}

UClass* AssetActions_AbilityKit::GetSupportedClass() const
{
	return UAmpelosAbilityKit::StaticClass();
}

uint32 AssetActions_AbilityKit::GetCategories()
{
	return AbilityKitCategory;
}
