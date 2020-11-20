//yes

#include <AmpelosK2Nodes/Public/AmpelosK2Nodes.h>
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

#define LOCTEXT_NAMESPACE "FAmpelosK2NodesModule"

//DEFINE_LOG_CATEGORY(AmpelosK2Nodes);

void FAmpelosK2NodesModule::StartupModule()
{

}

void FAmpelosK2NodesModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAmpelosK2NodesModule, AmpelosK2Nodes);
