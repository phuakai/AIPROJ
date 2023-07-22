// Fill out your copyright notice in the Description page of Project Settings.


#include "OperatorsLib.h"
#include <AIController.h>

void UOperatorsLib::test(int i )
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("TestBlueprintLib"));
}

bool UOperatorsLib::Navigate(ANPC* source, FVector dest)
{
	static float timer = 0.0f;
	static bool reset = true;

	if (IsValid(source)/* && source->GetActorLocation() != dest*/)
	{
		auto result = Cast<AAIController>(source->GetController())->MoveToLocation(dest);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%d"), Cast<AAIController>(source->GetController())->GetMoveStatus()));

		timer += FApp::GetDeltaTime();

		if (reset)
		{
			timer = 0.f;
			reset = false;
		}
		if (timer >= 2 && source->GetVelocity().SquaredLength() <= 1)
		{
			reset = true;
			return true;
		}
		
		return false;
	}
	else
	{
		return true;
	}

	//if (IsValid(source))
	//{
	//	Cast<AAIController>(source->GetController())->MoveToLocation(dest,10,true,true,false,0,false);

	//	if (Cast<AAIController>(source->GetController())->IsFollowingAPath())
	//	{
	//		return false;
	//	}
	//}
	//return true;
}
