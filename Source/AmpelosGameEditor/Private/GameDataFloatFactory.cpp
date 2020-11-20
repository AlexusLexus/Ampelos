// yes

#include "GameDataFloatFactory.h"
#include <Ampelos/GameDataFloat.h>

UGameDataFloatFactory::UGameDataFloatFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UGameDataFloat::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UGameDataFloatFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UGameDataFloat* NewObjectAsset = NewObject<UGameDataFloat>(InParent, Class, Name, Flags | RF_Transactional);
	return NewObjectAsset;
}
