// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operator.generated.h"
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class AIPROJ_API UOperator :public UObject
{
	GENERATED_BODY()
public:
	UOperator();
	~UOperator();
	UFUNCTION(BlueprintNativeEvent, Category = "Operator Functions")
	 void run();

	 void run_Implementation();


};
