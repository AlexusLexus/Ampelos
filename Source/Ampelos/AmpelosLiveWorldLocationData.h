// yes

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "Misc/Guid.h"
#include "AmpelosLiveWorldLocation.h"

#include "AmpelosLiveWorldLocationData.generated.h"

USTRUCT(BlueprintType)
struct FAmpelosLiveWorldLocationEntry
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAmpelosLiveWorldLocation> LocationObjectRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Comment;

};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosLiveWorldLocationData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Live World Data")
		TMap<FGuid, FAmpelosLiveWorldLocationEntry> WorldLocationData;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Live World Data", meta = (DisplayThumbnail = "true"))
		class UTexture2D* CollectionIcon;*/
	
};
