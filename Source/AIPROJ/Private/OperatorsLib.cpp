// Fill out your copyright notice in the Description page of Project Settings.


#include "OperatorsLib.h"


void UOperatorsLib::test(int i )
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("TestBlueprintLib"));
}

bool UOperatorsLib::Navigate(ANPC* source, FVector dest)
{
	if (IsValid(source))
	{
		Cast<AAIController>(source->GetController())->MoveToLocation(dest, 10, true, true, false, 0, false);
		if (Cast<AAIController>(source->GetController())->IsFollowingAPath())
		{
			return false;
		}
	}
	return true;
}
