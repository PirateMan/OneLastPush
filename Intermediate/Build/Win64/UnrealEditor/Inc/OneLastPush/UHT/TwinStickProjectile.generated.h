// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Variant_TwinStick/Gameplay/TwinStickProjectile.h"

#ifdef ONELASTPUSH_TwinStickProjectile_generated_h
#error "TwinStickProjectile.generated.h already included, missing '#pragma once' in TwinStickProjectile.h"
#endif
#define ONELASTPUSH_TwinStickProjectile_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;

// ********** Begin Class ATwinStickProjectile *****************************************************
#define FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnProjectileStop);


struct Z_Construct_UClass_ATwinStickProjectile_Statics;
ONELASTPUSH_API UClass* Z_Construct_UClass_ATwinStickProjectile_NoRegister();

#define FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATwinStickProjectile(); \
	friend struct ::Z_Construct_UClass_ATwinStickProjectile_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ONELASTPUSH_API UClass* ::Z_Construct_UClass_ATwinStickProjectile_NoRegister(); \
public: \
	DECLARE_CLASS2(ATwinStickProjectile, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/OneLastPush"), Z_Construct_UClass_ATwinStickProjectile_NoRegister) \
	DECLARE_SERIALIZER(ATwinStickProjectile)


#define FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_19_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ATwinStickProjectile(ATwinStickProjectile&&) = delete; \
	ATwinStickProjectile(const ATwinStickProjectile&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATwinStickProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATwinStickProjectile); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ATwinStickProjectile) \
	NO_API virtual ~ATwinStickProjectile();


#define FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_16_PROLOG
#define FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_19_INCLASS_NO_PURE_DECLS \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ATwinStickProjectile;

// ********** End Class ATwinStickProjectile *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_Games_OneLastPush_Source_OneLastPush_Variant_TwinStick_Gameplay_TwinStickProjectile_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
