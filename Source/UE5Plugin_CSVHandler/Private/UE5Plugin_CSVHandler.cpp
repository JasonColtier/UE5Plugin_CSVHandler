// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5Plugin_CSVHandler.h"

#define LOCTEXT_NAMESPACE "FUE5Plugin_CSVHandlerModule"

void FUE5Plugin_CSVHandlerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUE5Plugin_CSVHandlerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUE5Plugin_CSVHandlerModule, UE5Plugin_CSVHandler)