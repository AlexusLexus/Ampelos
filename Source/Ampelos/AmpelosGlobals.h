// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime\Core\Public\Misc\Paths.h>
#include <Runtime\Core\Public\HAL\PlatformFilemanager.h>
#include "AmpelosGlobals.generated.h"

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

UCLASS(Config = Game)
class AMPELOS_API AAmpelosGlobals : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmpelosGlobals();

	/*

		Use this function to convert file to FString

		@param Path - Path to file (use GetProjectDir() to fill this)
		@param Fodlers - Folder path that will be added to 'Path' (example - LiveAnim/Config) and don't add '/' at the end
		@param FileName - Name of the file

	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|File I/O", meta = (Keywords = "file write overwrite vlad", DisplayName = "File To String"))
		static FString FileToString(FString Path, FString Folders, FString FileName);

	/*

		Use this function to confert FString to file

		@param Path - Path to file (use GetProjectDir() to fill this)
		@param Fodlers - Folder path that will be added to 'Path' (example - LiveAnim/Config) and don't add '/' at the end
		@param FileName - Name of the file
		@param Data - strinf that will be saved

	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|File I/O", meta = (Keywords = "file read convert vlad", DisplayName = "String To File"))
		static bool StringToFile(FString Path, FString Folders, FString FileName, FString Data);

	/*

		Use this function to encrypt or decrypt FString

		@param Path - Path to file (use GetProjectDir() to fill this)
		@param Fodlers - Folder path that will be added to 'Path' (example - LiveAnim/Config) and don't add '/' at the end
		@param FileName - Name of the file
		@param Data - strinf that will be saved
		@param EncryptionKey - Encryption key that will be used to encrypt/decrypt data

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
