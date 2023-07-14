// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operator.h"
#include "Zone.h"

/**
 * 
 */
class AIPROJ_API Task
{
public:
	Task();
	~Task();

	UPROPERTY()
	AZone* theZone;
};


class AIPROJ_API PrimitiveTask :public Task
{
public:
	virtual bool checkPrecondition();
	Operator theOperator;
	

	
};

class AIPROJ_API CompoundTask :public Task
{
public:
	TArray<TArray<Task>> tasksList;
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