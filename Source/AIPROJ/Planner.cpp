// Fill out your copyright notice in the Description page of Project Settings.


#include "Planner.h"

// Sets default values
APlanner::APlanner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlanner::BeginPlay()
{
	runDonutShopCompound runDonutShop;
	root = runDonutShop;
	Super::BeginPlay();
	
}

// Called every frame
void APlanner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlanner::generatePlan()
{




}
