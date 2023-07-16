// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OperatorsLib.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class AIPROJ_API UOperatorsLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = UOperatorsLib)
		static void test(int i);
};
