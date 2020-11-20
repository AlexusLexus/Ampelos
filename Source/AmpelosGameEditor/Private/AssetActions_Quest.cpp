// yes


#include "AssetActions_Quest.h"

AssetActions_Quest::AssetActions_Quest(EAssetTypeCategories::Type InAssetCategory) : QuestCategory(InAssetCategory)
{
}

FText AssetActions_Quest::GetName() const
{
	return FText::FromString(TEXT("Quest"));
}

FColor AssetActions_Quest::GetTypeColor() const
{
	return FColor(0, 255, 255);
}

UClass* AssetActions_Quest::GetSupportedClass() const
{
	return UAmpelosQuestItemDefinition::StaticClass();
}

uint32 AssetActions_Quest::GetCategories()
{
	return QuestCategory;
}
