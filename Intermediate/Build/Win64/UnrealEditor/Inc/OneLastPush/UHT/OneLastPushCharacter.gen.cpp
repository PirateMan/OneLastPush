// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OneLastPushCharacter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOneLastPushCharacter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ETraceTypeQuery();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushCharacter();
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_OneLastPush();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AOneLastPushCharacter Function DoAim *************************************
struct Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics
{
	struct OneLastPushCharacter_eventDoAim_Parms
	{
		float AxisX;
		float AxisY;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles aim inputs from both input actions and touch interface */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles aim inputs from both input actions and touch interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoAim constinit property declarations *********************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AxisX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AxisY;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoAim constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoAim Property Definitions ********************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::NewProp_AxisX = { "AxisX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneLastPushCharacter_eventDoAim_Parms, AxisX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::NewProp_AxisY = { "AxisY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneLastPushCharacter_eventDoAim_Parms, AxisY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::NewProp_AxisX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::NewProp_AxisY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::PropPointers) < 2048);
// ********** End Function DoAim Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOneLastPushCharacter, nullptr, "DoAim", 	Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::OneLastPushCharacter_eventDoAim_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::OneLastPushCharacter_eventDoAim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOneLastPushCharacter_DoAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOneLastPushCharacter_DoAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOneLastPushCharacter::execDoAim)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_AxisX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AxisY);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoAim(Z_Param_AxisX,Z_Param_AxisY);
	P_NATIVE_END;
}
// ********** End Class AOneLastPushCharacter Function DoAim ***************************************

// ********** Begin Class AOneLastPushCharacter Function DoMove ************************************
struct Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics
{
	struct OneLastPushCharacter_eventDoMove_Parms
	{
		float AxisX;
		float AxisY;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles move inputs from both input actions and touch interface */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles move inputs from both input actions and touch interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoMove constinit property declarations ********************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AxisX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AxisY;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DoMove constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DoMove Property Definitions *******************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::NewProp_AxisX = { "AxisX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneLastPushCharacter_eventDoMove_Parms, AxisX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::NewProp_AxisY = { "AxisY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneLastPushCharacter_eventDoMove_Parms, AxisY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::NewProp_AxisX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::NewProp_AxisY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::PropPointers) < 2048);
// ********** End Function DoMove Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOneLastPushCharacter, nullptr, "DoMove", 	Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::OneLastPushCharacter_eventDoMove_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::OneLastPushCharacter_eventDoMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOneLastPushCharacter_DoMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOneLastPushCharacter_DoMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOneLastPushCharacter::execDoMove)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_AxisX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AxisY);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoMove(Z_Param_AxisX,Z_Param_AxisY);
	P_NATIVE_END;
}
// ********** End Class AOneLastPushCharacter Function DoMove **************************************

// ********** Begin Class AOneLastPushCharacter Function DoShoot ***********************************
struct Z_Construct_UFunction_AOneLastPushCharacter_DoShoot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles shoot inputs from both input actions and touch interface */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles shoot inputs from both input actions and touch interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoShoot constinit property declarations *******************************
// ********** End Function DoShoot constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOneLastPushCharacter_DoShoot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOneLastPushCharacter, nullptr, "DoShoot", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoShoot_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOneLastPushCharacter_DoShoot_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AOneLastPushCharacter_DoShoot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOneLastPushCharacter_DoShoot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOneLastPushCharacter::execDoShoot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoShoot();
	P_NATIVE_END;
}
// ********** End Class AOneLastPushCharacter Function DoShoot *************************************

// ********** Begin Class AOneLastPushCharacter Function DoSprint **********************************
struct Z_Construct_UFunction_AOneLastPushCharacter_DoSprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handles sprint inputs from both input actions and touch interface */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles sprint inputs from both input actions and touch interface" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DoSprint constinit property declarations ******************************
// ********** End Function DoSprint constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOneLastPushCharacter_DoSprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AOneLastPushCharacter, nullptr, "DoSprint", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOneLastPushCharacter_DoSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOneLastPushCharacter_DoSprint_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AOneLastPushCharacter_DoSprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOneLastPushCharacter_DoSprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOneLastPushCharacter::execDoSprint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoSprint();
	P_NATIVE_END;
}
// ********** End Class AOneLastPushCharacter Function DoSprint ************************************

