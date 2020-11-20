//yes

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"

//DECLARE_LOG_CATEGORY_EXTERN(AmpelosK2Nodes, All, All);

class FAmpelosK2NodesModule : public IModuleInterface
{
	
public:

    virtual void StartupModule() override;

    virtual void ShutdownModule() override;

};