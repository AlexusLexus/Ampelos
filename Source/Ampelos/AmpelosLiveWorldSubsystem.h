// yes

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Misc/Guid.h"
#include "AmpelosLiveWorldLocationData.h"
#include "AmpelosLiveWorldLocation.h"
#include "Engine/World.h"

#include "AmpelosLiveWorldSubsystem.generated.h"

UENUM(BlueprintType)
enum EAmpelosLiveWorldEventType
{
	/*Default behaviour*/
	LWE_None,
	/*Update look of object*/
	LWE_Update,
	/*Cretae object in world*/
	LWE_Create,
	/*Delete object in world*/
	LWE_Delete,
	/*Swap Objects*/
	LWE_Swap
};

UENUM(BlueprintType)
enum EAmpelosLiveWorldUpdateType
{
	/*Make a local change in the worldm usually used for singleplayer story line*/
	Offline,
	/*Call an API to submit a change and make your way from here, usually ends with calling local change to accept it*/
	Online
};

USTRUCT(BlueprintType)
struct FAmpelosLiveWorldEntry
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGuid WorldLocationGUID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAmpelosLiveWorldLocation> LocationClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector LocationCoords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator LocationRot;

};

/**
 * 
 */
UCLASS(DisplayName = "Ampelos Live World Subsystem")
class AMPELOS_API UAmpelosLiveWorldSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Live World Subsystem Vars")
		TMap<FName, FAmpelosLiveWorldEntry> ListOfCurrentLocations;

	/*
		Create Live World Location in UWorld based of GUID and Data Asset

		*param - Data Asset with locations
		*param - GUID for location of your choise
		*param - Location in world
		*param - Rotation in world
	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|LIVE WORLD")
		bool CreateLocation(UAmpelosLiveWorldLocationData* WorldData, FGuid LocationGUID, FVector TargetLocation, FRotator TargetRotation, FName NewLocationName);

	UFUNCTION(BlueprintPure, Category = "AMPELOS|LIVE WORLD")
		bool LocationExistsInDatabase(FName TargetName);

	UFUNCTION(BlueprintPure, Category = "AMPELOS|LIVE WORLD")
		bool TestDataAssetForLocationByGUID(UAmpelosLiveWorldLocationData* WorldData, FGuid TargetGUID);

	/*
	UFUNCTION(BlueprintPure, Category = "AMPELOS|LIVE WORLD")
		bool TestDataAssetForLocationByGlobalName(UAmpelosLiveWorldLocationData* WorldData, FName TestName);
	*/

	/*
		Use this function to register location in LiseOfCurrentLocations lise in UAmpelosLiveWorldSunsystem
	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|LIVE WORLD")
		void RegisterLocation(FName TargetLocation, FAmpelosLiveWorldEntry NewLocationData);

	UFUNCTION(BlueprintCallable, Category = "AMPELOS|LIVE WORLD")
		bool UnregisterLocation(FName TargetLocation);

	/*
		Use to swap locations, duh	
	*/
	UFUNCTION(BlueprintCallable, Category = "AMPELOS|LIVE WORLD")
		bool SwapLocations(UAmpelosLiveWorldLocationData* WorldData, FGuid NewLocationGUID, FName NewLocationName, FName OldLocationName);

};
