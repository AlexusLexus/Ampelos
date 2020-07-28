// yes

using UnrealBuildTool;
using System.Collections.Generic;

public class AmpelosTarget : TargetRules
{
	public AmpelosTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Ampelos" } );
	}
}
