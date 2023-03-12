// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASFramework : ModuleRules
{
	public GASFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });

        PublicIncludePaths.Add("GASFramework/");

        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks" });
    }
}
