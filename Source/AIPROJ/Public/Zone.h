// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC.h"
#include "Objects.h"
#include "Zone.generated.h"

UCLASS()
class AIPROJ_API AZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int donuts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int tables;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<bool> tableVacant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int freeNPCs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int cooksFree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ANPC*> NPCList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AObjects*> ObjectList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ANPC* chef1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ANPC*> customersInLine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool triggerPlanner = false;

	// Getter / setter
	// Setters trigger planner to run generatePlan()
	// Donut
	int getDonut()
	{
		return donuts;
	}
	void setDonut(int _donuts)
	{
		donuts = _donuts;
		triggerPlanner = true;
	}

	// Tables
	int getTables()
	{
		return tables;
	}
	void setTables(int _tables)
	{
		tables = _tables;
		triggerPlanner = true;
	}

	// Customers
	int getCustomers()
	{
		return freeNPCs;
	}
	void setCustomers(int _freeNPCs)
	{
		freeNPCs = _freeNPCs;
		triggerPlanner = true;
	}

	// CooksFree
	int getCooksFree()
	{
		return cooksFree;
	}
	void setCooksFree(int _cooksFree)
	{
		cooksFree = _cooksFree;
		triggerPlanner = true;
	}

};
