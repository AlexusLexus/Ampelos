// yes

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"
#include "Sound/SoundCue.h"

#include "AmpelosItemDefinition.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum EAmpelosItemType
{
	T_Item UMETA(DisplayName = "Item"),
	T_Gadget UMETA(DisplayName = "Gadget"),
	T_WeaponRanged UMETA(DisplayName = "Weapon Ranged"),
	T_WeaponMelee UMETA(DisplayName = "Weapon Melee"),
	T_Ammo UMETA(DisplayName = "Ammo"),
	T_Token UMETA(DisplayName = "Token"),
	T_Note UMETA(DisplayName = "Note"),
	T_Prop UMETA(DisplayName = "Prop"),
	T_Quest UMETA(DisplayName = "Quest"),
	T_Ingridient UMETA(DisplayName = "Ingridient"),
	T_NeverPersist UMETA(DisplayName = "Never Persist")
};

UENUM(BlueprintType)
enum EAmpelosItemFilterType
{
	F_Invisible UMETA(Displayname = "Filter Invisible"),
	F_Item UMETA(DisplayName = "Filter Item"),
	F_Gadget UMETA(DisplayName = "Filter Gadget"),
	F_WeaponRanged UMETA(DisplayName = "Filter Weapon Ranged"),
	F_WeaponMelee UMETA(DisplayName = "Filter Weapon Melee"),
	F_Ammo UMETA(DisplayName = "Filter Ammo"),
	F_Token UMETA(DisplayName = "Filter Token"),
	F_Note UMETA(DisplayName = "Filter Note"),
	F_Prop UMETA(DisplayName = "Filter Prop"),
	F_Quest UMETA(DisplayName = "Filter Quest"),
	F_Ingridient UMETA(DisplayName = "Filter Ingridient"),
	F_NeverPersist UMETA(DisplayName = "Filter Never Persist")
};

UENUM(BlueprintType)
enum EAmpelosItemAccessType
{
	Public,
	Private,
	DevOnly
};

UENUM(BlueprintType)
enum EAmpelosProfileType 
{
	AmpelosBaseGame,
	AmpelosPlayerAccount,
	Ampelos_U01,
	Ampelos_U02,
	Ampelos_U03,
	Ampelos_U04,
	Ampelos_U05,
	Ampelos_U06,
	Ampelos_U07,
	Ampelos_U08,
	Ampelos_U09,
	Ampelos_U10
};

UENUM(BlueprintType)
enum EAmpelosPickupMeshChannel
{
	SkeletalMesh,
	StaticMesh
};

UENUM(BlueprintType)
enum EAmpelosPickupType
{
	PT_Default UMETA(DisplayName = "Default"),
	PT_Auto UMETA(DisplayName = "Auto"),
	PT_SpinnerWithLightPillar UMETA(DisplayName = "Spinner with Light pillar")
};

UCLASS(BlueprintType)
class AMPELOS_API UAmpelosItemDefinition : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		FString ItemID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		FText ShortDesc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		FGameplayTagContainer ItemTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		TEnumAsByte<EAmpelosItemType> ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		TEnumAsByte<EAmpelosItemFilterType> FilterOverride;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		UTexture2D* SmallIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		UTexture2D* BigIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		UTexture2D* WideIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		TEnumAsByte<EAmpelosItemAccessType> AccessType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		TEnumAsByte<EAmpelosProfileType> ProfileType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		TEnumAsByte<EAmpelosPickupMeshChannel> PickupMeshChannel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition", meta = (ClampMin = 1))
		int MaxStackSize = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		bool bAllowStacking = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		bool bAllowMultiStacking;
	//If amount of this item is 0 and bSkipZeroCheck == true, then item will not be deleted
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		bool bSkipZeroCheck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		TEnumAsByte<EAmpelosPickupType> PickupType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		bool bUsePhysics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition", meta = (EditCondition = "bUsePhysics"))
		float Mass = 69.420;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		float PickupRadius = 52;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition")
		UStaticMesh* CollisionModel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Pickup Mesh")
		UStaticMesh* StaticPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Pickup Mesh")
		USkeletalMesh* SkeletalPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Item Sound")
		USoundCue* PickupSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Item Sound")
		USoundCue* DropSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Item Sound")
		USoundCue* DroppedLoopingSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		FText OverrideShortDesc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		FGameplayTagQuery DisallowPickupCheck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		FText DisallowDescription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		TSubclassOf<AActor> OverridePickupClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		FGameplayTag SpecialItemTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		bool bCanBeDropped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		bool bDestroyOnDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		bool bShouldTakeTimeToPickUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Item Definition|Flags")
		float TimeToPickup;

};
