// yes

#include "GameDataTextFactory.h"
#include <Ampelos/GameDataText.h>

UGameDataTextFactory::UGameDataTextFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UGameDataText::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UGameDataTextFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UGameDataText* NewObjectAsset = NewObject<UGameDataText>(InParent, Class, Name, Flags | RF_Transactional);
	return NewObjectAsset;
}
