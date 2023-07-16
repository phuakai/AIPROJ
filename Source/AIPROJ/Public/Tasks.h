// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operator.h"
#include "Zone.h"
#include "Tasks.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EStatus : uint8
{
	PROCESSING	UMETA(DisplayName = "Processing"),
	FAILED		UMETA(DisplayName = "Failed"),
	SUCCESS		UMETA(DisplayName = "Success")
};


UCLASS(Blueprintable, abstract)
class AIPROJ_API UTask :public UObject
{
	GENERATED_BODY()
public:
	UTask();
	~UTask();
	UFUNCTION(BlueprintNativeEvent, Category = "Task Functions")
	bool checkPrecondition();

	virtual bool checkPrecondition_Implementation();
	UFUNCTION(BlueprintNativeEvent, Category = "Task Functions")
	void run();
	virtual void run_Implementation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<AZone> theZone;	
	
	UFUNCTION(BlueprintNativeEvent, Category = "Task Functions")
	void reserveResources();
	void reserveResources_Implementation();
	UFUNCTION(BlueprintNativeEvent, Category = "Task Functions")
	void freeResources();
	void freeResources_Implementation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EStatus currentStatus;

};

UCLASS(Blueprintable)
class AIPROJ_API UPrimitiveTask :public UTask
{
	GENERATED_BODY()
public:


	

	
};
UCLASS(Blueprintable)
class AIPROJ_API UCompoundTask :public UTask
{
	GENERATED_BODY()
public:

	void run_Implementation() override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray< TSubclassOf<UTask>> tasksList;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UTask*> constructedTasks;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int currentTaskIndex;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
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