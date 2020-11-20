// yes


#include "AssetActions_GameDataFloat.h"

AssetActions_GameDataFloat::AssetActions_GameDataFloat(EAssetTypeCategories::Type InAssetCategory) : GameDataFloatCategory(InAssetCategory)
{
}

FText AssetActions_GameDataFloat::GetName() const
{
	return FText::FromString(TEXT("Game Data Float"));
}

FColor AssetActions_GameDataFloat::GetTypeColor() const
{
	return FColor(161, 255, 69);
}

UClass* AssetActions_GameDataFloat::GetSupportedClass() const
{
	return UGameDataFloat::StaticClass();
}

uint32 AssetActions_GameDataFloat::GetCategories()
{
	return GameDataFloatCategory;
}
