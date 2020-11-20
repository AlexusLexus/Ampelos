// yes


#include "AssetActions_Character.h"

AssetActions_Character::AssetActions_Character(EAssetTypeCategories::Type InAssetCategory) : CharacterCategory(InAssetCategory)
{
}

FText AssetActions_Character::GetName() const
{
	return FText::FromString(TEXT("Character"));
}

FColor AssetActions_Character::GetTypeColor() const
{
	return FColor(50, 140, 80);
}

UClass* AssetActions_Character::GetSupportedClass() const
{
	return UAmpelosCharacterItemDefinition::StaticClass();
}

uint32 AssetActions_Character::GetCategories()
{
	return CharacterCategory;
}
