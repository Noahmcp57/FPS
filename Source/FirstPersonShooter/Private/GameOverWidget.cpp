#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

bool UGameOverWidget::Initialize()
{
    bool Success = Super::Initialize();

    if (!Success) return false;

    if (RestartButton)
    {
        RestartButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnRestartClicked);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UGameOverWidget::OnQuitClicked);
    }

    return true;
}

void UGameOverWidget::OnRestartClicked()
{
    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void UGameOverWidget::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}