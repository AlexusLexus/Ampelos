// yes


#include "AmpelosPlaylist.h"

TSubclassOf<AQuest> UAmpelosPlaylist::GetQuestHandler()
{
	return GameplayHandler;
}

TEnumAsByte<EAmpelosPlaylistGameType> UAmpelosPlaylist::GetGameTypeFromPlaylist()
{
	return GameType;
}

FGameplayTagContainer UAmpelosPlaylist::GetPlaylistTags()
{
	return PlaylistTags;
}

UTexture2D * UAmpelosPlaylist::GetPlaylistTiles(UTexture2D *& BigTile)
{
	BigTile = BigTileImage;

	return DefaultTileImage;
}
