// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CSVLine.generated.h"

/**
 * Cet objet correspond à une ligne du fichier CSV
 */
USTRUCT(BlueprintType)
struct FCSVLine
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> ColumnValues;
};