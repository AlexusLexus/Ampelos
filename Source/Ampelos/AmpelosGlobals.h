// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <Runtime\Core\Public\Misc\Paths.h>
#include <Runtime\Core\Public\HAL\PlatformFilemanager.h>
#include "AmpelosItemDefinition.h"
#include "GameplayTagContainer.h"

#include "AmpelosGlobals.generated.h"

//Use this macro if you're lazy and don't want to write this shit too many times
#define STRUCT_PROPERTY UPROPERTY(EditAnywhere, BlueprintReadWrite)


UENUM(BlueprintType)
enum class EAmpelosCustomPartType : uint8
{
	CPT_Head UMETA(DisplayName = "Head"),
	CPT_Body UMETA(DisplayName = "Body"),
	CPT_Vest UMETA(DisplayName = "Vest"),
	CPT_Hair UMETA(DisplayName = "Hair"),
	CPT_Mask UMETA(DisplayName = "Mask"),
	CPT_Hat UMETA(DisplayName = "Hat"),
	CPT_Backpack UMETA(DisplayName = "Backpack"),
	CPT_Acc_01 UMETA(DisplayName = "Acc 01"),
	CPT_Acc_02 UMETA(DisplayName = "Acc 02"),
	CPT_Acc_03 UMETA(DisplayName = "Acc 03")
};


UENUM(BlueprintType)
enum EAmpelosBuildType
{
	DeveloperBuild UMETA(DisplayName = "Developer Build"),
	ShippingBuild UMETA(DisplayName = "Shipping Build"),
	AnimviewerBuild UMETA(DisplayName = "ALAN Animviewer Build"),
	WalkingSimBuild UMETA(DsiplayName = "Walking Sim Build"),
	PreviewBuild UMETA(DsiplayName = "Preview Build")
};

USTRUCT(BlueprintType)
struct FAmpelosGeoTrecker
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString GeoName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Lenght;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Widght;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LineThickness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString LinkedToLevel;

};

USTRUCT(BlueprintType)
struct FAmpelosSubSlotDefinition
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* ItemDef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Quantity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer SubSlotTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SubSlotLinkedToSlot;

};

USTRUCT(BlueprintType)
struct FAmpelosSlotDefinition
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAmpelosItemDefinition* ItemDefinition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAmpelosSubSlotDefinition> Subslots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayTagContainer SlotTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SlotLinkedToSlot;

};

UCLASS(Config = Game)
class AMPELOS_API AAmpelosGlobals : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmpelosGlobals();

	//UFUNCTION(BlueprintCallable, Category = "AMPELOS|Inventory V2")
	//void FindItemsInInventory(TArray<FAmpelosSlotDefinition> InventoryArr, UAmpelosItemDefinition* ItemToSearch, bool& bFound, int& FoundIndex);

	/*
	 *
	 *	Use this function to convert file to FString
	 *
	 *	@param Path - Path to file (use GetProjectDir() to fill this)
	 *	@param Fodlers - Folder path that will be added to 'Path' (example - LiveAnim/Config) and don't add '/' at the end
	 *	@param FileName - Name of the file
	 *
	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|File I/O", meta = (Keywords = "file write overwrite vlad", DisplayName = "File To String"))
		static FString FileToString(FString Path, FString Folders, FString FileName);

	/*
	 *
	 *	Use this function to confert FString to file
	 *
	 *	@param Path - Path to file (use GetProjectDir() to fill this)
	 *	@param Fodlers - Folder path that will be added to 'Path' (example - LiveAnim/Config) and don't add '/' at the end
	 *	@param FileName - Name of the file
	 *	@param Data - strinf that will be saved
	 *
	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|File I/O", meta = (Keywords = "file read convert vlad", DisplayName = "String To File"))
		static bool StringToFile(FString Path, FString Folders, FString FileName, FString Data);

	/*
	 *
	 *	Use this function to encrypt or decrypt FString
     *
	 *	@param Path - Path to file (use GetProjectDir() to fill this)
	 *	@param Fodlers - Folder path that will be added to 'Path' (example - LiveAnim/Config) and don't add '/' at the end
	 *	@param FileName - Name of the file
	 *	@param Data - strinf that will be saved
	 *	@param EncryptionKey - Encryption key that will be used to encrypt/decrypt data
	 *
	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|File I/O", meta = (Keywords = "file encryption XOR vlad", DisplayName = "Fetch Data"))
		static FString FetchData(FString Path, FString Folders, FString FileName, FString Data, FString EncryptionKey);

	UFUNCTION(BlueprintImplementableEvent, Category = "Ampelos|Globals")
		int GetBuildNum();
	UFUNCTION(BlueprintImplementableEvent, Category = "Ampelos|Globals")
		int GetVersionNum();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Version", config)
		int BuildNum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Version", config)
		FString VersionNum;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals", config)
		FName WorldMapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals", config)
		FName ParadiseWorldMapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals", config)
		FName FrontendWorldMapName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals", config)
		TEnumAsByte<EAmpelosBuildType> BuildType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals", config)
		TArray<FString> BlacklistedItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals", config)
		TArray<FAmpelosGeoTrecker> GeoTreckerList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Setups", config)
		TArray<FString> BeginPlayCommandList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultMaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultRegenHealthValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultRegenHealthTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultRegenHealthMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultMaxStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultStaminaCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultStaminaRegenDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultStaminaUsageMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultStaminaTimerFunc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultGlobalStaminaMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultGlobalStaminaRegenMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Stats", config)
		float DefaultMaxWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Graphics Settings", config)
		TArray<FString> LowSettingsPresetCommands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Graphics Settings", config)
		TArray<FString> MediumSettingsPresetCommands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Graphics Settings", config)
		TArray<FString> HighSettingsPresetCommands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Graphics Settings", config)
		TArray<FString> VeryHighSettingsPresetCommands;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Gameplay Settings", config)
		bool bAllowJumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Gameplay Settings", config)
		float MinCameraPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Globals|Gameplay Settings", config)
		float MaxCameraPitch;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
