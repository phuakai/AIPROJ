// Fill out your copyright notice in the Description page of Project Settings.


#include "Planner.h"


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
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("HIII :D"));

	//FString counterText;
		
	
	//counter++;
	if (donutShop->triggerPlanner)
	{
		generatePlan();
		donutShop->triggerPlanner = false;
	}

	for (int i = 0; i < tasksInPlan.Num(); ++i)
	{
		tasksInPlan[i].GetDefaultObject()->run();

		if (tasksInPlan[i].GetDefaultObject()->currentStatus == EStatus::SUCCESS ||
			tasksInPlan[i].GetDefaultObject()->currentStatus == EStatus::FAILED)
		{
			tasksInPlan[i].GetDefaultObject()->currentStatus = EStatus::PROCESSING;
			donutShop->triggerPlanner = true;
			//tasksInPlan[i].GetDefaultObject()->freeResouces();
			//tasksInPlan.RemoveAt(i);
			//--i;
		}
	}
}

void APlanner::generatePlan()
{
	for (int i = 0; i < allTasks.Num(); ++i)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("its hereee"));
		if (allTasks[i].GetDefaultObject()->checkPrecondition() && !tasksInPlan.Contains(allTasks[i]))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("its in"));
			tasksInPlan.Emplace(allTasks[i]);
			allTasks[i].GetDefaultObject()->reserveResouces();
		}
	}
}

