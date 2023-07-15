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
	UFUNCTION(BlueprintNativeEvent, Category = "Task Functions")
	bool checkPrecondition();

	bool checkPrecondition_Implementation();
	UFUNCTION(BlueprintNativeEvent, Category = "Task Functions")
	void run();
	void run_Implementation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<AZone> theZone;

	Status currentStatus;

};

UCLASS(Blueprintable)
class AIPROJ_API UPrimitiveTask :public UTask
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	TSoftObjectPtr<UOperator> theOperator;
	

	
};
UCLASS(Blueprintable)
class AIPROJ_API UCompoundTask :public UTask
{
	GENERATED_BODY()
public:

	void run();
	UPROPERTY(BlueprintReadWrite)
	TArray<UTask*> tasksList;
	UPROPERTY(BlueprintReadWrite)
	int currentTaskIndex;
	UPROPERTY(BlueprintReadWrite)
	bool reset;
};
UCLASS()
class AIPROJ_API UBakeDonutPrimitive : public UPrimitiveTask
{
	GENERATED_BODY()
public:
	


};

UCLASS(Blueprintable)
class AIPROJ_API UtestPT : public UPrimitiveTask
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	int counter = 0;


};


class AIPROJ_API BeDonutShopCompound :public UCompoundTask
{
public:
	//method?

	BeDonutShopCompound();
	void checkShopStatus();
};