// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operator.h"

/**
 * 
 */
class AIPROJ_API Task
{
public:
	Task();
	~Task();
};


class AIPROJ_API PrimitiveTask : Task
{
public:
	void checkPrecondition();
	Operator theOperator;
	

	
};

class AIPROJ_API CompoundTask : Task
{
public:
	TArray<Task> tasksList;
};