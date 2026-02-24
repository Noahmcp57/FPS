#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenuWidget::Initialize()
{
    bool Success = Super::Initialize();
    if (!Success) return false;

    if (StartButton)
    {
        StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartClicked);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitClicked);
    }

    return true;
}

void UMainMenuWidget::OnStartClicked()
{
    UGameplayStatics::OpenLevel(this, FName("Lvl_FirstPerson"));
}

void UMainMenuWidget::OnQuitClicked()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        PlayerController->ConsoleCommand("quit");
    }
}