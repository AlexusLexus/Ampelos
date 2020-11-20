// yes

#include "MultiSizeBrushFactory.h"
#include <Ampelos/MultiSizeBrush.h>

UMultiSizeBrushFactory::UMultiSizeBrushFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UMultiSizeBrush::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UMultiSizeBrushFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UMultiSizeBrush* NewObjectAsset = NewObject<UMultiSizeBrush>(InParent, Class, Name, Flags | RF_Transactional);
	return NewObjectAsset;
}
