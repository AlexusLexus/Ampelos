// yes


#include "AmpelosGameplayAbility.h"

// Sets default values
AAmpelosGameplayAbility::AAmpelosGameplayAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAmpelosGameplayAbility::BeginPlay()
{
	Super::BeginPlay();
	OnAbilityStart();
	
}

// Called every frame
void AAmpelosGameplayAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmpelosGameplayAbility::EnableTick()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAmpelosGameplayAbility::DisableTick()
{
	PrimaryActorTick.bCanEverTick = false;
}
