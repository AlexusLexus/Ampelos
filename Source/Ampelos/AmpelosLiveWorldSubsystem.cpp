// yes


#include "AmpelosLiveWorldSubsystem.h"
#include "Kismet/GameplayStatics.h"

bool UAmpelosLiveWorldSubsystem::CreateLocation(UAmpelosLiveWorldLocationData* WorldData, FGuid LocationGUID, FVector TargetLocation, FRotator TargetRotation, FName NewLocationName)
{

	if (WorldData->WorldLocationData.Contains(LocationGUID))
	{

		FAmpelosLiveWorldLocationEntry TempStructRef = WorldData->WorldLocationData[LocationGUID];
		TSubclassOf<AAmpelosLiveWorldLocation> TempLocationRef = TempStructRef.LocationObjectRef;
		FActorSpawnParameters SpawnParams;
		FAmpelosLiveWorldEntry TempReg;

		UWorld *WRLD = GetWorld();

		WRLD->SpawnActor(TempLocationRef, &TargetLocation, &TargetRotation);

		TempReg.WorldLocationGUID.NewGuid();
		TempReg.LocationClass = TempLocationRef;
		TempReg.LocationCoords = TargetLocation;
		TempReg.LocationRot = TargetRotation;

		RegisterLocation(NewLocationName, TempReg);

	}
	else
	{
		return false;
	}

	return true;

}

bool UAmpelosLiveWorldSubsystem::LocationExistsInDatabase(FName TargetName)
{

	if (ListOfCurrentLocations.Contains(TargetName))
	{
		return true;
	}
	else
	{
		return false;
	}

	return true;

}

bool UAmpelosLiveWorldSubsystem::TestDataAssetForLocationByGUID(UAmpelosLiveWorldLocationData* WorldData, FGuid TargetGUID)
{
	
	if (WorldData->WorldLocationData.Contains(TargetGUID))
	{
		return true;
	}
	else
	{
		return false;
	}

	return true;

}

void UAmpelosLiveWorldSubsystem::RegisterLocation(FName TargetLocation, FAmpelosLiveWorldEntry NewLocationData)
{

	ListOfCurrentLocations.Add(TargetLocation, NewLocationData);

}

bool UAmpelosLiveWorldSubsystem::UnregisterLocation(FName TargetLocation)
{

	if (ListOfCurrentLocations.Contains(TargetLocation))
	{
		ListOfCurrentLocations.Remove(TargetLocation);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Red, TEXT("Failed to remove Location '") + TargetLocation.ToString() + TEXT("', because it dosen't exist."));
		return false;
	}

	return true;

}

bool UAmpelosLiveWorldSubsystem::SwapLocations(UAmpelosLiveWorldLocationData * WorldData, FGuid NewLocationGUID, FName NewLocationName, FName OldLocationName)
{
	return false;
}

/*
bool UAmpelosLiveWorldSubsystem::TestDataAssetForLocationByGlobalName(UAmpelosLiveWorldLocationData* WorldData, FName TestName)
{

	TArray<FAmpelosLiveWorldLocationEntry> TempList;
	WorldData->WorldLocationData.GenerateValueArray(TempList);

	TSubclassOf<AAmpelosLiveWorldLocation> TestRef;
	TestRef = ListOfCurrentLocations[TestName];

	int ArrLen = TempList.Num();
	int i;

	for (i = 0; i < ArrLen; i++)
	{
		if (WorldData->WorldLocationData == TSubclassOf<TestRef>)
	}

	<*-*> TODO: Compare Classes
}
*/

//void UAmpelosLiveWorldSubsystem::SwapLocation(UAmpelosLiveWorldLocationData* WorldData, FGuid NewTargetGUID, FName OldLocationName)
//{
//
//	TArray<AActor*> ListOfLocations;
//	TSubclassOf<AAmpelosLiveWorldLocation> ClassOfLocation = AAmpelosLiveWorldLocation::StaticClass();
//
//	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassOfLocation, ListOfLocations);
//
//	int i;
//
//	for (i; i < ListOfLocations.Num(); i++)
//	{
//		ListOfLocations[i]
//	}
//
//
//}

