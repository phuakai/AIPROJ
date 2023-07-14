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
runDonutShopCompound::run()
{

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

bool PrimitiveTask::checkPrecondition()
{
	return false;
}
