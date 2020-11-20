// yes

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "GameplayTagContainer.h"
#include "AmpelosItemDefinition.h"
#include "AmpelosTokenType.h"
#include "Misc/Guid.h"

#include "QuestObjective.generated.h"

UENUM(BlueprintType)
enum class EAmpelosQuestGenStoryBranch : uint8
{
	BranchNone,
	A,
	B,
	C,
	D,
	E,
	F
};

UENUM(BlueprintType)
enum class EAmpelosQuestGenEventType : uint8
{
	OnUpdate,
	OnObjectiveFail,
	OnObjectiveComplete,
	OnObjectiveProgress
};

UENUM(BlueprintType)
enum class EAmpelosQuestGenContributionType : uint8
{
	/*All players can complete this objctive. Team work.*/
	AllPlayersInSession,
	/*Can be completed only by host.*/
	HostForAllplayers,
	/*All players but host can complete this objective.*/
	AllPlayersForHost,
	/*Random  player will be selected upon start and be able to complete objective.*/
	SelectedPlayerForOthers
};

USTRUCT(BlueprintType)
struct FAmpelosQuestGenItemRefs
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* ItemReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 1))
		int AmountReference = 1;

};

USTRUCT(BlueprintType)
struct FAmpelosQuestGenTokenRef
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosTokenType* TokenReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 1))
		int TokenAmountReference = 1;

};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UQuestObjective : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
		int StageId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
		FText ObjectiveDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
		FText ShortObjectiveDesc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
		UTexture2D* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
		FText FailDescription;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Objective")
		FGuid ObjectiveGuid = ObjectiveGuid.NewGuid();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
	TMap<EAmpelosQuestGenStoryBranch, UQuestObjective*> BranchingObjectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		FGameplayTagQuery ComplitionCondition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		FGameplayTagContainer ComplitionArgumentsTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		TArray<FGameplayTag> ComplitionConditionsTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		FGameplayTagQuery FailCondition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		TArray<FGameplayTag> FailArgumentsTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		FGameplayTagContainer FailConditionTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		int ObjectiveCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		FAmpelosQuestGenItemRefs RequiredEquipedItemRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Conditions")
		FAmpelosQuestGenTokenRef RequiredTokensItemRef;

	/*If true this stage will be invisible to player, but still trakced and counted in backend.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		bool bInvisible;
	/*In order to complete this objective player have to complete it in one go. If players leaves or exits the game progress will be reseted.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		bool bAllOrNothing;
	/*The value of progress for this objective will be saved in quest struct.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		bool bSaveProgress;
	/*This objctive is optional. If further stages completed this stage becomes unavailable.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		bool bOptional;
	/*If true, then this objective can be completed only in single player mode.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		bool bOnlySingleplayerObjective;
	/*
	* ONLY FOR MULTIPLAYER!
	* Complete objective for all clients in the session.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		bool bForciblyProgressAllClients;
	/*Set who can complete objective.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		EAmpelosQuestGenContributionType ContributionType;
	/*Can't be completed until ref'd item is not in player's hands.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		bool bCanBeCompletedOnlyIfQuestItemEquiped;
	/*Track stat for quest updates.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flags")
		FName TrackedStat;
	
};
