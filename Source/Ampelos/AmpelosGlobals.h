// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

UCLASS(Config = Game)
class AMPELOS_API AAmpelosGlobals : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmpelosGlobals();

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
