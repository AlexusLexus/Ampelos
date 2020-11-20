// yes

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameDataText.generated.h"

USTRUCT(BlueprintType)
struct FGameDataTextDefinition
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FString, FText> Entry;

};

USTRUCT(BlueprintType)
struct FGameDataTextRef
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintType)
		UGameDataText* TextTable;
	UPROPERTY(EditAnywhere, BlueprintType)
		FName TextEntryName;

};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UGameDataText : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "GPC Tools|Game Data|Text")
	TMap<FString, FText> GetTableEntry(FName EntryName);

	UFUNCTION(BlueprintPure, Category = "GPC Tools|Game Data|Text")
	FText GetTableEntryByCulture(FName EntryName, FString CultureName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data Text")
		TMap<FName, FGameDataTextDefinition> TextData;

};
