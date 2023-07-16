// Fill out your copyright notice in the Description page of Project Settings.


#include "OperatorsLib.h"
#include <AIController.h>

void UOperatorsLib::test(int i )
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("TestBlueprintLib"));
}

bool UOperatorsLib::Navigate(ANPC* source, ANPC* dest)
{
	if (IsValid(source) && source->GetActorLocation() != dest->GetActorLocation())
	{
		Cast<AAIController>(source->GetController())->MoveToLocation(dest->GetActorLocation());
		return false;
	}
	else
	{
		return true;
	}
}
