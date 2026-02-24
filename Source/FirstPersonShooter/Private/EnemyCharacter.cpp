#include "EnemyCharacter.h"
#include "AIController.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

   
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    AIControllerClass = AEnemyAIController::StaticClass();

    // Create Pawn Sensing
    PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
    PawnSensing->SightRadius = 2000.f;
    PawnSensing->SetPeripheralVisionAngle(60.f);

    // Bind the see function
    PawnSensing->OnSeePawn.AddDynamic(this, &AEnemyCharacter::OnSeePawn);
}

void AEnemyCharacter::OnSeePawn(APawn* Pawn)
{
    AEnemyAIController* AIController = Cast<AEnemyAIController>(GetController());

    if (AIController && AIController->GetBlackboardComponent())
    {
        AIController->GetBlackboardComponent()->SetValueAsObject("TargetActor", Pawn);
    }
}