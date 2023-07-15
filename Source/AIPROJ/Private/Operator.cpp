// Fill out your copyright notice in the Description page of Project Settings.


#include "Operator.h"
#include <AIController.h>

UOperator::UOperator()
{
}

UOperator::~UOperator()
{
}

void UOperator::run(ANPC* source, ANPC* dest)
{
	
}

UNavigateTo::UNavigateTo()
{
}

UNavigateTo::~UNavigateTo()
{
}

void UNavigateTo::run(ANPC* source, ANPC* dest)
{
	APawn* Pawn = Cast<APawn>(source->GetOwner());
	if (IsValid(Pawn))
	{
		Cast<AAIController>(Pawn->GetController())->MoveToLocation(dest->GetActorLocation());
	}
}
