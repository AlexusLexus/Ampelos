// yes

using UnrealBuildTool;

public class AmpelosGameEditor : ModuleRules
{
	public AmpelosGameEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Ampelos", "GameplayTags", "AssetTools", "UnrealEd" });
		

		PrivateDependencyModuleNames.AddRange(new string[] { "Core", "Ampelos", "AssetTools" });
		
		PublicIncludePaths.AddRange(
            new string[]
            {
                "AmpelosGameEditor/Public"
            });

        PrivateIncludePaths.AddRange(
            new string[]
            {
				"AmpelosGameEditor/Private"
            });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
