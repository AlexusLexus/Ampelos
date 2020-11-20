// yes

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "AmpelosGlobals.h"
#include "Animation/AnimInstance.h"

#include "AmpelosCustomCharacterPart.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosCustomCharacterPart : public UDataAsset
{
	GENERATED_BODY()

public:

	//Leave this ref NULL to use default anim class
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Character Custom Part")
		TSubclassOf<UAnimInstance> AnimClass;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Character Custom Part")
		EAmpelosCustomPartType CharacterPartType;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Character Custom Part")
		USkeletalMesh* CharacterSkeletalMesh;
	//Leave this material NULL to not override material on part swap
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Character Custom Part")
		UMaterial* MaterialOverride;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Character Custom Part|Morph Targets")
		FName HatMorphTargetName;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Character Custom Part|Morph Targets")
		FName AdditionalHairTargetName;

};
