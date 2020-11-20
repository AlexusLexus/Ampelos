// yes


#include "AssetActions_QuestBundle.h"

AssetActions_QuestBundle::AssetActions_QuestBundle(EAssetTypeCategories::Type InAssetCategory) : QuestBundleCategory(InAssetCategory)
{
}

FText AssetActions_QuestBundle::GetName() const
{
	return FText::FromString(TEXT("Quest Bundle"));
}

FColor AssetActions_QuestBundle::GetTypeColor() const
{
	return FColor(0, 175, 175);
}

UClass* AssetActions_QuestBundle::GetSupportedClass() const
{
	return UAmpelosQuestBundleDefinition::StaticClass();
}

uint32 AssetActions_QuestBundle::GetCategories()
{
	return QuestBundleCategory;
}

