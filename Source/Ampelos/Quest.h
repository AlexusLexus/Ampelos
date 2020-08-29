// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AmpelosLiveWorldSubsystem.h"

#include "Misc/Guid.h"
#include "Engine/World.h"
#include "GameplayTagContainer.h"

#include "Quest.generated.h"

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

	int ComplitionStage;
	int FailStage;
	
	//I'll do Update() in quest script itself
	//void Update();

	//Get Stage for current quest in this class.
	UFUNCTION(BlueprintPure, Category = "AMPELOS|Quests")
		int GetStage();

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void AdvanceStage(int AdvanceScale);

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void FinishQuest();
		
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void FailQuest();

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests")
		void SetStage(int TargetStage);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
