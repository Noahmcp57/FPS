#include "EnemyAIController.h"

AEnemyAIController::AEnemyAIController()
{
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    if (BehaviorTreeAsset)
    {
        RunBehaviorTree(BehaviorTreeAsset);
    }
}