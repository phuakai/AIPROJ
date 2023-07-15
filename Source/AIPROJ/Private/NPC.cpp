// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//i need this so that it can be a key in the map
FORCEINLINE uint32 GetTypeHash(const ANPC& theNPC)
{
	uint32 Hash = FCrc::MemCrc32(&theNPC, sizeof(ANPC));
	return Hash;
}

