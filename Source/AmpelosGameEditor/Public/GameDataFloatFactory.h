// yes

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UnrealEd.h"
#include "GameDataFloatFactory.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOSGAMEEDITOR_API UGameDataFloatFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:

	UGameDataFloatFactory();

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	
};
