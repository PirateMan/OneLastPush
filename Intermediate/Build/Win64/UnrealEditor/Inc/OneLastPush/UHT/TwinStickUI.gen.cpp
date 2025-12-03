// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwinStickUI.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeTwinStickUI() {}

// ********** Begin Cross Module References ********************************************************
ONELASTPUSH_API UClass* Z_Construct_UClass_UTwinStickUI();
ONELASTPUSH_API UClass* Z_Construct_UClass_UTwinStickUI_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UTwinStickUI Function UpdateCombo ****************************************
struct TwinStickUI_eventUpdateCombo_Parms
{
	int32 Combo;
};
static FName NAME_UTwinStickUI_UpdateCombo = FName(TEXT("UpdateCombo"));
void UTwinStickUI::UpdateCombo(int32 Combo)
{
	TwinStickUI_eventUpdateCombo_Parms Parms;
	Parms.Combo=Combo;
	UFunction* Func = FindFunctionChecked(NAME_UTwinStickUI_UpdateCombo);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint handler to update the combo sub-widgets */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/UI/TwinStickUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint handler to update the combo sub-widgets" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateCombo constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Combo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateCombo constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateCombo Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::NewProp_Combo = { "Combo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickUI_eventUpdateCombo_Parms, Combo), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::NewProp_Combo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::PropPointers) < 2048);
// ********** End Function UpdateCombo Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTwinStickUI, nullptr, "UpdateCombo", 	Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::PropPointers), 
sizeof(TwinStickUI_eventUpdateCombo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TwinStickUI_eventUpdateCombo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTwinStickUI_UpdateCombo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTwinStickUI_UpdateCombo_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UTwinStickUI Function UpdateCombo ******************************************

// ********** Begin Class UTwinStickUI Function UpdateItems ****************************************
struct TwinStickUI_eventUpdateItems_Parms
{
	int32 Score;
};
static FName NAME_UTwinStickUI_UpdateItems = FName(TEXT("UpdateItems"));
void UTwinStickUI::UpdateItems(int32 Score)
{
	TwinStickUI_eventUpdateItems_Parms Parms;
	Parms.Score=Score;
	UFunction* Func = FindFunctionChecked(NAME_UTwinStickUI_UpdateItems);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint handler to update the items counter */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/UI/TwinStickUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint handler to update the items counter" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateItems constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Score;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateItems constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateItems Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickUI_eventUpdateItems_Parms, Score), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::NewProp_Score,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::PropPointers) < 2048);
// ********** End Function UpdateItems Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTwinStickUI, nullptr, "UpdateItems", 	Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::PropPointers), 
sizeof(TwinStickUI_eventUpdateItems_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TwinStickUI_eventUpdateItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTwinStickUI_UpdateItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTwinStickUI_UpdateItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UTwinStickUI Function UpdateItems ******************************************

// ********** Begin Class UTwinStickUI Function UpdateScore ****************************************
struct TwinStickUI_eventUpdateScore_Parms
{
	int32 Score;
};
static FName NAME_UTwinStickUI_UpdateScore = FName(TEXT("UpdateScore"));
void UTwinStickUI::UpdateScore(int32 Score)
{
	TwinStickUI_eventUpdateScore_Parms Parms;
	Parms.Score=Score;
	UFunction* Func = FindFunctionChecked(NAME_UTwinStickUI_UpdateScore);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint handler to update the score sub-widgets */" },
#endif
		{ "ModuleRelativePath", "Variant_TwinStick/UI/TwinStickUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint handler to update the score sub-widgets" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UpdateScore constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Score;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UpdateScore constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UpdateScore Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TwinStickUI_eventUpdateScore_Parms, Score), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::NewProp_Score,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::PropPointers) < 2048);
// ********** End Function UpdateScore Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTwinStickUI, nullptr, "UpdateScore", 	Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::PropPointers), 
sizeof(TwinStickUI_eventUpdateScore_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TwinStickUI_eventUpdateScore_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTwinStickUI_UpdateScore()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTwinStickUI_UpdateScore_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UTwinStickUI Function UpdateScore ******************************************

// ********** Begin Class UTwinStickUI *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UTwinStickUI;
UClass* UTwinStickUI::GetPrivateStaticClass()
{
	using TClass = UTwinStickUI;
	if (!Z_Registration_Info_UClass_UTwinStickUI.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("TwinStickUI"),
			Z_Registration_Info_UClass_UTwinStickUI.InnerSingleton,
			StaticRegisterNativesUTwinStickUI,
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
	return Z_Registration_Info_UClass_UTwinStickUI.InnerSingleton;
}
UClass* Z_Construct_UClass_UTwinStickUI_NoRegister()
{
	return UTwinStickUI::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UTwinStickUI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A simple Twin Stick Shooter UI widget\n *  Provides a blueprint interface to expose score values to the UI\n */" },
#endif
		{ "IncludePath", "Variant_TwinStick/UI/TwinStickUI.h" },
		{ "ModuleRelativePath", "Variant_TwinStick/UI/TwinStickUI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A simple Twin Stick Shooter UI widget\nProvides a blueprint interface to expose score values to the UI" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UTwinStickUI constinit property declarations *****************************
// ********** End Class UTwinStickUI constinit property declarations *******************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTwinStickUI_UpdateCombo, "UpdateCombo" }, // 1095037433
		{ &Z_Construct_UFunction_UTwinStickUI_UpdateItems, "UpdateItems" }, // 437356510
		{ &Z_Construct_UFunction_UTwinStickUI_UpdateScore, "UpdateScore" }, // 2619855290
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTwinStickUI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UTwinStickUI_Statics
UObject* (*const Z_Construct_UClass_UTwinStickUI_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTwinStickUI_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTwinStickUI_Statics::ClassParams = {
	&UTwinStickUI::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00A010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTwinStickUI_Statics::Class_MetaDataParams), Z_Construct_UClass_UTwinStickUI_Statics::Class_MetaDataParams)
};
void UTwinStickUI::StaticRegisterNativesUTwinStickUI()
{
}
UClass* Z_Construct_UClass_UTwinStickUI()
{
	if (!Z_Registration_Info_UClass_UTwinStickUI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTwinStickUI.OuterSingleton, Z_Construct_UClass_UTwinStickUI_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTwinStickUI.OuterSingleton;
}
UTwinStickUI::UTwinStickUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UTwinStickUI);
UTwinStickUI::~UTwinStickUI() {}
// ********** End Class UTwinStickUI ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_UI_TwinStickUI_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTwinStickUI, UTwinStickUI::StaticClass, TEXT("UTwinStickUI"), &Z_Registration_Info_UClass_UTwinStickUI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTwinStickUI), 1600730777U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_UI_TwinStickUI_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_UI_TwinStickUI_h__Script_OneLastPush_1331734089{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_UI_TwinStickUI_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_UI_TwinStickUI_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
