// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operator.h"
#include "Zone.h"

/**
 * 
 */

enum class Status
{
	PROCESSING,
	FAILED,
	SUCCESS
};

class AIPROJ_API Task
{
public:
	Task();
	~Task();
	virtual bool checkPrecondition();
	virtual void run();
	UPROPERTY()
	AZone* theZone;
	Status currentStatus;
};


class AIPROJ_API PrimitiveTask :public Task
{
public:
	
	Operator theOperator;
	

	
};

class AIPROJ_API CompoundTask :public Task
{
public:
	bool checkPrecondition();
	void run();
	TArray<Task*> tasksList;
	int currentTaskIndex;
	
	bool reset;

	
};

class AIPROJ_API makeDonut : public PrimitiveTask
{
public:
	bool checkPrecondition();

};

class AIPROJ_API runDonutShopCompound :public CompoundTask
{
public:
	//method?
	runDonutShopCompound();
	void checkShopStatus();
};