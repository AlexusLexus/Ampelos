// yes

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmpelosGlobalQuestGraph.generated.h"

UCLASS()
class AMPELOS_API AAmpelosGlobalQuestGraph : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmpelosGlobalQuestGraph();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "AMPELOS|Quest Graph")
		void GraphUpdate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
