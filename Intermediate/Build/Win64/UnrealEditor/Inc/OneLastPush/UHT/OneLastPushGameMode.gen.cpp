// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OneLastPushGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOneLastPushGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushGameMode();
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AOneLastPushGameMode *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AOneLastPushGameMode;
UClass* AOneLastPushGameMode::GetPrivateStaticClass()
{
	using TClass = AOneLastPushGameMode;
	if (!Z_Registration_Info_UClass_AOneLastPushGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OneLastPushGameMode"),
			Z_Registration_Info_UClass_AOneLastPushGameMode.InnerSingleton,
			StaticRegisterNativesAOneLastPushGameMode,
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
	return Z_Registration_Info_UClass_AOneLastPushGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AOneLastPushGameMode_NoRegister()
{
	return AOneLastPushGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AOneLastPushGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple Game Mode for a top-down perspective game\n *  Sets the default gameplay framework classes\n *  Check the Blueprint derived class for the set values\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "OneLastPushGameMode.h" },
		{ "ModuleRelativePath", "OneLastPushGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple Game Mode for a top-down perspective game\nSets the default gameplay framework classes\nCheck the Blueprint derived class for the set values" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AOneLastPushGameMode constinit property declarations *********************
// ********** End Class AOneLastPushGameMode constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOneLastPushGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AOneLastPushGameMode_Statics
UObject* (*const Z_Construct_UClass_AOneLastPushGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOneLastPushGameMode_Statics::ClassParams = {
	&AOneLastPushGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AOneLastPushGameMode_Statics::Class_MetaDataParams)
};
void AOneLastPushGameMode::StaticRegisterNativesAOneLastPushGameMode()
{
}
UClass* Z_Construct_UClass_AOneLastPushGameMode()
{
	if (!Z_Registration_Info_UClass_AOneLastPushGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOneLastPushGameMode.OuterSingleton, Z_Construct_UClass_AOneLastPushGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOneLastPushGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AOneLastPushGameMode);
AOneLastPushGameMode::~AOneLastPushGameMode() {}
// ********** End Class AOneLastPushGameMode *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOneLastPushGameMode, AOneLastPushGameMode::StaticClass, TEXT("AOneLastPushGameMode"), &Z_Registration_Info_UClass_AOneLastPushGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOneLastPushGameMode), 57500638U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h__Script_OneLastPush_4275651270{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
