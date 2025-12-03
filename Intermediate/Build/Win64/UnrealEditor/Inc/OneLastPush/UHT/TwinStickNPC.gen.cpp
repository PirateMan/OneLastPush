// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwinStickNPC.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTwinStickNPC() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickNPC();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickNPC_NoRegister();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickNPCDestruction_NoRegister();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickPickup_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ATwinStickNPC ************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ATwinStickNPC;
UClass* ATwinStickNPC::GetPrivateStaticClass()
{
	using TClass = ATwinStickNPC;
	if (!Z_Registration_Info_UClass_ATwinStickNPC.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TwinStickNPC"),
			Z_Registration_Info_UClass_ATwinStickNPC.InnerSingleton,
			StaticRegisterNativesATwinStickNPC,
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
	return Z_Registration_Info_UClass_ATwinStickNPC.InnerSingleton;
}
UClass* Z_Construct_UClass_ATwinStickNPC_NoRegister()
{
	return ATwinStickNPC::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ATwinStickNPC_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple enemy NPC for a Twin Stick Shooter game\n *  It's driven by an AI Controller running a behavior tree\n *  Awards points and randomly spawns pickups on death\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple enemy NPC for a Twin Stick Shooter game\nIt's driven by an AI Controller running a behavior tree\nAwards points and randomly spawns pickups on death" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[] = {
		{ "Category", "Score" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Score to award when this NPC is destroyed */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Score to award when this NPC is destroyed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupSpawnChance_MetaData[] = {
		{ "Category", "Pickup" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Percentage chance of spawning a pickup */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Percentage chance of spawning a pickup" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupClass_MetaData[] = {
		{ "Category", "Pickup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of pickup to spawn on death */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of pickup to spawn on death" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestructionProxyClass_MetaData[] = {
		{ "Category", "Destruction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of destruction proxy to spawn on death */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of destruction proxy to spawn on death" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeferredDestructionTime_MetaData[] = {
		{ "Category", "Pickup" },
		{ "ClampMax", "5" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time to wait after this NPC is hit before destroying it */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time to wait after this NPC is hit before destroying it" },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHit_MetaData[] = {
		{ "Category", "NPC" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If true, this NPC has already been hit by a projectile and is being destroyed. Exposed to BP so it can be read by StateTree */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/AI/TwinStickNPC.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If true, this NPC has already been hit by a projectile and is being destroyed. Exposed to BP so it can be read by StateTree" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ATwinStickNPC constinit property declarations ****************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Score;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PickupSpawnChance;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PickupClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_DestructionProxyClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeferredDestructionTime;
	static void NewProp_bHit_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATwinStickNPC constinit property declarations ******************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwinStickNPC>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ATwinStickNPC_Statics

// ********** Begin Class ATwinStickNPC Property Definitions ***************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickNPC, Score), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Score_MetaData), NewProp_Score_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_PickupSpawnChance = { "PickupSpawnChance", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickNPC, PickupSpawnChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupSpawnChance_MetaData), NewProp_PickupSpawnChance_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_PickupClass = { "PickupClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickNPC, PickupClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_ATwinStickPickup_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupClass_MetaData), NewProp_PickupClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_DestructionProxyClass = { "DestructionProxyClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickNPC, DestructionProxyClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_ATwinStickNPCDestruction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestructionProxyClass_MetaData), NewProp_DestructionProxyClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_DeferredDestructionTime = { "DeferredDestructionTime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickNPC, DeferredDestructionTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeferredDestructionTime_MetaData), NewProp_DeferredDestructionTime_MetaData) };
void Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_bHit_SetBit(void* Obj)
{
	((ATwinStickNPC*)Obj)->bHit = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_bHit = { "bHit", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATwinStickNPC), &Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_bHit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHit_MetaData), NewProp_bHit_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATwinStickNPC_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_Score,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_PickupSpawnChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_PickupClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_DestructionProxyClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_DeferredDestructionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickNPC_Statics::NewProp_bHit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickNPC_Statics::PropPointers) < 2048);
// ********** End Class ATwinStickNPC Property Definitions *****************************************
UObject* (*const Z_Construct_UClass_ATwinStickNPC_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickNPC_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATwinStickNPC_Statics::ClassParams = {
	&ATwinStickNPC::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATwinStickNPC_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickNPC_Statics::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickNPC_Statics::Class_MetaDataParams), Z_Construct_UClass_ATwinStickNPC_Statics::Class_MetaDataParams)
};
void ATwinStickNPC::StaticRegisterNativesATwinStickNPC()
{
}
UClass* Z_Construct_UClass_ATwinStickNPC()
{
	if (!Z_Registration_Info_UClass_ATwinStickNPC.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATwinStickNPC.OuterSingleton, Z_Construct_UClass_ATwinStickNPC_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATwinStickNPC.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATwinStickNPC);
ATwinStickNPC::~ATwinStickNPC() {}
// ********** End Class ATwinStickNPC **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickNPC_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATwinStickNPC, ATwinStickNPC::StaticClass, TEXT("ATwinStickNPC"), &Z_Registration_Info_UClass_ATwinStickNPC, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATwinStickNPC), 3079461393U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickNPC_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickNPC_h__Script_OneLastPush_1060743677{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickNPC_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_AI_TwinStickNPC_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
