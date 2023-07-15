// Fill out your copyright notice in the Description page of Project Settings.


#include "Operator.h"
UOperator::UOperator()
{
}

UOperator::~UOperator()
{
}

void UOperator::run_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("DEFAULT OPERATOR RUN"));
}
