// yes

#include "QuestObjectiveSetFactory.h"
#include "AmpelosGameEditor.h"
#include <Ampelos/QuestObjectiveSet.h>
/*
UQuestObjectiveSetFactory::UQuestObjectiveSetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UQuestObjectiveSet::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}
*/
UQuestObjectiveSetFactory::UQuestObjectiveSetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UQuestObjectiveSet::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UQuestObjectiveSetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UQuestObjectiveSet* NewObjectAsset = NewObject<UQuestObjectiveSet>(InParent, Class, Name, Flags | RF_Transactional);
	return NewObjectAsset;
}