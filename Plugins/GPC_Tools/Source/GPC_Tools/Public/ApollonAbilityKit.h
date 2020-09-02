// yes

#pragma once

#include "CoreMinimal.h"
#include "ApollonItemDefinition.h"

#include "ApollonGameplayAbility.h"

#include "ApollonAbilityKit.generated.h"

USTRUCT(BlueprintType)
struct FApollonGameplayAbilityEffect
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FApollonGameplayEffectDefinition GameplayEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level = 1.0f;

};

/**
 * 
 */
UCLASS(BlueprintType)
class GPC_TOOLS_API UApollonAbilityKit : public UApollonItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Ability Kit")
		TArray<TSubclassOf<AApollonGameplayAbility>> GameplayAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Ability Kit")
		TArray<FApollonGameplayAbilityEffect> GameplayEfects;
	
	
};
