// yes

using UnrealBuildTool;
using System.Collections.Generic;

public class AmpelosEditorTarget : TargetRules
{
	public AmpelosEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Ampelos", "AmpelosGameEditor", "AmpelosK2Nodes" } );
	}
}
