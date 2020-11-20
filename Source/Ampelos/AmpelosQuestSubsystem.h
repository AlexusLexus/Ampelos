// yes

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AmpelosQuestSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOS_API UAmpelosQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Quest Subsystem")
		TMap<FName, FString> QuestScriptsList;
	
};
