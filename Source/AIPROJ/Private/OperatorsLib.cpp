// Fill out your copyright notice in the Description page of Project Settings.


#include "OperatorsLib.h"
#include <AIController.h>

void UOperatorsLib::test(int i )
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("TestBlueprintLib"));
}

bool UOperatorsLib::Navigate(ANPC* source, FVector dest)
{
	if (IsValid(source) && source->GetActorLocation() != dest)
	{
		Cast<AAIController>(source->GetController())->MoveToLocation(dest);
		return false;
	}
	else
	{
		return true;
	}
}
