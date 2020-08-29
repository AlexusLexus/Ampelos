// yes


#include "Quest.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

//I'll left it here for good
/*
void AQuest::Update()
{

	switch (Stage)
	{
	default:
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Quest hit default case!!!"));
		break;
	}

}
*/

int AQuest::GetStage()
{
	return Stage;
}

void AQuest::AdvanceStage(int AdvanceScale)
{
	Stage = Stage + AdvanceScale;
}

void AQuest::FinishQuest()
{
	Stage = ComplitionStage;
}

void AQuest::FailQuest()
{
	Stage = FailStage;
}

void AQuest::SetStage(int TargetStage)
{
	Stage = TargetStage;
}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

