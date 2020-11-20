//yes

#include "AmpelosGameEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"

#include "IAssetTypeActions.h"
#include "IAssetTools.h"
#include "AssetTypeCategories.h"
#include "Toolkits/AssetEditorManager.h"

#include "AssetActions_AmpelosPlaylist.h"
#include "AssetActions_ItemDefinition.h"
#include "AssetActions_Gadget.h"
#include "AssetActions_WeaponRanged.h"
#include "AssetActions_WeaponMelee.h"
#include "AssetActions_Token.h"
#include "AssetActions_Ammo.h"
#include "AssetActions_Prop.h"
#include "AssetActions_Badge.h"
#include "AssetActions_Quest.h"
#include "AssetActions_AbilityKit.h"
#include "AssetActions_MultiSizeBrush.h"
#include "AssetActions_QuestBundle.h"
#include "AssetActions_Character.h"
#include "AssetActions_GameDataFloat.h"
#include "AssetActions_GameDataText.h"
#include "AssetActions_Hero.h"
#include "AssetActions_Objective.h"
#include "AssetActions_ObjectiveSet.h"

#define LOCTEXT_NAMESPACE "FAmpelosGameEditorModule"

//DEFINE_LOG_CATEGORY(AmpelosGameEditor);

void FAmpelosGameEditorModule::StartupModule()
{
	
    //UE_LOG(AmpelosEditor, Warning, TEXT("AmpelosGameEditor: Log Started"));

	/*	ASSET TYPE ACTIONS*/

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	EAssetTypeCategories::Type AmpelosGameEditor_Category = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("GPC Tools")), FText::FromString("GPC Tools"));

	//UAmpelosPlaylist AssetActions -> return FColor(252, 161, 25)
	TSharedPtr<IAssetTypeActions> Action1 = MakeShareable(new AssetActions_AmpelosPlaylist(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action1.ToSharedRef());
	//UAmpelosItemDefinition AssetActions -> return FColor(30, 230, 100)
	TSharedPtr<IAssetTypeActions> Action2 = MakeShareable(new AssetActions_ItemDefinition(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action2.ToSharedRef());
	//UAmpelosGadgetItemDefinition AssetActions -> return FColor(250, 210, 10)
	TSharedPtr<IAssetTypeActions> Action3 = MakeShareable(new AssetActions_Gadget(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action3.ToSharedRef());
	//UAmpelosWeaponRangedDefinition AssetActions -> return FColor(0, 102, 204)
	TSharedPtr<IAssetTypeActions> Action4 = MakeShareable(new AssetActions_WeaponRanged(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action4.ToSharedRef());
	//UAmpelosWeaponMeleeItemDefinition AssetActions -> return FColor(102, 178, 255)
	TSharedPtr<IAssetTypeActions> Action5 = MakeShareable(new AssetActions_WeaponMelee(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action5.ToSharedRef());
	//UAmpelosTokenType AssetActions -> return FColor(0, 153, 153)
	TSharedPtr<IAssetTypeActions> Action6 = MakeShareable(new AssetActions_Token(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action6.ToSharedRef());
	//UAmpelosAmmoItemDefinition AssetActions -> return FColor(204, 0, 102)
	TSharedPtr<IAssetTypeActions> Action7 = MakeShareable(new AssetActions_Ammo(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action7.ToSharedRef());
	//UAmpelosPropItemDefinition AssetActions return -> FColor(250, 210, 140)
	TSharedPtr<IAssetTypeActions> Action8 = MakeShareable(new AssetActions_Prop(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action8.ToSharedRef());
	//UAmpelosBadgeItemDefinition AssetActions return -> FColor(100, 0, 200)
	TSharedPtr<IAssetTypeActions> Action9 = MakeShareable(new AssetActions_Badge(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action9.ToSharedRef());
	//UAmpelosQuestItemDefinition AssetActions return -> FColor(0, 255, 255)
	TSharedPtr<IAssetTypeActions> Action10 = MakeShareable(new AssetActions_Quest(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action10.ToSharedRef());
	//UAmpelosAbilityKit AssetActions return -> FColor (255, 25, 25)
	TSharedPtr<IAssetTypeActions> Action11 = MakeShareable(new AssetActions_AbilityKit(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action11.ToSharedRef());
	//UMultiSizebBrush
	TSharedPtr<IAssetTypeActions> Action12 = MakeShareable(new AssetActions_MultiSizeBrush(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action12.ToSharedRef());
	//UAmpelosQuestBundleItemDefinition
	TSharedPtr<IAssetTypeActions> Action13 = MakeShareable(new AssetActions_QuestBundle(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action13.ToSharedRef());
	//UAmpelosCharacterItemDefinition
	TSharedPtr<IAssetTypeActions> Action14 = MakeShareable(new AssetActions_Character(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action14.ToSharedRef());
	//UGameDataFloat
	TSharedPtr<IAssetTypeActions> Action15 = MakeShareable(new AssetActions_GameDataFloat(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action15.ToSharedRef());
	//UGameDataText
	TSharedPtr<IAssetTypeActions> Action16 = MakeShareable(new AssetActions_GameDataText(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action16.ToSharedRef());
	//UAmpelosHeroType
	TSharedPtr<IAssetTypeActions> Action17 = MakeShareable(new AssetActions_Hero(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action17.ToSharedRef());
	//UQuestObjective
	TSharedPtr<IAssetTypeActions> Action18 = MakeShareable(new AssetActions_Objective(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action18.ToSharedRef());
	//UQuestObjectiveSet
	TSharedPtr<IAssetTypeActions> Action19 = MakeShareable(new AssetActions_ObjectiveSet(AmpelosGameEditor_Category));
	AssetTools.RegisterAssetTypeActions(Action19.ToSharedRef());

	CreatedAssetTypeActions.Add(Action1);
	CreatedAssetTypeActions.Add(Action2);
	CreatedAssetTypeActions.Add(Action3);
	CreatedAssetTypeActions.Add(Action4);
	CreatedAssetTypeActions.Add(Action5);
	CreatedAssetTypeActions.Add(Action6);
	CreatedAssetTypeActions.Add(Action7);
	CreatedAssetTypeActions.Add(Action8);
	CreatedAssetTypeActions.Add(Action9);
	CreatedAssetTypeActions.Add(Action10);
	CreatedAssetTypeActions.Add(Action11);
	CreatedAssetTypeActions.Add(Action12);
	CreatedAssetTypeActions.Add(Action13);
	CreatedAssetTypeActions.Add(Action14);
	CreatedAssetTypeActions.Add(Action15);
	CreatedAssetTypeActions.Add(Action16);
	CreatedAssetTypeActions.Add(Action17);
	CreatedAssetTypeActions.Add(Action18);
	CreatedAssetTypeActions.Add(Action19);

	/*-------------------------------------------------------------------------*/

	/*	CUSTOM FSLATESTYLE THUMBNAILS*/

	//FString ContentDir = IPluginManager::Get().FindPlugin("Ampelos")->GetBaseDir();
	FString ContentDir = "E:\\Programs\\Epics\\UE4_Projects\\Ampelos";

	Style_ItemDefinition = MakeShareable(new FSlateStyleSet("ItemDefinitionStyle"));
	Style_Gadget = MakeShareable(new FSlateStyleSet("GadgetItemDefinitionStyle"));
	Style_WeaponRanged = MakeShareable(new FSlateStyleSet("WeaponRangedItemDefinitionStyle"));
	Style_Playlist = MakeShareable(new FSlateStyleSet("AmpelosPlaylist"));
	Style_WeaponMelee = MakeShareable(new FSlateStyleSet("WeaponMeleeItemDefinition"));
	Style_Token = MakeShareable(new FSlateStyleSet("TokenType"));
	Style_Ammo = MakeShareable(new FSlateStyleSet("AmmoItemDefinition"));
	Style_Prop = MakeShareable(new FSlateStyleSet("PropItemDefinition"));
	Style_Badge = MakeShareable(new FSlateStyleSet("BadgeItemDefinition"));
	Style_Quest = MakeShareable(new FSlateStyleSet("QuestItemDefiniton"));
	Style_MultiSizeBrush = MakeShareable(new FSlateStyleSet("MultiSizeBrushAsset"));
	Style_QuestBundle = MakeShareable(new FSlateStyleSet("QuestBundleItemDefinition"));
	Style_Character = MakeShareable(new FSlateStyleSet("CharacterItemDefinition"));
	Style_GameDataFloat = MakeShareable(new FSlateStyleSet("GameDataFloatStyle"));
	Style_GameDataText = MakeShareable(new FSlateStyleSet("GameDataTextStyle"));
	Style_Hero = MakeShareable(new FSlateStyleSet("HeroTypeStyle"));

	Style_ItemDefinition->SetContentRoot(ContentDir);
	Style_Gadget->SetContentRoot(ContentDir);
	Style_WeaponRanged->SetContentRoot(ContentDir);
	Style_Playlist->SetContentRoot(ContentDir);
	Style_WeaponMelee->SetContentRoot(ContentDir);
	Style_Token->SetContentRoot(ContentDir);
	Style_Ammo->SetContentRoot(ContentDir);
	Style_Prop->SetContentRoot(ContentDir);
	Style_Badge->SetContentRoot(ContentDir);
	Style_Quest->SetContentRoot(ContentDir);
	Style_MultiSizeBrush->SetContentRoot(ContentDir);
	Style_QuestBundle->SetContentRoot(ContentDir);
	Style_Character->SetContentRoot(ContentDir);
	Style_GameDataFloat->SetContentRoot(ContentDir);
	Style_GameDataText->SetContentRoot(ContentDir);
	Style_Hero->SetContentRoot(ContentDir);

	FSlateImageBrush* ThumbnailBrush_ItemDefinition = new FSlateImageBrush(Style_ItemDefinition->RootToContentDir(TEXT("Resources/Backpack128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Gadget = new FSlateImageBrush(Style_Gadget->RootToContentDir(TEXT("Resources/Gadget128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_WeaponRanged = new FSlateImageBrush(Style_WeaponRanged->RootToContentDir(TEXT("Resources/WeaponRanged128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Playlist = new FSlateImageBrush(Style_Playlist->RootToContentDir(TEXT("Resources/PlaylistIcon128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_WeaponMelee = new FSlateImageBrush(Style_WeaponMelee->RootToContentDir(TEXT("Resources/WeaponMelee128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Token = new FSlateImageBrush(Style_Token->RootToContentDir(TEXT("Resources/Token128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Ammo = new FSlateImageBrush(Style_Ammo->RootToContentDir(TEXT("Resources/Ammo128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Prop = new FSlateImageBrush(Style_Prop->RootToContentDir(TEXT("Resources/Prop128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Badge = new FSlateImageBrush(Style_Badge->RootToContentDir(TEXT("Resources/Trophy128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Quest = new FSlateImageBrush(Style_Quest->RootToContentDir(TEXT("Resources/QuestIcon128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_MultiSizeBrush = new FSlateImageBrush(Style_MultiSizeBrush->RootToContentDir(TEXT("Resources/MultiSizeBrush128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_QuestBundle = new FSlateImageBrush(Style_Quest->RootToContentDir(TEXT("Resources/QuestIcon128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Character = new FSlateImageBrush(Style_Character->RootToContentDir(TEXT("Resources/Char128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_GameDataFloat = new FSlateImageBrush(Style_GameDataFloat->RootToContentDir(TEXT("Resources/Float128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_GameDataText = new FSlateImageBrush(Style_GameDataText->RootToContentDir(TEXT("Resources/Text128"), TEXT(".png")), FVector2D(128.f, 128.f));
	FSlateImageBrush* ThumbnailBrush_Hero = new FSlateImageBrush(Style_Character->RootToContentDir(TEXT("Resources/Char128"), TEXT(".png")), FVector2D(128.f, 128.f));


	if (ThumbnailBrush_ItemDefinition)
	{
		Style_ItemDefinition->Set("ClassThumbnail.AmpelosItemDefinition", ThumbnailBrush_ItemDefinition);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_ItemDefinition);
	}

	if (ThumbnailBrush_Gadget)
	{
		Style_Gadget->Set("ClassThumbnail.AmpelosGadgetItemDefinition", ThumbnailBrush_Gadget);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Gadget);
	}

	if (ThumbnailBrush_WeaponRanged)
	{
		Style_WeaponRanged->Set("ClassThumbnail.AmpelosWeaponRangedDefinition", ThumbnailBrush_WeaponRanged);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_WeaponRanged);
	}

	if (ThumbnailBrush_Playlist)
	{
		Style_Playlist->Set("ClassThumbnail.AmpelosPlaylist", ThumbnailBrush_Playlist);
		//Style_Playlist->Set("ClassThumbnail.AmpelosGlobalQuestGraph", ThumbnailBrush_Playlist);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Playlist);
	}

	if (ThumbnailBrush_WeaponMelee)
	{
		Style_WeaponMelee->Set("ClassThumbnail.AmpelosWeaponMeleeDefinition", ThumbnailBrush_WeaponMelee);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_WeaponMelee);
	}

	if (ThumbnailBrush_Token)
	{
		Style_Token->Set("ClassThumbnail.AmpelosTokenType", ThumbnailBrush_Token);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Token);
	}

	if (ThumbnailBrush_Ammo)
	{
		Style_Ammo->Set("ClassThumbnail.AmpelosAmmoItemDefinition", ThumbnailBrush_Ammo);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Ammo);
	}

	if (ThumbnailBrush_Prop)
	{
		Style_Prop->Set("ClassThumbnail.AmpelosPropItemDefinition", ThumbnailBrush_Prop);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Prop);
	}

	if (ThumbnailBrush_Badge)
	{
		Style_Badge->Set("ClassThumbnail.AmpelosBadgeItemDefinition", ThumbnailBrush_Badge);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Badge);
	}

	if (ThumbnailBrush_Quest)
	{
		Style_Quest->Set("ClassThumbnail.AmpelosQuestItemDefinition", ThumbnailBrush_Quest);
		//Style_Quest->Set("ClassThumbnail.Quest", ThumbnailBrush_Quest);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Quest);
	}

	if (ThumbnailBrush_MultiSizeBrush)
	{
		Style_MultiSizeBrush->Set("ClassThumbnail.MultiSizeBrush", ThumbnailBrush_MultiSizeBrush);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_MultiSizeBrush);
	}

	if (ThumbnailBrush_QuestBundle)
	{
		Style_QuestBundle->Set("ClassThumbnail.AmpelosQuestBundleDefinition", ThumbnailBrush_QuestBundle);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_QuestBundle);
	}

	if (ThumbnailBrush_Character)
	{
		Style_Character->Set("ClassThumbnail.AmpelosCharacterItemDefinition", ThumbnailBrush_Character);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Character);
	}

	if (ThumbnailBrush_GameDataFloat)
	{
		Style_GameDataFloat->Set("ClassThumbnail.GameDataFloat", ThumbnailBrush_GameDataFloat);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_GameDataFloat);
	}

	if (ThumbnailBrush_GameDataText)
	{
		Style_GameDataText->Set("ClassThumbnail.GameDataText", ThumbnailBrush_GameDataText);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_GameDataText);
	}

	if (ThumbnailBrush_Hero)
	{
		Style_Hero->Set("ClassThumbnail.AmpelosHeroType", ThumbnailBrush_Hero);
		FSlateStyleRegistry::RegisterSlateStyle(*Style_Hero);
	}

}

void FAmpelosGameEditorModule::ShutdownModule()
{
	
    //UE_LOG(AmpelosEditor, Warning, TEXT("AmpelosGameEditor: Log Ended"));

	/*	ASSET TYPE ACTIONS*/

	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

		for (auto& Action : CreatedAssetTypeActions)
		{
			AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());
		}
	}

	CreatedAssetTypeActions.Empty();
	
	/*------------------------------------------------------------------------*/

	/*	CUSTOM FSLATESTYLE THUMBNAILS*/

	FSlateStyleRegistry::UnRegisterSlateStyle(Style_ItemDefinition->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Gadget->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_WeaponRanged->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Playlist->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_WeaponMelee->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Token->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Ammo->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Prop->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Badge->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Quest->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_MultiSizeBrush->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_QuestBundle->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Character->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_GameDataFloat->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_GameDataText->GetStyleSetName());
	FSlateStyleRegistry::UnRegisterSlateStyle(Style_Hero->GetStyleSetName());

}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAmpelosGameEditorModule, AmpelosGameEditor);
