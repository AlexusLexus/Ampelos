// yes

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Misc/Guid.h"

#include "MultiSizeBrush.generated.h"

UENUM(BlueprintType)
enum class EMultiSizeBrushTypes : uint8
{
	//Defualt, shouldn't be used
	MSBT_None UMETA(DisplayName = "None"),
	//32x32
	MSBT_XXS UMETA(DisplayName = "XXS"),
	//64x64
	MSBT_XS UMETA(DisplayName = "XS"),
	//128x128
	MSBT_S UMETA(DisplayName = "S"),
	//256x256
	MSBT_M UMETA(DisplayName = "M"),
	//512x512
	MSBT_L UMETA(DisplayName = "L"),
	//1024x1024
	MSBT_XL UMETA(DisplayName = "XL"),
	//2048x2048
	MSBT_XXL UMETA(DisplayName = "XXL")
};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UMultiSizeBrush : public UObject
{
	GENERATED_BODY()

public:

	UMultiSizeBrush();

	FGuid EmptyGuid;

	UFUNCTION(BlueprintPure, Category = "GPC Tools|Multi Size Brush Asset")
		UTexture2D* GetBrush(EMultiSizeBrushTypes BrushType);
	//UFUNCTION(BlueprintPure, Category = "GPC Tools|Multi Size Brush Asset")
	//	TArray<UTexture2D*> GetArrayOfBrushes();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multi Brush Size Asset")
		TMap<EMultiSizeBrushTypes, UTexture2D*> MultiSizeBrushData;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Multi Brush Size Asset")
		FGuid AssetGuid = AssetGuid.NewGuid();
	
};
