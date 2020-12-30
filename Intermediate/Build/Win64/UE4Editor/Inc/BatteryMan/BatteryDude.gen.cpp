// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BatteryMan/BatteryDude.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBatteryDude() {}
// Cross Module References
	BATTERYMAN_API UClass* Z_Construct_UClass_ABatteryDude_NoRegister();
	BATTERYMAN_API UClass* Z_Construct_UClass_ABatteryDude();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_BatteryMan();
// End Cross Module References
	void ABatteryDude::StaticRegisterNativesABatteryDude()
	{
	}
	UClass* Z_Construct_UClass_ABatteryDude_NoRegister()
	{
		return ABatteryDude::StaticClass();
	}
	struct Z_Construct_UClass_ABatteryDude_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABatteryDude_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_BatteryMan,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABatteryDude_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BatteryDude.h" },
		{ "ModuleRelativePath", "BatteryDude.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABatteryDude_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABatteryDude>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABatteryDude_Statics::ClassParams = {
		&ABatteryDude::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABatteryDude_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABatteryDude_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABatteryDude()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABatteryDude_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABatteryDude, 3234090206);
	template<> BATTERYMAN_API UClass* StaticClass<ABatteryDude>()
	{
		return ABatteryDude::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABatteryDude(Z_Construct_UClass_ABatteryDude, &ABatteryDude::StaticClass, TEXT("/Script/BatteryMan"), TEXT("ABatteryDude"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABatteryDude);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
