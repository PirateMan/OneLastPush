// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OneLastPushCharacter.h"

#ifdef ONELASTPUSH_OneLastPushCharacter_generated_h
#error "OneLastPushCharacter.generated.h already included, missing '#pragma once' in OneLastPushCharacter.h"
#endif
#define ONELASTPUSH_OneLastPushCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInventoryComponent;

// ********** Begin Class AOneLastPushCharacter ****************************************************
#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetInventory); \
	DECLARE_FUNCTION(execDoShoot); \
	DECLARE_FUNCTION(execDoSprint); \
	DECLARE_FUNCTION(execDoAim); \
	DECLARE_FUNCTION(execDoMove);


struct Z_Construct_UClass_AOneLastPushCharacter_Statics;
ONELASTPUSH_API UClass* Z_Construct_UClass_AOneLastPushCharacter_NoRegister();

#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOneLastPushCharacter(); \
	friend struct ::Z_Construct_UClass_AOneLastPushCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ONELASTPUSH_API UClass* ::Z_Construct_UClass_AOneLastPushCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AOneLastPushCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/OneLastPush"), Z_Construct_UClass_AOneLastPushCharacter_NoRegister) \
	DECLARE_SERIALIZER(AOneLastPushCharacter)


#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AOneLastPushCharacter(AOneLastPushCharacter&&) = delete; \
	AOneLastPushCharacter(const AOneLastPushCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOneLastPushCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOneLastPushCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AOneLastPushCharacter) \
	NO_API virtual ~AOneLastPushCharacter();


#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_22_PROLOG
#define FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_25_INCLASS_NO_PURE_DECLS \
	FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AOneLastPushCharacter;

// ********** End Class AOneLastPushCharacter ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_Games_OneLastPush_Source_OneLastPush_OneLastPushCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
