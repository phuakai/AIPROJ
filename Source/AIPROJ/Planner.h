// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Public/NPC.h"
#include "Public/Tasks.h"
#include "Planner.generated.h"


UCLASS()
class AIPROJ_API APlanner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TMap<ANPC, UTask*> queue;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UTask>> allTasks;

	// Compund Tasks
	BeDonutShopCompound* beDonutShop;

	// Primitive Tasks
	UPROPERTY()
	UBakeDonutPrimitive* bakeDonutPrimitive;
	//UPROPERTY()
	//UTask root;

	UPROPERTY(EditAnywhere)
	AZone* donutShop;

	UPROPERTY(EditAnywhere)
	TArray<UTask*> tasksInPlan;
	 
	void generatePlan();

};
