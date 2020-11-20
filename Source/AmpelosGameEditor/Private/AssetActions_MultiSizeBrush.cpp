// yes


#include "AssetActions_MultiSizeBrush.h"

AssetActions_MultiSizeBrush::AssetActions_MultiSizeBrush(EAssetTypeCategories::Type InAssetCategory) : MultiSizebBrushCategory(InAssetCategory)
{
}

FText AssetActions_MultiSizeBrush::GetName() const
{
	return FText::FromString(TEXT("Multi Size Brush"));
}

FColor AssetActions_MultiSizeBrush::GetTypeColor() const
{
	return FColor(255, 25, 25);
}

UClass* AssetActions_MultiSizeBrush::GetSupportedClass() const
{
	return UMultiSizeBrush::StaticClass();
}

uint32 AssetActions_MultiSizeBrush::GetCategories()
{
	return MultiSizebBrushCategory;
}
