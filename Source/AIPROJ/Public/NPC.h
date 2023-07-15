// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC.generated.h"

UENUM(BlueprintType)
enum class ETag : uint8
{
	DEFAULT		UMETA(DisplayName = "Default"),
	WAITER		UMETA(DisplayName = "Waiter"),
	COOK		UMETA(DisplayName = "Cook")
};

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

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ETag tag;
	bool operator==(const ANPC& Other) const
	{
		return tag == Other.tag;
	}


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool busy;
};

FORCEINLINE uint32 GetTypeHash(const ANPC& theNPC);