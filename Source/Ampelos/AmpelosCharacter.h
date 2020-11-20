// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GameplayTagContainer.h"
#include "AmpelosHeroType.h"
#include "AmpelosCharacterItemDefinition.h"
#include "AmpelosGadgetItemDefinition.h"
#include "AmpelosAbilityKit.h"

#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "Components/AudioComponent.h"

#include "AmpelosCharacter.generated.h"

UENUM(BlueprintType)
enum class EAmpelosCharacterType : uint8
{
	CT_Friendly UMETA(DisplayName = "Friendly"),
	CT_Enemy UMETA(DisplayName = "Enemy"),
	CT_ScriptedNPC UMETA(DisplayName = "Scripted NPC"),
	//NPC that controled by script during the event
	CT_LiveEventNPC UMETA(DisplayName = "Live Event NPC"),
	//Apollon Live ANimation Character
	CT_ALANChar UMETA(DisplayName = "ALAN NPC")
};

UCLASS()
class AMPELOS_API AAmpelosCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAmpelosCharacter();

	/*Use this function to reload character parts from current parts list, and not drom the CID*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Characters|CID & Character Parts")
		void ReloadCharacterParts();

	/*Set Character parts from CID and reload them
	* DO NOT USE!
	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Characters|CID & Character Parts")
		void SetAndReloadCIDParts();

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|Characters|CID & Character Parts")
		void SetCharacterPartsFromCID();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Type", meta = (DisplayPriority = 100))
		UAmpelosHeroType* HeroType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Type", meta = (DisplayPriority = 101))
		FAmpelosHeroParts CharacterParts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Type", meta = (DisplayPriority = 101))
		UAmpelosCharacterItemDefinition* Hero_CID UMETA(DisplayName = "Hero's CID");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Type", meta = (DisplayPriority = 101), AdvancedDisplay)
		bool bOverrideHerosCIDbyNew;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Animation", meta = (DisplayPriority = 80))
		TSubclassOf<UAnimInstance> BaseAnimClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Meta Data", meta = (DisplayPriority = 70))
		EAmpelosCharacterType CharacterType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Meta Data", meta = (DisplayPriority = 70))
		FGameplayTagContainer EmbeddedHeroTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Equipment", meta = (DisplayPriority = 60))
		UAmpelosGadgetItemDefinition* Default_Hero_Gadget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Hero Equipment", meta = (DisplayPriority = 60))
		UAmpelosAbilityKit* Default_Hero_Ability_Kit;
	//DefaultDialogueTree
	//FootstepBank

	UPROPERTY(EditAnywhere)
		UAudioComponent* S_Footsteps;

	UPROPERTY(EditAnywhere)
		UAudioComponent* S_Voice;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Base;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Torso;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Backpack;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Head;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Vest;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Hair;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Mask;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Hat;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Acc_01;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Acc_02;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SK_Acc_03;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
