// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tasks.h"
#include "AssignChefsPrimitiveTask.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJ_API UAssignChefsPrimitiveTask : public UPrimitiveTask
{
	GENERATED_BODY()

	bool checkPrecondition_Implementation() override;
	void run_Implementation() override;
};
