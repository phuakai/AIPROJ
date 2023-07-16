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
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT OPERATOR RUN"));
}

