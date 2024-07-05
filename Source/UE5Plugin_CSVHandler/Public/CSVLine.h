// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CSVLine.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UCSVLine : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> ColumnValues;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UCSVLine* MakeCSVLine(TArray<FString> Values);
};
