// yes

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "GameplayTagContainer.h"

#include "AmpelosCPPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOS_API UAmpelosCPPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Quests", meta = (BlueprintInternalUseOnly = "true"))
		void UpdateQuest(int Count, UObject* ObjectiveSet, FGameplayTagQuery ObjectiveQuery);
	
};
