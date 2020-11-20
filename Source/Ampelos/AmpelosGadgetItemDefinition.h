// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "AmpelosAbilityKit.h"
#include "AmpelosGameplayAbility.h"

#include "AmpelosGadgetItemDefinition.generated.h"

UENUM(BlueprintType)
enum class EAmpelosCharacterOverrideType : uint8
{
	COT_None UMETA(DisplayName = "None"),
	COT_Override UMETA(DisplayName = "Override")
};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosGadgetItemDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		UAmpelosItemDefinition* WeaponItemDefinition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		UAmpelosAbilityKit* AbilityKit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		TArray<TSubclassOf<AAmpelosGameplayAbility>> EquipedAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		TSubclassOf<AAmpelosGameplayAbility> OnEquipAbility;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
	// AbilityKit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		TSubclassOf<UAnimInstance> OverrideWeaponAnimBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		USkeletalMesh* OverrideSkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		FGameplayTag SpecialInventoryTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		FName AttachSocketName;
	//If this item is present more the one it will be dropped and changed for new item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		bool bDissallowMultistack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Flags")
		FText InventoryActorDisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Flags")
		bool bDropCurrentEquipedItemsOnEquip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Flags")
		FGameplayTagContainer HUD_Tags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition")
		EAmpelosCharacterOverrideType CharacterOverrideType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Head;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Hat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Hair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Backpack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Acc01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Acc02;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Gadget Item Definition|Character Parts")
		UAmpelosItemDefinition* Override_Acc03;
		
};
