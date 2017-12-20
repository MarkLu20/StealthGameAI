// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AIPatrolController.generated.h"

/**
 *
 */
UCLASS()
class STEALTHGAMEAI_API AAIPatrolController : public AAIController
{
	GENERATED_BODY()
		//our blackborad
    UBlackboardComponent *Blackboardcomp;
	UBehaviorTreeComponent *BehavorComp;
	//blackborad keys
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName LocationTOgoKey;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName PlayerKey;
	TArray<AActor *> PatrolPoints;
	virtual void Possess(APawn *Pawn) override;



public:
	AAIPatrolController();
	int32 CurrentPatrolPoint=0;
	void SetPlayerCaught(APawn * Pawn);
	FORCEINLINE UBlackboardComponent *GetBlacakboradComp() const { return Blackboardcomp; }
	FORCEINLINE TArray<AActor*> GetPatrolPoints()const { return PatrolPoints; }


};
