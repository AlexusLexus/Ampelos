// yes

#pragma once

#include "CoreMinimal.h"
#include "ApollonDefinition.h"

#include "GameplayTagContainer.h"
#include "Sound/SoundCue.h"

#include "ApollonItemDefinition.generated.h"

UENUM(BlueprintType)
enum EApollonItemType
{
	T_Item UMETA(DisplayName = "Item"),
	T_Token UMETA(DisplayName = "Token"),
	T_WorldObject UMETA(DisplayName = "World Object"),
	T_Gadget UMETA(DisplayName = "Gadget"),
	T_Ammo UMETA(DisplayName = "Ammo"),
	T_WeaponRanged UMETA(DislayName = "Weapon Ranged"),
	T_WeaponMelee UMETA(DisplayName = "Weapon Melee"),
	T_Alteration UMETA(DisplayName = "Alteration"),
	T_Stat UMETA(DisplayName = "Stat"),
	T_Trincket UMETA(DisplayName = "Trincket"),
	T_Currency UMETA(DisplayName = "Currency"),
	T_Quest UMETA(DisplayName = "Quest"),
	T_Ingridient UMETA(DisplayName = "Ingridient"),
	T_Schematic UMETA(DisplayName = "Schematic"),
	T_XP UMETA(DisplayName = "XP"),
	T_Note UMETA(DisplayName = "Note"),
	T_Prop UMETA(DisplayName = "Prop"),
	T_Badge UMETA(DisplayName = "Badge"),
	T_Deco UMETA(DisplayName = "Deco"),
	T_NeverPersist UMETA(DisplayName = "Never Persist"),
	T_Character UMETA(DisplayName = "Character"),
	T_Costume UMETA(DisplayName = "Costume"),
	T_VariantToken UMETA(DisplayName = "Variant Token")
};

UENUM(BlueprintType)
enum EApollonFilterOverride
{
	F_Invisible UMETA(DisplayName = "Filter Invisible"),
	F_Item UMETA(DisplayName = "Filter Item"),
	F_Token UMETA(DisplayName = "Filter Token"),
	F_WorldObject UMETA(DisplayName = "Filter World Object"),
	F_Gadget UMETA(DisplayName = "Filter Gadget"),
	F_Ammo UMETA(DisplayName = "Filter Ammo"),
	F_WeaponRanged UMETA(DislayName = "Filter Weapon Ranged"),
	F_WeaponMelee UMETA(DisplayName = "Filter Weapon Melee"),
	F_Alteration UMETA(DisplayName = "Filter Alteration"),
	F_Stat UMETA(DisplayName = "Filter Stat"),
	F_Trincket UMETA(DisplayName = "Filter Trincket"),
	F_Currency UMETA(DisplayName = "Filter Currency"),
	F_Quest UMETA(DisplayName = "Filter Quest"),
	F_Ingridient UMETA(DisplayName = "Filter Ingridient"),
	F_Schematic UMETA(DisplayName = "Filter Schematic"),
	F_XP UMETA(DisplayName = "Filter XP"),
	F_Note UMETA(DisplayName = "Filter Note"),
	F_Prop UMETA(DisplayName = "Filter Prop"),
	F_Badge UMETA(DisplayName = "Filter Badge"),
	F_Deco UMETA(Displayname = "Filter Deco"),
	F_NeverPersist UMETA(DisplayName = "Filter Never Persist"),
	F_Character UMETA(DisplayName = "Filter Character"),
	F_Costume UMETA(DisplayName = "Filter Costume"),
	F_VariantToken UMETA(DisplayName = "Filter Variant Token")
};

UENUM(BlueprintType)
enum EApollonRarity
{
	Common,
	Rare,
	Masterpiece,
	Transcendent,
	ApollonLegacy
};

UENUM(BlueprintType)
enum EApollonPickupMeshChannel
{
	PMC_SkeletalMesh UMETA(DisplayName = "Skeletal Mesh"),
	PMC_StaticMesh UMETA(DisplayName = "Static Mesh")
};

UENUM(BlueprintType)
enum EApollonPickupType
{
	PT_Default UMETA(DisplayName = "Default"),
	PT_Auto UMETA(DisplayName = "Auto"),
	PT_SpinnerWithLightPillar UMETA(DisplayName = "Spinner with Light Pillar")
};

UENUM(BlueprintType)
enum EApollonTier
{
	None,
	I,
	II,
	III,
	IV,
	V,
	VI,
	VII,
	VIII,
	IX,
	X
};

/**
 * 
 */
UCLASS(BlueprintType)
class GPC_TOOLS_API UApollonItemDefinition : public UApollonDefinition
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "APOLLON|Debug Shit")
		void WriteDebugInfo(UApollonItemDefinition* Input);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		FString ItemID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		FText ShortDesc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		TEnumAsByte<EApollonItemType> ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		TEnumAsByte<EApollonFilterOverride> FilterOverride;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		TEnumAsByte<EApollonRarity> Rarity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		TEnumAsByte<EApollonTier> CurrentTier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		TEnumAsByte<EApollonTier> MaxTier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		FGameplayTagContainer ItemTags;
	//Small Preview
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		UTexture2D* SquareEditorIcon;
	//Big Preview
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		UTexture2D* RectangleWheelIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition", meta = (ClampMin = 1, EditCondition = "bAllowStacking"))
		int MaxStackSize = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		bool bAllowStacking = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		bool bAllowMultipleStacking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		TEnumAsByte<EApollonPickupType> PickupType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		bool bUsePhysics;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition", meta = (ClampMin = 50, EditCondition = "bUsePhysics"))
		float WorldMass = 101.69420f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		float AutoPickupRadius = 69.420f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		UStaticMesh* CollisionModel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		TEnumAsByte<EApollonPickupMeshChannel> PickupMeshChannel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition|Pickup Mesh")
		USkeletalMesh* PickupSkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition|Pickup Mesh")
		UStaticMesh* PickupStaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition|Audio")
		USoundCue* PickupSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition|Audio")
		USoundCue* DropSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		FText SearchKeywords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition")
		FString AnalysticsName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition", AdvancedDisplay)
		bool bCantBeDropped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition", AdvancedDisplay)
		bool bFocusOnPickup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition", AdvancedDisplay)
		bool bAllowBeDrawnOnMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apollon Item Definition", AdvancedDisplay, meta = (EditCondition = "bAllowBeDrawnOnMap"))
		UTexture2D* MapBrush;

};
