// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONSHOOTER_API AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	// --- New Code Start --- 

	virtual void StartPlay() override;

	// --- New Code End --- 	
};
