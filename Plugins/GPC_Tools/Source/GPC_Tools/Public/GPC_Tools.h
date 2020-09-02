// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Styling/SlateStyle.h"
#include "IAssetTypeActions.h"

//#include <SlateStyle.h>

class FGPC_ToolsModule : public IModuleInterface
{
public:

	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;

	TSharedPtr<FSlateStyleSet> StyleSet;
	TSharedPtr<FSlateStyleSet> Style_Definition;
	TSharedPtr<FSlateStyleSet> Style_ItemDefinition;
	TSharedPtr<FSlateStyleSet> Style_AGID;
	TSharedPtr<FSlateStyleSet> Style_Playlist;
	TSharedPtr<FSlateStyleSet> Style_AbilityScript;

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
