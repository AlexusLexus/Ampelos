// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"
#include "AmpelosAmmoItemDefinition.h"

#include "AmpelosWeaponRangedDefinition.generated.h"

UENUM(BlueprintType)
enum class EAmpelosWeaponRangedType : uint8
{
	Pistol,
	AssaultRifle,
	Shotgun,
	Minigun,
	SMG,
	LMG,
	RPG,
	GrenadeLauncher,
	Railgun_High,
	Shitgun_DoubleBarrel
};

UENUM(BlueprintType)
enum class EAmpelosWeaponRangedTriggerType : uint8
{
	Auto,
	Burst,
	On_Release
};

UENUM(BlueprintType)
enum class EAmpelosWeaponRangedReloadType : uint8
{
	ReloadWholeClip,
	ReloadOneByOne,
	Recharge,
	Cooldown
};

UENUM(BlueprintType)
enum class EAmpelosWeaponRangedMechanic : uint8
{
	Default_Scanline,
	Default_ProjectileBased,
	With_Cooldown,
	Recharging,
	InfiniteAmmo
};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosWeaponRangedDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		TSubclassOf<AActor> WeaponActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		USkeletalMesh* WepaonMeshOverride;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		TSubclassOf<AActor> ProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		UAmpelosAmmoItemDefinition* AmmoData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		EAmpelosWeaponRangedMechanic WeaponMechanic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		EAmpelosWeaponRangedType WeaponRangedType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		EAmpelosWeaponRangedReloadType ReloadType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		EAmpelosWeaponRangedTriggerType TriggerType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		UAmpelosItemDefinition* BaseAlteration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		FName StatHandleName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		bool bCanBeReloaded = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		bool bCanSprintWithWeapon = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		bool bCanCrouchWithWeapon = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		bool bCanAimWhileReloading = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		bool bCanAimWhileSprinting = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		bool bCanAimWhleFallingJumping = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		bool bAutoEquiponPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		FGameplayTagContainer EquipedTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		FName SocketName UMETA(DisplayName = "Attach Socket Name");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		float CooldownTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Weapon Ranged Item Dedinition")
		float ReachrgeTime;

};
