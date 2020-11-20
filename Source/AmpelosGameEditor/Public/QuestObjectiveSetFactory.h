// yes

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UnrealEd.h"
#include "QuestObjectiveSetFactory.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOSGAMEEDITOR_API UQuestObjectiveSetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:

	UQuestObjectiveSetFactory();

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

	
};
