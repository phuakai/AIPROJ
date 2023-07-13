// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AIPROJ : ModuleRules
{
	public AIPROJ(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
