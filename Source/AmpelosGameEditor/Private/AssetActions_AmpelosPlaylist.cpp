// yes


#include "AssetActions_AmpelosPlaylist.h"

AssetActions_AmpelosPlaylist::AssetActions_AmpelosPlaylist(EAssetTypeCategories::Type InAssetCategory) : PlaylistCategory(InAssetCategory)
{
}

FText AssetActions_AmpelosPlaylist::GetName() const
{
	return FText::FromString(TEXT("AmpelosPlaylist"));
}

FColor AssetActions_AmpelosPlaylist::GetTypeColor() const
{
	return FColor(252, 161, 25);
}

UClass* AssetActions_AmpelosPlaylist::GetSupportedClass() const
{
	return UAmpelosPlaylist::StaticClass();
}

uint32 AssetActions_AmpelosPlaylist::GetCategories()
{
	return PlaylistCategory;
}