// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks.h"

UTask::UTask()
{
}

UTask::~UTask()
{
}

BeDonutShopCompound::BeDonutShopCompound()
{
	//first is cook donuts
	//makeDonut makeDonutTask;
	//TArray<Task> cookDonuts;
	
	//cookDonuts.Emplace(makeDonutTask);
	//tasksList.Emplace(cookDonuts);
	
}

void BeDonutShopCompound::checkShopStatus()
{
	
}


bool UTask::checkPrecondition()
{
	return false;
}

void UTask::run()
{
	return;
}

bool UCompoundTask::checkPrecondition()
{
	for (auto& a : tasksList)
	{
		if (!a->checkPrecondition())
			return false;
	}
	return true;
}

void UCompoundTask::run()
{
	if (reset)
	{
		currentTaskIndex = 0;
		currentStatus = Status::PROCESSING;
		reset = false;
	}
	tasksList[currentTaskIndex]->run();
	auto status = tasksList[currentTaskIndex]->currentStatus;

	if (status == Status::FAILED)
	{
		currentStatus = Status::FAILED;
		reset = true;
		return;
	}
	else if (status == Status::SUCCESS)
	{
		++currentTaskIndex;
		if (currentTaskIndex == tasksList.Num())
		{
			currentStatus = Status::SUCCESS;
			reset = true;
			return;
		}
	}
}

bool UBakeDonutPrimitive::checkPrecondition()
{
	if (theZone->cooksFree != 0)
		return true;
	return false;
}

void UBakeDonutPrimitive::run()
{
	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("okay it comes innnn"));
}

