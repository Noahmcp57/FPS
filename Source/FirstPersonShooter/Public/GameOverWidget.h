#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UButton;

UCLASS()
class FIRSTPERSONSHOOTER_API UGameOverWidget : public UUserWidget
{
    GENERATED_BODY()

protected:

    virtual bool Initialize() override;

    UPROPERTY(meta = (BindWidget))
    UButton* RestartButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitButton;

    UFUNCTION()
    void OnRestartClicked();

    UFUNCTION()
    void OnQuitClicked();
};