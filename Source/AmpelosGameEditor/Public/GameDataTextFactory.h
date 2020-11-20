// yes

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UnrealEd.h"
#include "GameDataTextFactory.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOSGAMEEDITOR_API UGameDataTextFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:

	UGameDataTextFactory();

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	
};
