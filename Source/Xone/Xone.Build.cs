// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Xone : ModuleRules
{
	public Xone(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] 
            {
                "Xone"
            });

        PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput" 
		});

        PrivateDependencyModuleNames.AddRange(new string[]
{
            "Slate",
            "SlateCore",
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks"
		});
    }
}
