// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"

#include "AmpelosAmmoItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosAmmoItemDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Ammo Item Definition")
		FGameplayTag AmmoTag;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Ammo Item Definition")
		bool bRenderIconBrush;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Ammo Item Definition", meta = (EditCondition = "bRenderIconBrush"))
		UTexture2D* IconBrush;
};
