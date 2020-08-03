// yes


#include "AmpelosGlobals.h"

// Sets default values
AAmpelosGlobals::AAmpelosGlobals()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAmpelosGlobals::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmpelosGlobals::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AAmpelosGlobals::FileToString(FString Path, FString Folders, FString FileName)
{

	FString result;
	FString directory = Path + "/" + Folders;
	IFileManager& file = IFileManager::Get();

	if (file.DirectoryExists(*directory))
	{
		FString myFile = directory + "/" + FileName;
		FFileHelper::LoadFileToString(result, *myFile);
	}

	return result;

}

bool AAmpelosGlobals::StringToFile(FString Path, FString Folders, FString FileName, FString Data)
{

	FString fullPath = Path + "/" + Folders + "/" + FileName;

	return FFileHelper::SaveStringToFile(Data, *fullPath);

}

FString AAmpelosGlobals::FetchData(FString Path, FString Folders, FString FileName, FString Data, FString EncryptionKey)
{

	FString tempstring = Data;
	int Lenght = tempstring.Len();

	for (int i = 0; i < Lenght; i++) {
		tempstring[i] = Data[i] ^ EncryptionKey[i % ((sizeof(EncryptionKey) / sizeof(FString) + sizeof(Data)))];
	}

	return tempstring;

}
