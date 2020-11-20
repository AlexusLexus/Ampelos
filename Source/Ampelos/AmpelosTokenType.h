// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"

#include "AmpelosTokenType.generated.h"

UENUM(BlueprintType)
enum EAmpelosTokenOverrideType
{
	OT_Default UMETA(DisplayName = "Default"),
	OT_Currency UMETA(DisplayName = "Currency"),
	OT_ForQuests UMETA(DisplayName = "For Quests"),
	OT_Score UMETA(DisplayName = "Score"),
	OT_Stat UMETA(DisplayName = "Stat"),
	OT_XP UMETA(DisplayName = "XP"),
	OT_Ingridient UMETA(DisplayName = "Ingridient"),
	OT_Varinat UMETA(DisplayName = "Variant"),
	OT_Reagent UMETA(DisplayName = "Reagent"),
	OT_AccountResource UMETA(DisplayName = "Account Resource")
};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosTokenType : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Token Type")
		TEnumAsByte<EAmpelosTokenOverrideType> TokenOverrideType;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Token Type")
		bool bCreateTokenImage;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Token Type", meta = (EditCondition = "bCreateTokenImage"))
		UTexture2D* TokenImage;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Token Type")
		FGameplayTag TokenSpecialTag;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Token Type")
		bool bUseSubName;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Token Type", meta = (EditCondition = "bUseSubName"))
		FText SubDisplayName;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Token Type", meta = (EditCondition = "bUseSubName"))
		FText SubDescription;
	
};
