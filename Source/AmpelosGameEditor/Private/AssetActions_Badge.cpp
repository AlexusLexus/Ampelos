// yes


#include "AssetActions_Badge.h"

AssetActions_Badge::AssetActions_Badge(EAssetTypeCategories::Type InAssetCategory) : BadgeCategory(InAssetCategory)
{
}

FText AssetActions_Badge::GetName() const
{
	return FText::FromString(TEXT("Badge"));
}

FColor AssetActions_Badge::GetTypeColor() const
{
	return FColor(127, 0, 255);
}

UClass * AssetActions_Badge::GetSupportedClass() const
{
	return UAmpelosBadgeItemDefinition::StaticClass();
}

uint32 AssetActions_Badge::GetCategories()
{
	return BadgeCategory;
}
