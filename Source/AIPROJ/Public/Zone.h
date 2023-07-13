// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC.h"
#include "Zone.generated.h"

UCLASS()
class AIPROJ_API AZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		int donuts;
	UPROPERTY(EditAnywhere)
		int tables;
	UPROPERTY(EditAnywhere)
		int customers;
	UPROPERTY(EditAnywhere)
		int waiters;
	UPROPERTY(EditAnywhere)
		TArray<ANPC*> NPCList;

};
