// yes

#include "QuestObjectiveFactory.h"
#include "AmpelosGameEditor.h"
#include <Ampelos/QuestObjective.h>

/*
UQuestObjectiveFactory::UQuestObjectiveFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UQuestObjective::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}
*/

UQuestObjectiveFactory::UQuestObjectiveFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UQuestObjective::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UQuestObjectiveFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UQuestObjective* NewObjectAsset = NewObject<UQuestObjective>(InParent, Class, Name, Flags | RF_Transactional);
	return NewObjectAsset;
}