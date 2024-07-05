// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CSVLine.h"
#include "UObject/Object.h"
#include "CSVFileObject.generated.h"

class UCSVLine;
/**
 * cet objet correspond à un fichier CSV
 */
UCLASS()
class UCSVFileObject : public UObject
{
	GENERATED_BODY()

public:
	//fonction statique permettant de créer un fichier CSV
	UFUNCTION(BlueprintCallable)
	static UCSVFileObject* CreateCSVFile(const FString& Header, const FString& Name, const FString& Delimitor, const FString& OutputFolder);

	//sauvegarde du fichier manuelle
	UFUNCTION(BlueprintCallable)
	void SaveFile();

	//ajout d'une ligne et sauvegarde automatique
	UFUNCTION(BlueprintCallable)
	void AppendCSVLine(FCSVLine Line);

	//ajout de plusieurs lignes et sauvegarde automatique
	UFUNCTION(BlueprintCallable)
	void AppendCSVLines(TArray<FCSVLine> Lines);

protected:
	//la première ligne du CSV
	UPROPERTY(BlueprintReadOnly)
	FString CSVHeader;

	//le contenu global du CSV (ne contient pas le header)
	UPROPERTY(BlueprintReadOnly)
	FString CSVContent;

	//le nom du fichier. Pas besoin de spécifier .csv
	UPROPERTY(BlueprintReadOnly)
	FString CSVFileName;

	//le dossier d'export
	UPROPERTY(BlueprintReadOnly)
	FString CSVOutputFolder;

	//la méthode de délimitation utilisée
	UPROPERTY(BlueprintReadOnly)
	FString CSVDelimitor;

	
private:
	//initialisation du fichier csv
	UFUNCTION()
	void InitializeFile(const FString& Header,const FString& FileName,const FString& Delimitor,const FString& OutputFolder);

	//concaténation du header et du contenu en une seule string
	UFUNCTION()
	FString AppendHeaderAndContent();

	//transforme le chemin du dossier et le nom du fichier en une seule string pour l'écriture du fichier
	UFUNCTION()
	FString GetFilePath();
};
