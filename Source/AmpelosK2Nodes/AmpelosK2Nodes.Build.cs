// yes

using UnrealBuildTool;

public class AmpelosK2Nodes : ModuleRules
{
	public AmpelosK2Nodes(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Ampelos", "GameplayTags", "AssetTools", "UnrealEd", "BlueprintGraph" });
		

		PrivateDependencyModuleNames.AddRange(new string[] { "Ampelos", "Core", "Engine", "AssetTools", "UnrealEd", "KismetCompiler", "BlueprintGraph" });
		
		PublicIncludePaths.AddRange(
            new string[]
            {
                "AmpelosK2Nodes/Public"
            });

        PrivateIncludePaths.AddRange(
            new string[]
            {
				"AmpelosK2Nodes/Private"
            });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
