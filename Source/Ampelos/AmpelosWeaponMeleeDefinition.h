// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"

#include "AmpelosWeaponMeleeDefinition.generated.h"

UENUM(BlueprintType)
enum EAmpelosWeaponMeleeType
{
	Sword
};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosWeaponMeleeDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		TSubclassOf<AActor> WeaponClass UMETA(DisplayName = "Weapon Actor Class");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		USkeletalMesh* MeshOverride UMETA(DisplayName = "Weapon Mesh Override");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		FName StatHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		UAmpelosItemDefinition* BaseAlt UMETA(DisplayName ="Base Alteration");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		bool bCanSprint UMETA(DisplayName = "Can Sprint With Weapon");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		bool bCanCrouch UMETA(DisplayName = "Can Crouch With Weapon");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		UAmpelosItemDefinition* EquipedAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		FGameplayTagContainer EquipedWeaponTags UMETA(DisplayName = "Equiped Tags");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Melee Item Dedinition")
		FName AttachSocket UMETA(DisplayName = "Attach Socket Name");
	
};
