// Fill out your copyright notice in the Description page of Project Settings.


#include "Planner.h"
#include "AssignChefsPrimitiveTask.h"


// Sets default values
APlanner::APlanner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlanner::BeginPlay()
{
	//root = beDonutShop;
	Super::BeginPlay();

	// Initial generation
	if (donutShop != nullptr)
	{
		donutShop->triggerPlanner = true;
		donutShop->freeNPCs = donutShop->NPCList.Num();
	}

	// Stores all of the tasks
	//allTasks.Emplace(bakeDonutPrimitive);

	// Constructing BeDonutShopCompound
}

// Called every frame
void APlanner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (donutShop == nullptr)
	{
		return;
	}
	static int counter = 0;

	check(GEngine != nullptr);
	//GEngine->ClearOnScreenDebugMessages();
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("HIII :D"));

	//FString counterText;
		
	
	//counter++;
	if (donutShop->triggerPlanner)
	{
		generatePlan();
		donutShop->triggerPlanner = false;
	}

	for (int i = 0; i < tasksInPlan.Num(); ++i)
	{
		tasksInPlan[i]->run();

		if (tasksInPlan[i]->currentStatus == EStatus::SUCCESS ||
			tasksInPlan[i]->currentStatus == EStatus::FAILED)
		{
			tasksInPlan[i]->currentStatus = EStatus::PROCESSING;
			tasksInPlan[i]->freeResources();
			tasksInPlan.RemoveAt(i);
			--i;
		}
	}
}

void APlanner::generatePlan()
{
	for (int i = 0; i < allTasks.Num(); ++i)
	{
		if (allTasks[i].GetDefaultObject()->checkPrecondition()) // && !tasksInPlan.Contains(allTasks[i]))
		{
			UTask* newTask = NewObject<UTask>(this, allTasks[i]);
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("reserving"));
			tasksInPlan.Emplace(newTask);
			tasksInPlan[tasksInPlan.Num() - 1]->reserveResources();
		}
	}
}

