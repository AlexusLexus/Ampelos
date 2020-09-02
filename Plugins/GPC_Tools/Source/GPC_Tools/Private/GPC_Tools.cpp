// Copyright Epic Games, Inc. All Rights Reserved.

#include "GPC_Tools.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"

#include "IAssetTypeActions.h"
#include "IAssetTools.h"
#include "AssetTypeCategories.h"
#include "Toolkits/AssetEditorManager.h"
#include "AssetActions_Timecycle.h"

#define LOCTEXT_NAMESPACE "FGPC_ToolsModule"

void FGPC_ToolsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	EAssetTypeCategories::Type GPC_Category = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("GPC Tools")), FText::FromString("GPC Tools"));
	TSharedPtr<IAssetTypeActions> Action1 = MakeShareable(new AssetActions_Timecycle(GPC_Category));
	AssetTools.RegisterAssetTypeActions(Action1.ToSharedRef());

	CreatedAssetTypeActions.Add(Action1);
	

	StyleSet = MakeShareable(new FSlateStyleSet("AmpelosTimecycle"));
	Style_Definition = MakeShareable(new FSlateStyleSet("ApollonDefinition"));
	Style_ItemDefinition = MakeShareable(new FSlateStyleSet("ApollonItemDefinition"));
	Style_AGID = MakeShareable(new FSlateStyleSet("ApollonGadgetItemDefinition"));
	Style_Playlist = MakeShareable(new FSlateStyleSet("ApollonPlaylist"));
	Style_AbilityScript = MakeShareable(new FSlateStyleSet("ApollonAbilityScript"));

	FString ContentDir = IPluginManager::Get().FindPlugin("GPC_Tools")->GetBaseDir();

	StyleSet->SetContentRoot(ContentDir);
	Style_Definition->SetContentRoot(ContentDir);
	Style_ItemDefinition->SetContentRoot(ContentDir);
	Style_AGID->SetContentRoot(ContentDir);
	Style_Playlist->SetContentRoot(ContentDir);
	Style_AbilityScript->SetContentRoot(ContentDir);

	FSlateImageBrush* ThumbnailBrush = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Resources/Icon128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Definition = new FSlateImageBrush(Style_Definition->RootToContentDir(TEXT("Resources/StarsFull128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_ItemDefinition = new FSlateImageBrush(Style_ItemDefinition->RootToContentDir(TEXT("Resources/Backpack128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_AGID = new FSlateImageBrush(Style_ItemDefinition->RootToContentDir(TEXT("Resources/Backpack128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Playlist = new FSlateImageBrush(Style_ItemDefinition->RootToContentDir(TEXT("Resources/PlaylistIcon128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_AbilityScript = new FSlateImageBrush(Style_AbilityScript->RootToContentDir(TEXT("Resources/AbilityIcon128"), TEXT(".png")), FVector2D(1000.f, 1000.f));

	if (ThumbnailBrush)
	{
		//In order to bind the thumbnail to our class we need to type ClassThumbnail.X where X is the name of the C++ class of the asset
		StyleSet->Set("ClassThumbnail.Timecycle", ThumbnailBrush);

		//Reguster the created style
		FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
	}

	if (ThumbnailBrush_Definition)
	{
		Style_Definition->Set("ClassThumbnail.ApollonDefinition", ThumbnailBrush_Definition);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Definition);
	}

	if (ThumbnailBrush_ItemDefinition)
	{
		Style_ItemDefinition->Set("ClassThumbnail.ApollonItemDefinition", ThumbnailBrush_ItemDefinition);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_ItemDefinition);
	}

	if (ThumbnailBrush_AGID)
	{
		Style_AGID->Set("ClassThumbnail.ApollonGadgetItemDefinition", ThumbnailBrush_AGID);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_AGID);
	}

	if (ThumbnailBrush_Playlist)
	{
		Style_Playlist->Set("ClassThumbnail.ApollonPlaylist", ThumbnailBrush_Playlist);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Playlist);
	}

	if (ThumbnailBrush_AbilityScript)
	{
		Style_AbilityScript->Set("ClassThumbnail.ApollonGameplayAbility", ThumbnailBrush_AbilityScript);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_AbilityScript);
	}

}

void FGPC_ToolsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
	
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

		for (auto& Action : CreatedAssetTypeActions)
		{
			AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());
		}
	}

	CreatedAssetTypeActions.Empty();
	

	FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Definition->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_ItemDefinition->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_AGID->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Playlist->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_AbilityScript->GetStyleSetName());

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGPC_ToolsModule, GPC_Tools)