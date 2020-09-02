// yes

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Timecycle.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GPC_TOOLS_API UTimecycle : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timecycle - Zenith")
		FColor Zenith_Color_1;
	
};
