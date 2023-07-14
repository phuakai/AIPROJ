// Fill out your copyright notice in the Description page of Project Settings.


#include "Tasks.h"

Task::Task()
{
}

Task::~Task()
{
}

runDonutShopCompound::runDonutShopCompound()
{
	//first is cook donuts
	makeDonut makeDonutTask;
	TArray<Task> cookDonuts;
	
	cookDonuts.Emplace(makeDonutTask);
	tasksList.Emplace(cookDonuts);
	
}

void runDonutShopCompound::checkShopStatus()
{
	
}

bool makeDonut::checkPrecondition()
{
	if (theZone->cooksFree != 0)
		return true;
	return false;
}

bool Task::checkPrecondition()
{
	return false;
}

void Task::run()
{
	return;
}

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
