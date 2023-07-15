// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operator.h"
#include "Zone.h"
#include "Tasks.generated.h"

/**
 * 
 */

enum class Status
{
	PROCESSING,
	FAILED,
	SUCCESS
};
UCLASS()
class AIPROJ_API UTask :public UObject
{
	GENERATED_BODY()
public:
	UTask();
	~UTask();
	UFUNCTION()
	virtual bool checkPrecondition();
	UFUNCTION()
	virtual void run();
	UPROPERTY(BlueprintReadWrite)
	AZone* theZone;

	Status currentStatus;
};

UCLASS(Blueprintable)
class AIPROJ_API UPrimitiveTask :public UTask
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	UOperator* theOperator;
	

	
};
UCLASS(Blueprintable)
class AIPROJ_API UCompoundTask :public UTask
{
	GENERATED_BODY()
public:
	bool checkPrecondition() override;
	void run();
	UPROPERTY(BlueprintReadWrite)
	TArray<UTask*> tasksList;
	UPROPERTY(BlueprintReadWrite)
	int currentTaskIndex;
	UPROPERTY(BlueprintReadWrite)
	bool reset;
};
UCLASS()
class AIPROJ_API UmakeDonut : public UPrimitiveTask
{
	GENERATED_BODY()
public:
	
	bool checkPrecondition() override;

};

class AIPROJ_API runDonutShopCompound :public UCompoundTask
{
public:
	//method?
	BeDonutShopCompound();
	void checkShopStatus();
};