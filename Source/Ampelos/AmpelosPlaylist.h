// yes

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "Quest.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "Blueprint/UserWidget.h"

#include "AmpelosPlaylist.generated.h"

UENUM(BlueprintType)
enum EAmpelosPlaylistGameType
{
	PGT_Singleplayer UMETA(DisplayName = "Singleplayer"),
	PGT_Coop UMETA(DisplayName = "COOP"),
	PGT_LTE UMETA(DisplayName = "Limited Time Event")
};

UENUM(BlueprintType)
enum EAmpelosAdditionakWidgetPosition
{
	TopCenter,
	TopLeft,
	TopRight,
	UseArea,
	BottomLeft,
	SubtilesArea,
	BottomRight
};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosPlaylist : public UDataAsset
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "AMPELOS|Playlist")
		TSubclassOf<AQuest> GetQuestHandler();

	UFUNCTION(BlueprintPure, Category = "AMPELOS|Playlist")
		TEnumAsByte<EAmpelosPlaylistGameType> GetGameTypeFromPlaylist();

	UFUNCTION(BlueprintPure, Category = "AMPELOS|Playlist")
		FGameplayTagContainer GetPlaylistTags();

	UFUNCTION(BlueprintPure, Category = "AMPELOS|Playlist")
		UTexture2D* GetPlaylistTiles(UTexture2D*& BigTile);

	//Use quest as gameplay handler
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		TSubclassOf<AQuest> GameplayHandler;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		TEnumAsByte<EAmpelosPlaylistGameType> GameType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		FText PlaylistDisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		FText PlaylistDisplayDesc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		UTexture2D* DefaultTileImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		UTexture2D* BigTileImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		int PlaylistIdNum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		FString PlaylistId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition", meta = (ClampMin = 1, ClampMax = 100))
		int MaxPlayers = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition", meta = (ClampMin = 1, ClampMax = 100))
		int MaxTeams = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition", meta = (ClampMin = 1, ClampMax = 100))
		int MaxTeamSize = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Playlist Definition")
		FGameplayTagContainer PlaylistTags;
	
};
