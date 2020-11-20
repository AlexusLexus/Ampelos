// yes

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "GameplayTagContainer.h"
#include "AmpelosGameplayAbility.h"

#include "AmpelosAbilityKit.generated.h"

USTRUCT(BlueprintType)
struct FAmpelosAbilityKitAbility
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAmpelosGameplayAbility> GameplayAbility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AbilityLevel;

};

UENUM(BlueprintType)
enum EApollonGameplayAbilityDurationPolicy
{
	Instant,
	OverTime,
	OnTick,
	OblivionTimer
};

UENUM(BlueprintType)
enum EApollonGameplayAbilityTarget
{
	T_Self UMETA(DisplayName = "Self"),
	T_LinetracedTarget UMETA(DisplayName = "Linetraced Target"),
	T_Area UMETA(DisplayName = "Area"),
	T_ScriptedTarget UMETA(DisplayName = "Scripted Target")
};

UENUM(BlueprintType)
enum EApollonGameplayAbilityModifierOp
{
	Add,
	Substract,
	Multiply,
	Devide
};

UENUM(BlueprintType)
enum EApollonATTRIBUTE
{
	CustomProperty,
	Health,
	Health_Max,
	Health_Head,
	Health_Head_Max,
	Health_Torso,
	Health_Torso_Max,
	Health_Left_LowerArm,
	Health_Left_LowerArm_Max,
	Health_Left_UpperArm,
	Health_Left_UpperArm_Max,
	Health_Right_LowerArm,
	Health_Right_LowerArm_Max,
	Health_Right_UpperArm,
	Health_Right_UpperArm_Max,
	Health_Left_LowerLeg,
	Health_Left_LowerLeg_Max,
	Health_Left_UpperLeg,
	Health_Left_UpperLeg_Max,
	Health_Right_LowerLeg,
	Health_Right_LowerLeg_Max,
	Health_Right_UpperLeg,
	Health_Right_UpperLeg_Max,
	Stamina_Max,
	Stamina_Usage,
	Stamina_Regen_Value,
	Stamina_Regen_Multiplier,
	Speed_Walk_Max,
	Speed_Crouch_Max,
	Speed_Sprint_Max,
	Speed_Swim_Max,
	Jump_Max_Z_Velocity,
	Jump_Air_Control,
	Gravity_Scale,
	Gravity_Mass,
	Gravity_GroundFriction,
	Gravity_BreackingDeceleration,
	Special_MaxWalkableAngle
};

USTRUCT(BlueprintType)
struct FApollonScaleableFloat
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCurveFloat* FloatTable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Level;

};

USTRUCT(BlueprintType)
struct FApollonGameplayEffectDefinition
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EApollonGameplayAbilityDurationPolicy> DurationPolicy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Duration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FApollonScaleableFloat DurationMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EApollonGameplayAbilityTarget> TargetType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagQuery TargetIgnoresEffectOnTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EApollonATTRIBUTE> Attribute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EApollonGameplayAbilityModifierOp> ModifierOp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FApollonScaleableFloat Magnitude;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxStackSize = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int StackoverflowCapacity = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAmpelosGameplayAbility> StackoverflowAbility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagQuery CancelAbilityOnTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagQuery AbilityIgnoresTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer AddTagsOnEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer RemoveTagsOnEffect;

};

/**
 * 
 */
UCLASS(BlueprintType)
class AMPELOS_API UAmpelosAbilityKit : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Ability Kit")
		TArray<FAmpelosAbilityKitAbility> ListOfGameplayAbilities;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Ability Kit")
		TArray<FApollonGameplayEffectDefinition> GameplayEffects;
	
};
