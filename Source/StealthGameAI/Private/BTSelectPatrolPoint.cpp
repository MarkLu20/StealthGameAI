// Fill out your copyright notice in the Description page of Project Settings.

#include "BTSelectPatrolPoint.h"
#include "AIPatrolController.h"
#include "AIPatrolPoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

EBTNodeResult::Type UBTSelectPatrolPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAIPatrolController *AICon = Cast<AAIPatrolController>(OwnerComp.GetAIOwner());
		if (AICon)
		{
			UBlackboardComponent *BlackboarComp = AICon->GetBlacakboradComp();
			AAIPatrolPoint *CurrenPoint = Cast<AAIPatrolPoint>(BlackboarComp->GetValueAsObject("LocationToGo"));
			TArray<AActor *> AvaiblePAtrolPatrolPoints = AICon->GetPatrolPoints();
			AAIPatrolPoint *NextPatrolPoint = nullptr;
			if (AICon->CurrentPatrolPoint!=AvaiblePAtrolPatrolPoints.Num()-1)
			{
				NextPatrolPoint = Cast<AAIPatrolPoint>(AvaiblePAtrolPatrolPoints[++AICon->CurrentPatrolPoint]);

			}
			else
			{
				NextPatrolPoint = Cast<AAIPatrolPoint>(AvaiblePAtrolPatrolPoints[0]);
				AICon->CurrentPatrolPoint = 0;
			}
			BlackboarComp->SetValueAsObject("LocationToGo",NextPatrolPoint);
			return EBTNode
		}

	
}
