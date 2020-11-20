// yes

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UnrealEd.h"
#include "MultiSizeBrushFactory.generated.h"

/**
 * 
 */
UCLASS()
class AMPELOSGAMEEDITOR_API UMultiSizeBrushFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:

	UMultiSizeBrushFactory();

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	
};
