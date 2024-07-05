// Fill out your copyright notice in the Description page of Project Settings.


#include "CSVLine.h"

UCSVLine* UCSVLine::MakeCSVLine(TArray<FString> Values)
{
	UCSVLine* Line = NewObject<UCSVLine>();
	Line->ColumnValues = Values;
	return Line;
}
