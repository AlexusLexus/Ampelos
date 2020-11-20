// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "Animation/AnimInstance.h"
#include "Sound/SoundCue.h"
#include "AmpelosCharacterItemDefinition.h"

#include "AmpelosGliderItemDefinition.generated.h"

UENUM(BlueprintType)
enum class EAmpelosGliderType : uint8
{
	Default,
	Umbrella,
	BlackMondayCape
};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosGliderItemDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Item Definition")
		TSubclassOf<AActor> GliderClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Item Definition")
		USkeletalMesh* GliderMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Item Definition")
		EAmpelosGliderType GliderType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Item Definition")
		TSubclassOf<UAnimInstance> GliderAnimClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Item Definition")
		USoundCue* OpenSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Item Definition")
		USoundCue* CloseSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Item Definition")
		USoundCue* LoopSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Personolized Glider Variant Definition")
		TArray<FAmpelosCharacterVariantCategoryDefinition> GliderVariantData;
	
};
