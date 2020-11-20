// yes


#include "AssetActions_ObjectiveSet.h"

AssetActions_ObjectiveSet::AssetActions_ObjectiveSet(EAssetTypeCategories::Type InAssetCategory) : ObjectiveSetCategory(InAssetCategory)
{
}

FText AssetActions_ObjectiveSet::GetName() const
{
	return FText::FromString(TEXT("Quest Objective Set"));
}

FColor AssetActions_ObjectiveSet::GetTypeColor() const
{
	return FColor(220, 150, 60);
}

UClass* AssetActions_ObjectiveSet::GetSupportedClass() const
{
	return UQuestObjectiveSet::StaticClass();
}

uint32 AssetActions_ObjectiveSet::GetCategories()
{
	return ObjectiveSetCategory;
}
