// yes


#include "AssetActions_GameDataText.h"

AssetActions_GameDataText::AssetActions_GameDataText(EAssetTypeCategories::Type InAssetCategory) : GameDataTextCategory(InAssetCategory)
{
}

FText AssetActions_GameDataText::GetName() const
{
	return FText::FromString(TEXT("Game Data Text"));
}

FColor AssetActions_GameDataText::GetTypeColor() const
{
	return FColor(225, 130, 160);
}

UClass* AssetActions_GameDataText::GetSupportedClass() const
{
	return UGameDataText::StaticClass();
}

uint32 AssetActions_GameDataText::GetCategories()
{
	return GameDataTextCategory;

}
