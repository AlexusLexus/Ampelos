//yes

#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"
#include "Styling/SlateStyle.h"
#include "IAssetTypeActions.h"

//DECLARE_LOG_CATEGORY_EXTERN(AmpelosGameEditor, All, All);

class FAmpelosGameEditorModule : public IModuleInterface
{
	
public:

	//AssetTypeActions
	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;

	//Custom Class Thumbnails
	TSharedPtr<FSlateStyleSet> Style_ItemDefinition;
	TSharedPtr<FSlateStyleSet> Style_Playlist;
	TSharedPtr<FSlateStyleSet> Style_Quest;
	TSharedPtr<FSlateStyleSet> Style_Gadget;
	TSharedPtr<FSlateStyleSet> Style_WeaponRanged;
	TSharedPtr<FSlateStyleSet> Style_WeaponMelee;
	TSharedPtr<FSlateStyleSet> Style_Token;
	TSharedPtr<FSlateStyleSet> Style_Ammo;
	TSharedPtr<FSlateStyleSet> Style_Prop;
	TSharedPtr<FSlateStyleSet> Style_Badge;
	TSharedPtr<FSlateStyleSet> Style_MultiSizeBrush;
	TSharedPtr<FSlateStyleSet> Style_QuestBundle;
	TSharedPtr<FSlateStyleSet> Style_Character;
	TSharedPtr<FSlateStyleSet> Style_GameDataFloat;
	TSharedPtr<FSlateStyleSet> Style_GameDataText;
	TSharedPtr<FSlateStyleSet> Style_Hero;


    virtual void StartupModule() override;

    virtual void ShutdownModule() override;

};