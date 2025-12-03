// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwinStickAoEAttack.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTwinStickAoEAttack() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickAoEAttack();
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickAoEAttack_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ATwinStickAoEAttack Function BP_AoEFinished ******************************
static FName NAME_ATwinStickAoEAttack_BP_AoEFinished = FName(TEXT("BP_AoEFinished"));
void ATwinStickAoEAttack::BP_AoEFinished()
{
	UFunction* Func = FindFunctionChecked(NAME_ATwinStickAoEAttack_BP_AoEFinished);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ATwinStickAoEAttack_BP_AoEFinished_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AoE Attack" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Allows Blueprint handling of AoE fade out effects. NOTE: Call Destroy Actor at the end of this! */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows Blueprint handling of AoE fade out effects. NOTE: Call Destroy Actor at the end of this!" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BP_AoEFinished constinit property declarations ************************
// ********** End Function BP_AoEFinished constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwinStickAoEAttack_BP_AoEFinished_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATwinStickAoEAttack, nullptr, "BP_AoEFinished", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickAoEAttack_BP_AoEFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATwinStickAoEAttack_BP_AoEFinished_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ATwinStickAoEAttack_BP_AoEFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATwinStickAoEAttack_BP_AoEFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ATwinStickAoEAttack Function BP_AoEFinished ********************************

// ********** Begin Class ATwinStickAoEAttack Function OnAoEOverlap ********************************
struct Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics
{
	struct TwinStickAoEAttack_eventOnAoEOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles collision with the AoE while it's active */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles collision with the AoE while it's active" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnAoEOverlap constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnAoEOverlap constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnAoEOverlap Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickAoEAttack_eventOnAoEOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickAoEAttack_eventOnAoEOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickAoEAttack_eventOnAoEOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickAoEAttack_eventOnAoEOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((TwinStickAoEAttack_eventOnAoEOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TwinStickAoEAttack_eventOnAoEOverlap_Parms), &Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickAoEAttack_eventOnAoEOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 222120718
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::PropPointers) < 2048);
// ********** End Function OnAoEOverlap Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ATwinStickAoEAttack, nullptr, "OnAoEOverlap", 	Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::TwinStickAoEAttack_eventOnAoEOverlap_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::TwinStickAoEAttack_eventOnAoEOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATwinStickAoEAttack::execOnAoEOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAoEOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class ATwinStickAoEAttack Function OnAoEOverlap **********************************

// ********** Begin Class ATwinStickAoEAttack ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ATwinStickAoEAttack;
UClass* ATwinStickAoEAttack::GetPrivateStaticClass()
{
	using TClass = ATwinStickAoEAttack;
	if (!Z_Registration_Info_UClass_ATwinStickAoEAttack.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TwinStickAoEAttack"),
			Z_Registration_Info_UClass_ATwinStickAoEAttack.InnerSingleton,
			StaticRegisterNativesATwinStickAoEAttack,
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
	return Z_Registration_Info_UClass_ATwinStickAoEAttack.InnerSingleton;
}
UClass* Z_Construct_UClass_ATwinStickAoEAttack_NoRegister()
{
	return ATwinStickAoEAttack::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ATwinStickAoEAttack_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple persistent AoE attack.\n *  Damages characters that enter for as long as it's active\n */" },
#endif
		{ "IncludePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple persistent AoE attack.\nDamages characters that enter for as long as it's active" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereVisual_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Provides the visual representation for the AoE attack */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides the visual representation for the AoE attack" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionSphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Provides the collision volume for the AoE attack */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Provides the collision volume for the AoE attack" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartAoETime_MetaData[] = {
		{ "Category", "AoE Attack" },
		{ "ClampMax", "5" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time to wait between AoE damage ticks */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time to wait between AoE damage ticks" },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StopAoETime_MetaData[] = {
		{ "Category", "AoE Attack" },
		{ "ClampMax", "5" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time to wait before stopping AoE damage checks */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/Gameplay/TwinStickAoEAttack.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time to wait before stopping AoE damage checks" },
#endif
		{ "Units", "s" },
	};
#endif // WITH_METADATA

// ********** Begin Class ATwinStickAoEAttack constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereVisual;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionSphere;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartAoETime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StopAoETime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATwinStickAoEAttack constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnAoEOverlap"), .Pointer = &ATwinStickAoEAttack::execOnAoEOverlap },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATwinStickAoEAttack_BP_AoEFinished, "BP_AoEFinished" }, // 1589821413
		{ &Z_Construct_UFunction_ATwinStickAoEAttack_OnAoEOverlap, "OnAoEOverlap" }, // 94765623
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwinStickAoEAttack>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ATwinStickAoEAttack_Statics

// ********** Begin Class ATwinStickAoEAttack Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_SphereVisual = { "SphereVisual", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickAoEAttack, SphereVisual), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereVisual_MetaData), NewProp_SphereVisual_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_CollisionSphere = { "CollisionSphere", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickAoEAttack, CollisionSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionSphere_MetaData), NewProp_CollisionSphere_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_StartAoETime = { "StartAoETime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickAoEAttack, StartAoETime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartAoETime_MetaData), NewProp_StartAoETime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_StopAoETime = { "StopAoETime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATwinStickAoEAttack, StopAoETime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StopAoETime_MetaData), NewProp_StopAoETime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATwinStickAoEAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_SphereVisual,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_CollisionSphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_StartAoETime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickAoEAttack_Statics::NewProp_StopAoETime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickAoEAttack_Statics::PropPointers) < 2048);
// ********** End Class ATwinStickAoEAttack Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_ATwinStickAoEAttack_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickAoEAttack_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATwinStickAoEAttack_Statics::ClassParams = {
	&ATwinStickAoEAttack::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATwinStickAoEAttack_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickAoEAttack_Statics::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickAoEAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_ATwinStickAoEAttack_Statics::Class_MetaDataParams)
};
void ATwinStickAoEAttack::StaticRegisterNativesATwinStickAoEAttack()
{
	UClass* Class = ATwinStickAoEAttack::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ATwinStickAoEAttack_Statics::Funcs));
}
UClass* Z_Construct_UClass_ATwinStickAoEAttack()
{
	if (!Z_Registration_Info_UClass_ATwinStickAoEAttack.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATwinStickAoEAttack.OuterSingleton, Z_Construct_UClass_ATwinStickAoEAttack_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATwinStickAoEAttack.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATwinStickAoEAttack);
ATwinStickAoEAttack::~ATwinStickAoEAttack() {}
// ********** End Class ATwinStickAoEAttack ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickAoEAttack_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATwinStickAoEAttack, ATwinStickAoEAttack::StaticClass, TEXT("ATwinStickAoEAttack"), &Z_Registration_Info_UClass_ATwinStickAoEAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATwinStickAoEAttack), 2437032533U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickAoEAttack_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickAoEAttack_h__Script_OneLastPush_1723775223{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickAoEAttack_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickAoEAttack_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
