// yes

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UnrealEd.h"
#include "QuestObjectiveFactory.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOSGAMEEDITOR_API UQuestObjectiveFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:

	UQuestObjectiveFactory();

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

	
};
