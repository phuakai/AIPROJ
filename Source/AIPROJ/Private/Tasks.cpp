// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks.h"

bool CompoundTask::checkPrecondition()
{
	for (auto& a : tasksList)
	{
		if (!a->checkPrecondition())
			return false;
	}
	return true;
}

void CompoundTask::run()
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

bool BakeDonutPrimitive::checkPrecondition()
{
	if (theZone->cooksFree != 0)
		return true;
	return false;
}

void BakeDonutPrimitive::run()
{
	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("okay it comes innnn"));
}

BeDonutShopCompound::BeDonutShopCompound()
{
	//first is cook donuts
	//makeDonut makeDonutTask;
	//TArray<Task> cookDonuts;
	//
	//cookDonuts.Emplace(makeDonutTask);
	//tasksList.Emplace(cookDonuts);
}

void BeDonutShopCompound::checkShopStatus()
{
	
}