// ********** Begin Class AOneLastPushCharacter ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AOneLastPushCharacter;
UClass* AOneLastPushCharacter::GetPrivateStaticClass()
{
	using TClass = AOneLastPushCharacter;
	if (!Z_Registration_Info_UClass_AOneLastPushCharacter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OneLastPushCharacter"),
			Z_Registration_Info_UClass_AOneLastPushCharacter.InnerSingleton,
			StaticRegisterNativesAOneLastPushCharacter,
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
	return Z_Registration_Info_UClass_AOneLastPushCharacter.InnerSingleton;
}
UClass* Z_Construct_UClass_AOneLastPushCharacter_NoRegister()
{
	return AOneLastPushCharacter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AOneLastPushCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  A controllable top-down perspective character\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "OneLastPushCharacter.h" },
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A controllable top-down perspective character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom spring arm */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom spring arm" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Player Camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player Camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Movement input action */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movement input action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StickAimAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gamepad aim input action */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gamepad aim input action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseAimAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mouse aim input action */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mouse aim input action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sprint input action */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sprint input action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShootAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shooting input action */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shooting input action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseAimTraceChannel_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Trace channel to use for mouse aim */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trace channel to use for mouse aim" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimRotationInterpSpeed_MetaData[] = {
		{ "Category", "Aim" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Speed to blend between our current rotation and the target aim rotation when stick aiming */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Speed to blend between our current rotation and the target aim rotation when stick aiming" },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoFireDelay_MetaData[] = {
		{ "Category", "Aim" },
		{ "ClampMax", "5" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time to wait between autofire attempts */" },
#endif
		{ "ModuleRelativePath", "OneLastPushCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time to wait between autofire attempts" },
#endif
		{ "Units", "s" },
	};
#endif // WITH_METADATA

// ********** Begin Class AOneLastPushCharacter constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StickAimAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MouseAimAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootAction;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MouseAimTraceChannel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimRotationInterpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AutoFireDelay;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AOneLastPushCharacter constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("DoAim"), .Pointer = &AOneLastPushCharacter::execDoAim },
		{ .NameUTF8 = UTF8TEXT("DoMove"), .Pointer = &AOneLastPushCharacter::execDoMove },
		{ .NameUTF8 = UTF8TEXT("DoShoot"), .Pointer = &AOneLastPushCharacter::execDoShoot },
		{ .NameUTF8 = UTF8TEXT("DoSprint"), .Pointer = &AOneLastPushCharacter::execDoSprint },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AOneLastPushCharacter_DoAim, "DoAim" }, // 1883290070
		{ &Z_Construct_UFunction_AOneLastPushCharacter_DoMove, "DoMove" }, // 638371027
		{ &Z_Construct_UFunction_AOneLastPushCharacter_DoShoot, "DoShoot" }, // 3564648385
		{ &Z_Construct_UFunction_AOneLastPushCharacter_DoSprint, "DoSprint" }, // 2702810192
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOneLastPushCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AOneLastPushCharacter_Statics

// ********** Begin Class AOneLastPushCharacter Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_StickAimAction = { "StickAimAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, StickAimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StickAimAction_MetaData), NewProp_StickAimAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_MouseAimAction = { "MouseAimAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, MouseAimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseAimAction_MetaData), NewProp_MouseAimAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_SprintAction = { "SprintAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAction_MetaData), NewProp_SprintAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_ShootAction = { "ShootAction", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, ShootAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShootAction_MetaData), NewProp_ShootAction_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_MouseAimTraceChannel = { "MouseAimTraceChannel", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, MouseAimTraceChannel), Z_Construct_UEnum_Engine_ETraceTypeQuery, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseAimTraceChannel_MetaData), NewProp_MouseAimTraceChannel_MetaData) }; // 93441085
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_AimRotationInterpSpeed = { "AimRotationInterpSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, AimRotationInterpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimRotationInterpSpeed_MetaData), NewProp_AimRotationInterpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_AutoFireDelay = { "AutoFireDelay", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOneLastPushCharacter, AutoFireDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoFireDelay_MetaData), NewProp_AutoFireDelay_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOneLastPushCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_StickAimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_MouseAimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_ShootAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_MouseAimTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_AimRotationInterpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOneLastPushCharacter_Statics::NewProp_AutoFireDelay,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushCharacter_Statics::PropPointers) < 2048);
// ********** End Class AOneLastPushCharacter Property Definitions *********************************
UObject* (*const Z_Construct_UClass_AOneLastPushCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_OneLastPush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOneLastPushCharacter_Statics::ClassParams = {
	&AOneLastPushCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AOneLastPushCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushCharacter_Statics::PropPointers),
	0,
	0x008000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOneLastPushCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AOneLastPushCharacter_Statics::Class_MetaDataParams)
};
void AOneLastPushCharacter::StaticRegisterNativesAOneLastPushCharacter()
{
	UClass* Class = AOneLastPushCharacter::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AOneLastPushCharacter_Statics::Funcs));
}
UClass* Z_Construct_UClass_AOneLastPushCharacter()
{
	if (!Z_Registration_Info_UClass_AOneLastPushCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOneLastPushCharacter.OuterSingleton, Z_Construct_UClass_AOneLastPushCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOneLastPushCharacter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AOneLastPushCharacter);
AOneLastPushCharacter::~AOneLastPushCharacter() {}
// ********** End Class AOneLastPushCharacter ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h__Script_OneLastPush_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOneLastPushCharacter, AOneLastPushCharacter::StaticClass, TEXT("AOneLastPushCharacter"), &Z_Registration_Info_UClass_AOneLastPushCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOneLastPushCharacter), 1118988899U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h__Script_OneLastPush_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h__Script_OneLastPush_2538665842{
	TEXT("/Script/OneLastPush"),
	Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h__Script_OneLastPush_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h__Script_OneLastPush_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
