// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StrategyHUD.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeStrategyHUD() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_AHUD();
ONELASTPUSH_API UClass* Z_Construct_UClass_AStrategyHUD();
ONELASTPUSH_API UClass* Z_Construct_UClass_AStrategyHUD_NoRegister();
ONELASTPUSH_API UClass* Z_Construct_UClass_UStrategyUI_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AStrategyHUD *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AStrategyHUD;
UClass* AStrategyHUD::GetPrivateStaticClass()
{
	using TClass = AStrategyHUD;
	if (!Z_Registration_Info_UClass_AStrategyHUD.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("StrategyHUD"),
			Z_Registration_Info_UClass_AStrategyHUD.InnerSingleton,
			StaticRegisterNativesAStrategyHUD,
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
	return Z_Registration_Info_UClass_AStrategyHUD.InnerSingleton;
}
UClass* Z_Construct_UClass_AStrategyHUD_NoRegister()
{
	return AStrategyHUD::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AStrategyHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple strategy game HUD\n *  Draws the selection box and unit selected overlays\n */" },
#endif
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Variant_Strategy/UI/StrategyHUD.h" },
		{ "ModuleRelativePath", "Variant_Strategy/UI/StrategyHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple strategy game HUD\nDraws the selection box and unit selected overlays" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIWidget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pointer to the UI user widget */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Variant_Strategy/UI/StrategyHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pointer to the UI user widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UIWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of UI Widget to spawn */" },
#endif
		{ "ModuleRelativePath", "Variant_Strategy/UI/StrategyHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of UI Widget to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectionBoxColor_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Color of the selection box */" },
#endif
		{ "ModuleRelativePath", "Variant_Strategy/UI/StrategyHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Color of the selection box" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AStrategyHUD constinit property declarations *****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UIWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_UIWidgetClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectionBoxColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AStrategyHUD constinit property declarations *******************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStrategyHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AStrategyHUD_Statics

// ********** Begin Class AStrategyHUD Property Definitions ****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStrategyHUD_Statics::NewProp_UIWidget = { "UIWidget", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStrategyHUD, UIWidget), Z_Construct_UClass_UStrategyUI_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIWidget_MetaData), NewProp_UIWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStrategyHUD_Statics::NewProp_UIWidgetClass = { "UIWidgetClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStrategyHUD, UIWidgetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UStrategyUI_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UIWidgetClass_MetaData), NewProp_UIWidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AStrategyHUD_Statics::NewProp_SelectionBoxColor = { "SelectionBoxColor", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStrategyHUD, SelectionBoxColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectionBoxColor_MetaData), NewProp_SelectionBoxColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStrategyHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStrategyHUD_Statics::NewProp_UIWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStrategyHUD_Statics::NewProp_UIWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStrategyHUD_Statics::NewProp_SelectionBoxColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyHUD_Statics::PropPointers) < 2048);
// ********** End Class AStrategyHUD Property Definitions ******************************************
UObject* (*const Z_Construct_UClass_AStrategyHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStrategyHUD_Statics::ClassParams = {
	&AStrategyHUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AStrategyHUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyHUD_Statics::PropPointers),
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_AStrategyHUD_Statics::Class_MetaDataParams)
};
void AStrategyHUD::StaticRegisterNativesAStrategyHUD()
{
}
UClass* Z_Construct_UClass_AStrategyHUD()
{
	if (!Z_Registration_Info_UClass_AStrategyHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStrategyHUD.OuterSingleton, Z_Construct_UClass_AStrategyHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStrategyHUD.OuterSingleton;
}
AStrategyHUD::AStrategyHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AStrategyHUD);
AStrategyHUD::~AStrategyHUD() {}
// ********** End Class AStrategyHUD ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_Strategy_UI_StrategyHUD_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStrategyHUD, AStrategyHUD::StaticClass, TEXT("AStrategyHUD"), &Z_Registration_Info_UClass_AStrategyHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStrategyHUD), 831971883U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_Strategy_UI_StrategyHUD_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_Strategy_UI_StrategyHUD_h__Script_OneLastPush_3195221168{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_Strategy_UI_StrategyHUD_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_Strategy_UI_StrategyHUD_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
