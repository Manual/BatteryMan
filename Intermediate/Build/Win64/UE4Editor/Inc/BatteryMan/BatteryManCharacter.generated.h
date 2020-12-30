// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTERYMAN_BatteryManCharacter_generated_h
#error "BatteryManCharacter.generated.h already included, missing '#pragma once' in BatteryManCharacter.h"
#endif
#define BATTERYMAN_BatteryManCharacter_generated_h

#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_SPARSE_DATA
#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_RPC_WRAPPERS
#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABatteryManCharacter(); \
	friend struct Z_Construct_UClass_ABatteryManCharacter_Statics; \
public: \
	DECLARE_CLASS(ABatteryManCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BatteryMan"), NO_API) \
	DECLARE_SERIALIZER(ABatteryManCharacter)


#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesABatteryManCharacter(); \
	friend struct Z_Construct_UClass_ABatteryManCharacter_Statics; \
public: \
	DECLARE_CLASS(ABatteryManCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BatteryMan"), NO_API) \
	DECLARE_SERIALIZER(ABatteryManCharacter)


#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABatteryManCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABatteryManCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryManCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryManCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABatteryManCharacter(ABatteryManCharacter&&); \
	NO_API ABatteryManCharacter(const ABatteryManCharacter&); \
public:


#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABatteryManCharacter(ABatteryManCharacter&&); \
	NO_API ABatteryManCharacter(const ABatteryManCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryManCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryManCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABatteryManCharacter)


#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ABatteryManCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ABatteryManCharacter, FollowCamera); }


#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_9_PROLOG
#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_SPARSE_DATA \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_RPC_WRAPPERS \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_INCLASS \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_SPARSE_DATA \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_INCLASS_NO_PURE_DECLS \
	BatteryMan_Source_BatteryMan_BatteryManCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BATTERYMAN_API UClass* StaticClass<class ABatteryManCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BatteryMan_Source_BatteryMan_BatteryManCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
