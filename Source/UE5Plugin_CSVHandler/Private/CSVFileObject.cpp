// Fill out your copyright notice in the Description page of Project Settings.


#include "CSVFileObject.h"

#include "CSVLine.h"
#include "Kismet/KismetStringLibrary.h"


UCSVFileObject* UCSVFileObject::CreateCSVFile(const FString& Header, const FString& Name, const FString& Delimitor, const FString& OutputFolder)
{
	UCSVFileObject* CSVFile = NewObject<UCSVFileObject>();
	CSVFile->InitializeFile(Header,Name,Delimitor,OutputFolder);
	return CSVFile;
}

void UCSVFileObject::SaveFile()
{
	FFileHelper::SaveStringToFile(AppendHeaderAndContent(),*GetFilePath(),FFileHelper::EEncodingOptions::ForceUTF8,&IFileManager::Get(),FILEWRITE_None);
}

void UCSVFileObject::AppendCSVLine(FCSVLine Line)
{
	const FString JoinedArray = UKismetStringLibrary::JoinStringArray(Line.ColumnValues,CSVDelimitor);
	CSVContent+=JoinedArray+"\n";
	SaveFile();
}

void UCSVFileObject::AppendCSVLines(TArray<FCSVLine> Lines)
{
	for (auto Line : Lines)
	{
		const FString JoinedArray = UKismetStringLibrary::JoinStringArray(Line.ColumnValues,CSVDelimitor);
		CSVContent+=JoinedArray+"\n";
	}

	SaveFile();
}

void UCSVFileObject::InitializeFile(const FString& Header, const FString& FileName,const FString& Delimitor, const FString& OutputFolder)
{
	CSVHeader = Header;
	CSVFileName = FileName;
	CSVOutputFolder = OutputFolder;
	CSVDelimitor = Delimitor;

	SaveFile();
}

FString UCSVFileObject::AppendHeaderAndContent()
{
	return CSVHeader+"\n"+CSVContent;
}

FString UCSVFileObject::GetFilePath()
{
	return CSVOutputFolder+FGenericPlatformMisc::GetDefaultPathSeparator()+CSVFileName+".csv";
}
