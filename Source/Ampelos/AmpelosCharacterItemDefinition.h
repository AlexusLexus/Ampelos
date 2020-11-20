// yes

#pragma once

#include "CoreMinimal.h"
#include "AmpelosItemDefinition.h"

#include "GameplayTagContainer.h"
#include "MultiSizeBrush.h"
#include "AmpelosGlobals.h"
#include "AmpelosCustomCharacterPart.h"

#include "AmpelosCharacterItemDefinition.generated.h"

//UENUM(BlueprintType)
//enum class EAmpelosCustomPartType : uint8
//{
//	CPT_Head UMETA(DisplayName = "Head"),
//	CPT_Body UMETA(DisplayName = "Body"),
//	CPT_Hair UMETA(DisplayName = "Hair"),
//	CPT_Mask UMETA(DisplayName = "Mask"),
//	CPT_Hat UMETA(DisplayName = "Hat"),
//	CPT_Backpack UMETA(DisplayName = "Backpack"),
//	CPT_Acc_01 UMETA(DisplayName = "Acc 01"),
//	CPT_Acc_02 UMETA(DisplayName = "Acc 02"),
//	CPT_Acc_03 UMETA(DisplayName = "Acc 03")
//};

UENUM(BlueprintType, meta = (Bitflags))
enum EAmpelosVarinatMode
{
	CVM_PartAlteration,
	CVM_MaterialAlteration,
	CVM_MaterialParametrsAlteration,
	CVM_FloatSliderAlteration,
	CVM_ColorHueAlteration
};

USTRUCT(BlueprintType)
struct FAmpelosCharacterPartAlteration
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* CharacterPart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAmpelosCustomPartType PartType;

};

USTRUCT(BlueprintType)
struct FAmpelosCharcaterMaterialAlteration
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterial* MaterialToALter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0))
		int MaterialIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAmpelosCustomPartType PartToAlterMaterial;

};

USTRUCT(BlueprintType)
struct FAmpelosCharacterMaterialParametrAlteration
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterial* ParentMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ParametrName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAmpelosCustomPartType PartToAlterMaterialOn;

};

USTRUCT(BlueprintType)
struct FAmpelosCharacterFloatSliderAlteration
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DefaultSliderValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UMaterial*> MaterialsToAlter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ParamName;

};

USTRUCT(BlueprintType)
struct FRGBColor
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RGB_Red UMETA(DisplayName = "Red");
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RGB_Green UMETA(DisplayName = "Green");
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RGB_Blue UMETA(DisplayName = "Blue");

};

USTRUCT(BlueprintType)
struct FRGBAColor
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RGBA_Red UMETA(DisplayName = "Red");
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RGBA_Green UMETA(DisplayName = "Green");
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RGBA_Blue UMETA(DisplayName = "Blue");
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RGBA_Alpha UMETA(DisplayName = "Alpha");

};

USTRUCT(BlueprintType)
struct FAmpelosCharacterColorHueAlteration
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRGBColor DefaultColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAllowUserSavingColor;

};
	
USTRUCT(BlueprintType)
struct FAmpelosVariantMetaData
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer TagsToAdd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer TagsToRemove;

};

USTRUCT(BlueprintType)
struct FAmpelosCharacterVariantDefinition
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText VariantName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* VariantIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsDefault;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHideIfNotUnlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bUnlockAtStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* UnlockToken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTag VariantAlterationTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = "EAmpelosVarinatMode"))
		int32 VarinatModes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosCharacterPartAlteration> CharacterPartAlterations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosCharcaterMaterialAlteration> CharacterMaterialsAlterations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosCharacterMaterialParametrAlteration> CharacterMaterialParametrsAlterations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosCharacterFloatSliderAlteration> CharacterFloatSliderAlterations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosCharacterColorHueAlteration> CharacterColorHueAlterations;

};

USTRUCT(BlueprintType)
struct FAmpelosCharcaterVariantChannelDefinition
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText ChannelName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosCharacterVariantDefinition> Variants;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	TArray<FAmpelosCharacterFloatSliderAlteration> CharacterFloatSliderAlterations;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	TArray<FAmpelosCharacterColorHueAlteration> CharacterColorHueAlterations;

};

USTRUCT(BlueprintType)
struct FAmpelosCharacterVariantCategoryDefinition
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText CategoryName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* CategoryIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosCharcaterVariantChannelDefinition> Channels;


};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosCharacterItemDefinition : public UAmpelosItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Head;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Vest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Hair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Hat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Mask;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Backpack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Acc_01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Acc_02;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		UAmpelosCustomCharacterPart* CP_Acc_03;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		TArray<FName> AbsorbeStats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		FGameplayTagContainer CharacterTagAddOnEquip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		FGameplayTagQuery DisallowQuery;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
		FText DisabledDescription;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Item Definition")
	//	UAmpelosHeroType* HeroItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Character Variant Parts")
		TArray<FAmpelosCharacterVariantCategoryDefinition> VariantData;
	
};
