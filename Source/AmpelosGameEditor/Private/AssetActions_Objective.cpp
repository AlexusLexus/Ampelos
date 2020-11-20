// yes


#include "AssetActions_Objective.h"

AssetActions_Objective::AssetActions_Objective(EAssetTypeCategories::Type InAssetCategory) : ObjectiveCategory(InAssetCategory)
{
}

FText AssetActions_Objective::GetName() const
{
	return FText::FromString(TEXT("Quest Objective"));
}

FColor AssetActions_Objective::GetTypeColor() const
{
	return FColor(180, 190, 90);
}

UClass* AssetActions_Objective::GetSupportedClass() const
{
	return UQuestObjective::StaticClass();
}

uint32 AssetActions_Objective::GetCategories()
{
	return ObjectiveCategory;
}
