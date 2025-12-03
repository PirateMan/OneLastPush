// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwinStickProjectile.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTwinStickProjectile() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickProjectile();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickProjectile_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ATwinStickProjectile Function OnProjectileStop ***************************
struct Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics
{
	struct TwinStickProjectile_eventOnProjectileStop_Parms
	{
		FHitResult ImpactResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles collisions that stop this projectile from moving */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles collisions that stop this projectile from moving" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnProjectileStop constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImpactResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnProjectileStop constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnProjectileStop Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::NewProp_ImpactResult = { "ImpactResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickProjectile_eventOnProjectileStop_Parms, ImpactResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactResult_MetaData), NewProp_ImpactResult_MetaData) }; // 222120718
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::NewProp_ImpactResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::PropPointers) < 2048);
// ********** End Function OnProjectileStop Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATwinStickProjectile, nullptr, "OnProjectileStop", 	Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::TwinStickProjectile_eventOnProjectileStop_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::TwinStickProjectile_eventOnProjectileStop_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATwinStickProjectile::execOnProjectileStop)
{
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_ImpactResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnProjectileStop(Z_Param_Out_ImpactResult);
	P_NATIVE_END;
}
// ********** End Class ATwinStickProjectile Function OnProjectileStop *****************************

// ********** Begin Class ATwinStickProjectile *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ATwinStickProjectile;
UClass* ATwinStickProjectile::GetPrivateStaticClass()
{
	using TClass = ATwinStickProjectile;
	if (!Z_Registration_Info_UClass_ATwinStickProjectile.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TwinStickProjectile"),
			Z_Registration_Info_UClass_ATwinStickProjectile.InnerSingleton,
			StaticRegisterNativesATwinStickProjectile,
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
	return Z_Registration_Info_UClass_ATwinStickProjectile.InnerSingleton;
}
UClass* Z_Construct_UClass_ATwinStickProjectile_NoRegister()
{
	return ATwinStickProjectile::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ATwinStickProjectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple bouncing projectile for a Twin Stick shooter game\n */" },
#endif
		{ "IncludePath", "Variant_TwinStick/Gameplay/TwinStickProjectile.h" },
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple bouncing projectile for a Twin Stick shooter game" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionSphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Projectile collision sphere */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Projectile collision sphere" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mesh that provides the visual representation for this projectile */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh that provides the visual representation for this projectile" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovement_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles movement behaviors for this projectile */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles movement behaviors for this projectile" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ATwinStickProjectile constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionSphere;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovement;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATwinStickProjectile constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnProjectileStop"), .Pointer = &ATwinStickProjectile::execOnProjectileStop },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATwinStickProjectile_OnProjectileStop, "OnProjectileStop" }, // 1941740201
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwinStickProjectile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ATwinStickProjectile_Statics

// ********** Begin Class ATwinStickProjectile Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATwinStickProjectile_Statics::NewProp_CollisionSphere = { "CollisionSphere", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickProjectile, CollisionSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionSphere_MetaData), NewProp_CollisionSphere_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATwinStickProjectile_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickProjectile, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATwinStickProjectile_Statics::NewProp_ProjectileMovement = { "ProjectileMovement", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickProjectile, ProjectileMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileMovement_MetaData), NewProp_ProjectileMovement_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATwinStickProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickProjectile_Statics::NewProp_CollisionSphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickProjectile_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickProjectile_Statics::NewProp_ProjectileMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickProjectile_Statics::PropPointers) < 2048);
// ********** End Class ATwinStickProjectile Property Definitions **********************************
UObject* (*const Z_Construct_UClass_ATwinStickProjectile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickProjectile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATwinStickProjectile_Statics::ClassParams = {
	&ATwinStickProjectile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATwinStickProjectile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickProjectile_Statics::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickProjectile_Statics::Class_MetaDataParams), Z_Construct_UClass_ATwinStickProjectile_Statics::Class_MetaDataParams)
};
void ATwinStickProjectile::StaticRegisterNativesATwinStickProjectile()
{
	UClass* Class = ATwinStickProjectile::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ATwinStickProjectile_Statics::Funcs));
}
UClass* Z_Construct_UClass_ATwinStickProjectile()
{
	if (!Z_Registration_Info_UClass_ATwinStickProjectile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATwinStickProjectile.OuterSingleton, Z_Construct_UClass_ATwinStickProjectile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATwinStickProjectile.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATwinStickProjectile);
ATwinStickProjectile::~ATwinStickProjectile() {}
// ********** End Class ATwinStickProjectile *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATwinStickProjectile, ATwinStickProjectile::StaticClass, TEXT("ATwinStickProjectile"), &Z_Registration_Info_UClass_ATwinStickProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATwinStickProjectile), 1630938464U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h__Script_OneLastPush_2493483611{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
