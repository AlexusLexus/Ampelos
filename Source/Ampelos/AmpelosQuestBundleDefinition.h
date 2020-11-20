// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "AmpelosQuestItemDefinition.h"
#include "GameplayTagContainer.h"

#include "AmpelosQuestBundleDefinition.generated.h"

USTRUCT(BlueprintType)
struct FAmpelosQuestBundleStruct
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosQuestItemDefinition* QuestDef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bUnlockAtStart;


};

USTRUCT(BlueprintType)
struct FAmpelosRewardPair
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* RewardItemDef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int RewardAmount;

};

/**
 * 
 */
UCLASS()
class AMPELOS_API UAmpelosQuestBundleDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Bundle Item Definition")
		TArray<FAmpelosQuestBundleStruct> QuestsInBundle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Bundle Item Definition")
		TMap<int, FAmpelosRewardPair> Rewards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Bundle Item Definition")
		FAmpelosRewardPair ComplitionReward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Bundle Item Definition")
		FGameplayTagContainer BundleTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Bundle Item Definition")
		bool bHidden;
	
};
