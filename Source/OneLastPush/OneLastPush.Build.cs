// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OneLastPush : ModuleRules
{
	public OneLastPush(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate",
			"SlateCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"OneLastPush",
			"OneLastPush/Variant_Strategy",
			"OneLastPush/Variant_Strategy/UI",
			"OneLastPush/Variant_TwinStick",
			"OneLastPush/Variant_TwinStick/AI",
			"OneLastPush/Variant_TwinStick/Gameplay",
			"OneLastPush/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
