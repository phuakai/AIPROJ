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


bool UTask::checkPrecondition_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT CLASS CHECK PRECONDITION"));
	return false;
}

void UTask::run_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT CLASS RUN"));
}

void UTask::reserveResources_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT CLASS RESERVE RESOURCES"));
}

void UTask::freeResources_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT CLASS FREE RESOURCES"));

	if (theZone != nullptr)
	{
		theZone->triggerPlanner = true;
	}
}

//void UTask::run()
//{
//
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT CLASS RUNNING"));
//	return;
//}



//void UTask::test_Implementation()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT CLASS C++ TEST"));
//}
//
//bool UCompoundTask::checkPrecondition()
//{
//	for (auto& a : tasksList)
//	{
//		if (!a->checkPrecondition())
//			return false;
//	}
//	return true;
//}

void UCompoundTask::run_Implementation()
{
	if (reset)
	{
		currentTaskIndex = 0;
		currentStatus = EStatus::PROCESSING;
		reset = false;
	}

	if (currentTaskIndex == constructedTasks.Num())
	{
		currentStatus = EStatus::SUCCESS;
		reset = true;
		return;
	}

	constructedTasks[currentTaskIndex]->run();
	auto status = constructedTasks[currentTaskIndex]->currentStatus;

	if (status == EStatus::FAILED)
	{
		currentStatus = EStatus::FAILED;
		reset = true;
		return;
	}
	else if (status == EStatus::SUCCESS)
	{
		++currentTaskIndex;
	}
}

//bool UBakeDonutPrimitive::checkPrecondition()
//{
//	if (theZone->cooksFree != 0)
//		return true;
//	return false;
//}
//
//void UBakeDonutPrimitive::run()
//{
//	check(GEngine != nullptr);
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("okay it comes innnn"));
//}
//
//bool UtestPT::checkPrecondition(AZone& zone)
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("testtt"));
//	return false;
//}
//
//void UtestPT::run()
//{
//	counter++;
//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%i counter"), counter));
//}
//
//void UtestPT::test_Implementation()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%i C+++ VERSION"), counter));
//}
