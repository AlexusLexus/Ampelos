// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"

#include "AmpelosBadgeItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosBadgeItemDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Badge Item Definition")
		UMaterial* OverrideBadgeMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Badge Item Definition")
		FText LockedDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Badge Item Definition")
		FText UnlockedDescription;
	/*
	*	If this value is '-1', it will take NEXT FREE POSITION
	*	If this value is > -1, it will take IT'S PREFERED POSITION And if needed all free spaces will be extinguished
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Badge Item Definition", meta = (ClampMin = -1))
		int PreferedPosition = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Badge Item Definition")
		FGameplayTag BadgeTag;
	
};
