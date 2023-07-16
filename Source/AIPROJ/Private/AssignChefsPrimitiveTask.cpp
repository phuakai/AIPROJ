// Fill out your copyright notice in the Description page of Project Settings.


#include "AssignChefsPrimitiveTask.h"

bool UAssignChefsPrimitiveTask::checkPrecondition_Implementation()
{
	if (theZone != nullptr && (theZone.Get()->chef1 == nullptr || theZone.Get()->chef2 == nullptr))
	{
		return true;
	}
	return false;
}

void UAssignChefsPrimitiveTask::run_Implementation()
{
	for (int i = 0; i < theZone.Get()->NPCList.Num(); ++i)
	{
		if (theZone.Get()->chef1 != nullptr && theZone.Get()->chef2 != nullptr)
		{
			break;
		}

		if (theZone.Get()->NPCList[i]->tag == ETag::DEFAULT)
		{
			theZone.Get()->NPCList[i]->tag = ETag::COOK;
			++theZone.Get()->cooksFree;

			if (theZone.Get()->chef1 == nullptr)
			{
				theZone.Get()->chef1 = theZone.Get()->NPCList[i];
				continue;
			}
			else if (theZone.Get()->chef2 == nullptr)
			{
				theZone.Get()->chef2 = theZone.Get()->NPCList[i];
				continue;
			}
		}
	}

	currentStatus = EStatus::SUCCESS;
}