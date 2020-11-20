// yes


#include "AmpelosGameModeBase.h"

void AAmpelosGameModeBase::TestExec()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Oh, hello, Test Exec!"));
	//UE_LOG(AmpelosGameMode_Base, Warning, TEXT("Used test exec successfully :)"));
}