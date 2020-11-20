// yes

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "QuestObjective.h"
#include "Misc/Guid.h"

#include "QuestObjectiveSet.generated.h"

USTRUCT(BlueprintType)
struct FAmpelosQuestGenObjectiveSet
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UQuestObjective* QuestObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NextStageIdOnComplition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NextStageIdOnFail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAmpelosQuestGenStoryBranch StoryBranch;

};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UQuestObjectiveSet : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Gen Objective Set")
		TMap<int, FAmpelosQuestGenObjectiveSet> ObjectivesSet;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ampelos Quest Gen Objective Set")
		FGuid ObjectivesSetGuid = ObjectivesSetGuid.NewGuid();
	
};
