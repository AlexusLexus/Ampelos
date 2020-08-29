// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Misc/Guid.h"

#include "AmpelosLiveWorldLocation.generated.h"

UCLASS()
class AMPELOS_API AAmpelosLiveWorldLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmpelosLiveWorldLocation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Live World Settings")
		FName LocationName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ampelos Live World Settings")
		FGuid LocationWorldGUID;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
