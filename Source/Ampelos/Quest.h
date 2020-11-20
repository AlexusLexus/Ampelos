// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AmpelosLiveWorldSubsystem.h"

#include "Misc/Guid.h"
#include "Engine/World.h"
#include "GameplayTagContainer.h"
#include "QuestObjectiveSet.h"
#include "QuestObjective.h"
#include "AmpelosItemDefinition.h"

#include "Quest.generated.h"

UENUM(BlueprintType)
enum class EAmpelosQuestGenUpdateTypeInfo : uint8
{
	PlayerReachedArea,
	PlayerLeavedArea,
	PlayerCollectedItem,
	PlayerDroppedItem,
	PlayerCompletedTask,
	WorldContextEventCall,
	TimerHitZero,
	PlayerInteractedWithWorldObject,
	ByDialogChoice,
	PlayerKillendPawn
};

USTRUCT(BlueprintType)
struct FAmpelosQuestGenUpdateInfo
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NewCountValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAmpelosQuestGenUpdateTypeInfo UpdateType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* UpdateItemRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int UpdateItemRefAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag TargetCharacterTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TargetCharacterCount;

};

/*
This is a parent class for any quest in AMPELOS
*/
UCLASS(Config = Game)
class AMPELOS_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest")
		int Stage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest")
		UQuestObjectiveSet* ObjectiveSet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest")
		FString QuestUniqueName;

	int ComplitionStage;
	int FailStage;
	
	//I'll do Update() in quest script itself
	//void Update();

	UFUNCTION(BlueprintImplementableEvent, Category = "AMPELOS|Quest Gen")
		void InitializeQuest(UQuestObjectiveSet* StartupObjectiveSet, int InitialStage);

	//Get Stage for current quest in this class.
	UFUNCTION(BlueprintPure, Category = "AMPELOS|Quests")
		int GetStage();

	UFUNCTION(BlueprintPure, Category = "AMPELOS|Quests")
		UQuestObjective* GetCurrentObjective();

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void AdvanceStage(int AdvanceScale);

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void FinishQuest();
		
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void FailQuest();

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void SetStage(int TargetStage);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "AMPELOS|Quests")
		void QuestUpdate();

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void CallUpdate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
