// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "Quest.h"
#include "GameplayTagContainer.h"

#include "AmpelosQuestItemDefinition.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOS_API UAmpelosQuestItemDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Item Definition")
		TSubclassOf<AQuest> QuestClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Item Definition")
		FGameplayTag UniqueQuestTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Item Definition")
		FGameplayTagContainer QuestTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Item Definition")
		TMap<int, FGameplayTag> StageTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Item Definition")
		UTexture2D* QuestIcon; 
	
};
