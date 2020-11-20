// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "AmpelosGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOS_API AAmpelosGameModeBase : public AGameMode
{
	GENERATED_BODY()

public:

	UFUNCTION(Exec)
		void TestExec();
	
};
