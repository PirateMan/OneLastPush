// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OneLastPushPlayerController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOneLastPushPlayerController() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushCharacter_NoRegister();
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushPlayerController();
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushPlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AOneLastPushPlayerController Function OnPawnDestroyed ********************
struct Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics
{
	struct OneLastPushPlayerController_eventOnPawnDestroyed_Parms
	{
		AActor* DestroyedActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called if the possessed pawn is destroyed */" },
#endif
		{ "ModuleRelativePath", "OneLastPushPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called if the possessed pawn is destroyed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnPawnDestroyed constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DestroyedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnPawnDestroyed constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnPawnDestroyed Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::NewProp_DestroyedActor = { "DestroyedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneLastPushPlayerController_eventOnPawnDestroyed_Parms, DestroyedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::NewProp_DestroyedActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::PropPointers) < 2048);
// ********** End Function OnPawnDestroyed Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOneLastPushPlayerController, nullptr, "OnPawnDestroyed", 	Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::OneLastPushPlayerController_eventOnPawnDestroyed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::OneLastPushPlayerController_eventOnPawnDestroyed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOneLastPushPlayerController::execOnPawnDestroyed)
{
	P_GET_OBJECT(AActor,Z_Param_DestroyedActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPawnDestroyed(Z_Param_DestroyedActor);
	P_NATIVE_END;
}
// ********** End Class AOneLastPushPlayerController Function OnPawnDestroyed **********************

// ********** Begin Class AOneLastPushPlayerController *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AOneLastPushPlayerController;
UClass* AOneLastPushPlayerController::GetPrivateStaticClass()
{
	using TClass = AOneLastPushPlayerController;
	if (!Z_Registration_Info_UClass_AOneLastPushPlayerController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OneLastPushPlayerController"),
			Z_Registration_Info_UClass_AOneLastPushPlayerController.InnerSingleton,
			StaticRegisterNativesAOneLastPushPlayerController,
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
	return Z_Registration_Info_UClass_AOneLastPushPlayerController.InnerSingleton;
}
UClass* Z_Construct_UClass_AOneLastPushPlayerController_NoRegister()
{
	return AOneLastPushPlayerController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AOneLastPushPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple Player Controller for a Twin Stick Shooter game\n *  Manages input mapping contexts\n *  Respawns the pawn if it is destroyed\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "OneLastPushPlayerController.h" },
		{ "ModuleRelativePath", "OneLastPushPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple Player Controller for a Twin Stick Shooter game\nManages input mapping contexts\nRespawns the pawn if it is destroyed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContexts_MetaData[] = {
		{ "Category", "Input|Input Mappings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Mapping Contexts */" },
#endif
		{ "ModuleRelativePath", "OneLastPushPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Mapping Contexts" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterClass_MetaData[] = {
		{ "Category", "Respawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Character class to respawn when the possessed pawn is destroyed */" },
#endif
		{ "ModuleRelativePath", "OneLastPushPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character class to respawn when the possessed pawn is destroyed" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AOneLastPushPlayerController constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContexts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultMappingContexts;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CharacterClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AOneLastPushPlayerController constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnPawnDestroyed"), .Pointer = &AOneLastPushPlayerController::execOnPawnDestroyed },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AOneLastPushPlayerController_OnPawnDestroyed, "OnPawnDestroyed" }, // 3118786215
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOneLastPushPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AOneLastPushPlayerController_Statics

// ********** Begin Class AOneLastPushPlayerController Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushPlayerController_Statics::NewProp_DefaultMappingContexts_Inner = { "DefaultMappingContexts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOneLastPushPlayerController_Statics::NewProp_DefaultMappingContexts = { "DefaultMappingContexts", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushPlayerController, DefaultMappingContexts), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContexts_MetaData), NewProp_DefaultMappingContexts_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AOneLastPushPlayerController_Statics::NewProp_CharacterClass = { "CharacterClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushPlayerController, CharacterClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AOneLastPushCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterClass_MetaData), NewProp_CharacterClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOneLastPushPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushPlayerController_Statics::NewProp_DefaultMappingContexts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushPlayerController_Statics::NewProp_DefaultMappingContexts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushPlayerController_Statics::NewProp_CharacterClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushPlayerController_Statics::PropPointers) < 2048);
// ********** End Class AOneLastPushPlayerController Property Definitions **************************
UObject* (*const Z_Construct_UClass_AOneLastPushPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOneLastPushPlayerController_Statics::ClassParams = {
	&AOneLastPushPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AOneLastPushPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushPlayerController_Statics::PropPointers),
	0,
	0x008002A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AOneLastPushPlayerController_Statics::Class_MetaDataParams)
};
void AOneLastPushPlayerController::StaticRegisterNativesAOneLastPushPlayerController()
{
	UClass* Class = AOneLastPushPlayerController::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AOneLastPushPlayerController_Statics::Funcs));
}
UClass* Z_Construct_UClass_AOneLastPushPlayerController()
{
	if (!Z_Registration_Info_UClass_AOneLastPushPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOneLastPushPlayerController.OuterSingleton, Z_Construct_UClass_AOneLastPushPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOneLastPushPlayerController.OuterSingleton;
}
AOneLastPushPlayerController::AOneLastPushPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AOneLastPushPlayerController);
AOneLastPushPlayerController::~AOneLastPushPlayerController() {}
// ********** End Class AOneLastPushPlayerController ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushPlayerController_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOneLastPushPlayerController, AOneLastPushPlayerController::StaticClass, TEXT("AOneLastPushPlayerController"), &Z_Registration_Info_UClass_AOneLastPushPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOneLastPushPlayerController), 4077754250U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushPlayerController_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushPlayerController_h__Script_OneLastPush_1334197361{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushPlayerController_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushPlayerController_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
