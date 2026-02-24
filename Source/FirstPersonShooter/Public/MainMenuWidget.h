#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

UCLASS()
class FIRSTPERSONSHOOTER_API UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:

    virtual bool Initialize() override;

    // Bind these to buttons in UMG
    UPROPERTY(meta = (BindWidget))
    UButton* StartButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitButton;

    UFUNCTION()
    void OnStartClicked();

    UFUNCTION()
    void OnQuitClicked();
};