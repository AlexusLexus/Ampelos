// yes


#include "AssetActions_Timecycle.h"

AssetActions_Timecycle::AssetActions_Timecycle(EAssetTypeCategories::Type InAssetCategory) : TimecycleCategory(InAssetCategory)
{
}

FText AssetActions_Timecycle::GetName() const
{
	return FText::FromString(TEXT("Timecycle"));
}

FColor AssetActions_Timecycle::GetTypeColor() const
{
	return FColor(77, 166, 255);
}

UClass * AssetActions_Timecycle::GetSupportedClass() const
{
	return UTimecycle::StaticClass();
}

uint32 AssetActions_Timecycle::GetCategories()
{
	return TimecycleCategory;
}
