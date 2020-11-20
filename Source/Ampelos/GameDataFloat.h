// yes

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameDataFloat.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGameDataFloatRef
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UGameDataFloat* GameDataTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName FloatTargetName;

};

UCLASS(BlueprintType)
class AMPELOS_API UGameDataFloat : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "GPC Tools|Game Data|Float")
		float GetFloatValue(FName ValueName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data Float")
		TMap<FName, float> FloatData;
	
};
