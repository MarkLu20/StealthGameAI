// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPatrolController.h"
#include "AIPatrol.h"
#include "AIPatrolPoint.h"
#include "Engine.h"
AAIPatrolController::AAIPatrolController()
{

	//chu shi hua bb and bt
	BehavorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	Blackboardcomp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoradComp"));
	PlayerKey = "Target";
	LocationTOgoKey = "LocationToGo";
	CurrentPatrolPoint = 0;
	
}
void AAIPatrolController::SetPlayerCaught(APawn * Pawn)
{
	if (Blackboardcomp)
	{
		Blackboardcomp->SetValueAsObject(PlayerKey,Pawn);
	}
}
void AAIPatrolController::Possess(APawn * Pawn)
{

	//
	AAIPatrol *AICharcter = Cast<AAIPatrol>(Pawn);
	if (AICharcter)
	{
		if (AICharcter->BehaviorTree->BlackboardAsset)
		{
			Blackboardcomp->InitializeBlackboard(*(AICharcter->BehaviorTree->BlackboardAsset));
		}
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPatrolPoint::StaticClass(), PatrolPoints);
		BehavorComp->StartTree(*AICharcter->BehaviorTree);

	}
}