// yes


#include "ApollonGameplayAbility.h"

// Sets default values
AApollonGameplayAbility::AApollonGameplayAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AApollonGameplayAbility::EnableTick()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AApollonGameplayAbility::DisableTick()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AApollonGameplayAbility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AApollonGameplayAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

