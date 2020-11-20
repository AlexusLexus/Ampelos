// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"
#include "AmpelosCharacterItemDefinition.h"
#include "AmpelosGameplayAbility.h"
#include "AmpelosCustomCharacterPart.h"
#include "AmpelosAbilityKit.h"
#include "AmpelosGlobals.h"
#include "AmpelosGadgetItemDefinition.h"

#include "AmpelosHeroType.generated.h"

USTRUCT(BlueprintType)
struct FAmpelosHeroParts
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Head;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Vest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Hair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Mask;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Hat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Backpack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Acc_01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Acc_02;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosCustomCharacterPart* Acc_03;

};

USTRUCT(BlueprintType)
struct FAmpelosHeroGadgetPair
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosGadgetItemDefinition* HeroGadget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int HeroGadgetSlotIndex;

};

USTRUCT(BlueprintType)
struct FAmpelosHeroWeaponPair
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* HeroWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int HeroWeaponSlotIndex;

};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosHeroType : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		TArray<TSubclassOf<AAmpelosGameplayAbility>> GrantedAbilities;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		UAmpelosAbilityKit* GrantedAbilityKit;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		FGameplayTagQuery RequiredHeroTags;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		FGameplayTagContainer GrantedTags;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		UAmpelosCharacterItemDefinition* HeroCosmeticOutfitDefinition;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		UAmpelosCustomCharacterPart* HeroCosmeticBackpackDefinition;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		UAmpelosItemDefinition* HeroPersonolizedGliderDefinition;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		FAmpelosHeroParts DefaultHeroParts;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		UAmpelosGadgetItemDefinition* DefaultHeroGadget;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		TArray<FAmpelosHeroGadgetPair> DefaultHeroGadgets;
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Ampelos Hero Type")
		TArray<FAmpelosHeroWeaponPair> DefaultHeroWeapons;
	
};
