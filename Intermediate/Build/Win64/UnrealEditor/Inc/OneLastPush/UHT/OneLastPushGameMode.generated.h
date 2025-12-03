// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OneLastPushGameMode.h"

#ifdef ONELASTPUSH_OneLastPushGameMode_generated_h
#error "OneLastPushGameMode.generated.h already included, missing '#pragma once' in OneLastPushGameMode.h"
#endif
#define ONELASTPUSH_OneLastPushGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AOneLastPushGameMode *****************************************************
struct Z_Construct_UClass_AOneLastPushGameMode_Statics;
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushGameMode_NoRegister();

#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOneLastPushGameMode(); \
	friend struct ::Z_Construct_UClass_AOneLastPushGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ONELASTPUSH_API UClass* ::Z_Construct_UClass_AOneLastPushGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AOneLastPushGameMode, AGameModeBase, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/OneLastPush"), Z_Construct_UClass_AOneLastPushGameMode_NoRegister) \
	DECLARE_SERIALIZER(AOneLastPushGameMode)


#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOneLastPushGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AOneLastPushGameMode(AOneLastPushGameMode&&) = delete; \
	AOneLastPushGameMode(const AOneLastPushGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOneLastPushGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOneLastPushGameMode); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOneLastPushGameMode) \
	NO_API virtual ~AOneLastPushGameMode();


#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h_15_PROLOG
#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h_18_INCLASS_NO_PURE_DECLS \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AOneLastPushGameMode;

// ********** End Class AOneLastPushGameMode *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
