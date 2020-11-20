// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"

#include "AmpelosPropItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosPropItemDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		TSubclassOf<AActor> PropActorClass;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		FGameplayTag PropTag;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		bool bSkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition", meta = (EditCondition = "!bSkeletalMesh"))
		USkeletalMesh* PropSkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition", meta = (EditCondition = "bSkeletalMesh"))
		UStaticMesh* PropStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		UStaticMesh* PreviewStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition", meta = (ClampMin = 1))
		float PropMass = 50.0f UMETA(DisplayName = "Mass");
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		UStaticMesh* PropCollision;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		FGameplayTagQuery FrinedlyProps;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		FGameplayTagQuery UnfriendlyProps;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Prop Item Definition")
		bool bReturnToInventoryWhenPutInWater = true;
	
};
