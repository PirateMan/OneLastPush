// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwinStickSpawner.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTwinStickSpawner() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickNPC_NoRegister();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickSpawner();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickSpawner_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ATwinStickSpawner ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ATwinStickSpawner;
UClass* ATwinStickSpawner::GetPrivateStaticClass()
{
	using TClass = ATwinStickSpawner;
	if (!Z_Registration_Info_UClass_ATwinStickSpawner.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TwinStickSpawner"),
			Z_Registration_Info_UClass_ATwinStickSpawner.InnerSingleton,
			StaticRegisterNativesATwinStickSpawner,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ATwinStickSpawner.InnerSingleton;
}
UClass* Z_Construct_UClass_ATwinStickSpawner_NoRegister()
{
	return ATwinStickSpawner::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ATwinStickSpawner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple NPC spawner for a Twin Stick Shooter game\n */" },
#endif
		{ "IncludePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple NPC spawner for a Twin Stick Shooter game" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NPCClass_MetaData[] = {
		{ "Category", "NPC Spawner" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of NPC to spawn */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of NPC to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroupDelay_MetaData[] = {
		{ "Category", "NPC Spawner" },
		{ "ClampMax", "20" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time delay between enemy group spawns */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time delay between enemy group spawns" },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinSpawnDelay_MetaData[] = {
		{ "Category", "NPC Spawner" },
		{ "ClampMax", "2" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Min time delay between individual NPC spawns */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Min time delay between individual NPC spawns" },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpawnDelay_MetaData[] = {
		{ "Category", "NPC Spawner" },
		{ "ClampMax", "2" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Max time delay between individual NPC spawns */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Max time delay between individual NPC spawns" },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRadius_MetaData[] = {
		{ "Category", "NPC Spawner" },
		{ "ClampMax", "20" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Radius around the spawner where it can spawn NPCs */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Radius around the spawner where it can spawn NPCs" },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroupSize_MetaData[] = {
		{ "Category", "NPC Spawner" },
		{ "ClampMax", "10" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of NPCs to spawn per group */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of NPCs to spawn per group" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ATwinStickSpawner constinit property declarations ************************
	static const UECodeGen_Private::FClassPropertyParams NewProp_NPCClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnGroupDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinSpawnDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpawnDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnRadius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnGroupSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATwinStickSpawner constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwinStickSpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ATwinStickSpawner_Statics

// ********** Begin Class ATwinStickSpawner Property Definitions ***********************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_NPCClass = { "NPCClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickSpawner, NPCClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_ATwinStickNPC_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NPCClass_MetaData), NewProp_NPCClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_SpawnGroupDelay = { "SpawnGroupDelay", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickSpawner, SpawnGroupDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroupDelay_MetaData), NewProp_SpawnGroupDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_MinSpawnDelay = { "MinSpawnDelay", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickSpawner, MinSpawnDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinSpawnDelay_MetaData), NewProp_MinSpawnDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_MaxSpawnDelay = { "MaxSpawnDelay", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickSpawner, MaxSpawnDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSpawnDelay_MetaData), NewProp_MaxSpawnDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_SpawnRadius = { "SpawnRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickSpawner, SpawnRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnRadius_MetaData), NewProp_SpawnRadius_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_SpawnGroupSize = { "SpawnGroupSize", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickSpawner, SpawnGroupSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroupSize_MetaData), NewProp_SpawnGroupSize_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATwinStickSpawner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_NPCClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_SpawnGroupDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_MinSpawnDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_MaxSpawnDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_SpawnRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickSpawner_Statics::NewProp_SpawnGroupSize,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickSpawner_Statics::PropPointers) < 2048);
// ********** End Class ATwinStickSpawner Property Definitions *************************************
UObject* (*const Z_Construct_UClass_ATwinStickSpawner_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickSpawner_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATwinStickSpawner_Statics::ClassParams = {
	&ATwinStickSpawner::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATwinStickSpawner_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickSpawner_Statics::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickSpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_ATwinStickSpawner_Statics::Class_MetaDataParams)
};
void ATwinStickSpawner::StaticRegisterNativesATwinStickSpawner()
{
}
UClass* Z_Construct_UClass_ATwinStickSpawner()
{
	if (!Z_Registration_Info_UClass_ATwinStickSpawner.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATwinStickSpawner.OuterSingleton, Z_Construct_UClass_ATwinStickSpawner_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATwinStickSpawner.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATwinStickSpawner);
ATwinStickSpawner::~ATwinStickSpawner() {}
// ********** End Class ATwinStickSpawner **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickSpawner_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATwinStickSpawner, ATwinStickSpawner::StaticClass, TEXT("ATwinStickSpawner"), &Z_Registration_Info_UClass_ATwinStickSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATwinStickSpawner), 1372911404U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickSpawner_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickSpawner_h__Script_OneLastPush_1385641250{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickSpawner_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickSpawner_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
