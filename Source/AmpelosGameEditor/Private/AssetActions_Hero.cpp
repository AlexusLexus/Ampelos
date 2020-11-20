// yes


#include "AssetActions_Hero.h"

AssetActions_Hero::AssetActions_Hero(EAssetTypeCategories::Type InAssetCategory) : HeroCategory(InAssetCategory)
{
}

FText AssetActions_Hero::GetName() const
{
	return FText::FromString(TEXT("Hero"));
}

FColor AssetActions_Hero::GetTypeColor() const
{
	return FColor(100, 170, 80);
}

UClass* AssetActions_Hero::GetSupportedClass() const
{
	return UAmpelosHeroType::StaticClass();
}

uint32 AssetActions_Hero::GetCategories()
{
	return HeroCategory;
}
