// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class FutilityTarget : TargetRules
{
	public FutilityTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
        ExtraModuleNames.AddRange(new string[] { "Futility" });
		//bUsePCHFiles = false;
		//bUseUnityBuild = false;
    }

	//
	// TargetRules interface.
	//

	/*public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "Futility" } );
	}*/
}
