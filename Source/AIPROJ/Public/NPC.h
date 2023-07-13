// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC.generated.h"

UCLASS()
class AIPROJ_API ANPC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	enum class TAG
	{
		default,
		waiter,
		cook
	};
	TAG tag;
	bool operator==(const ANPC& Other) const
	{
		return tag == Other.tag;
	}

};

FORCEINLINE uint32 GetTypeHash(const ANPC& theNPC);