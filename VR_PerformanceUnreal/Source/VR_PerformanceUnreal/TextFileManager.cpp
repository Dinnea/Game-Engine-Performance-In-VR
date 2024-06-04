// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"

bool UTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverwriting = true)
{
	//Set File path
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!AllowOverwriting) 
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory)) return false;
	}

	FString FinalString = "";
	for (FString& Each : SaveText) 
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}
	return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}
