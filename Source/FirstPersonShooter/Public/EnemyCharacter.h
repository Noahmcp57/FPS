#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "EnemyAIController.h"
#include "EnemyCharacter.generated.h"


UCLASS()
class FIRSTPERSONSHOOTER_API AEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UPawnSensingComponent* PawnSensing;

    UFUNCTION()
    void OnSeePawn(APawn* Pawn);

public:
    AEnemyCharacter();
};