// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CSVFileObject.generated.h"

class UCSVLine;
/**
 * 
 */
UCLASS()
class UCSVFileObject : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FString CSVHeader;

	UPROPERTY(BlueprintReadOnly)
	FString CSVContent;

	UPROPERTY(BlueprintReadOnly)
	FString CSVFileName;

	UPROPERTY(BlueprintReadOnly)
	FString CSVOutputFolder;

	UPROPERTY(BlueprintReadOnly)
	FString CSVDelimitor;

	UFUNCTION(BlueprintCallable)
	static UCSVFileObject* CreateCSVFile(const FString& Header, const FString& Name, const FString& Delimitor, const FString& OutputFolder);

	UFUNCTION()
	void InitializeFile(const FString& Header,const FString& FileName,const FString& Delimitor,const FString& OutputFolder);
	
	UFUNCTION(BlueprintCallable)
	void SaveFile();
	
	UFUNCTION(BlueprintCallable)
	void AppendCSVLine(UCSVLine* Line);

	UFUNCTION(BlueprintCallable)
	void AppendCSVLines(TArray<UCSVLine*> Lines);

private:
	FString AppendHeaderAndContent();

	FString GetFilePath();
};
