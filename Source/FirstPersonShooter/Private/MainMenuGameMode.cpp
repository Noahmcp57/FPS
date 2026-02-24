#include "MainMenuGameMode.h"
#include "Blueprint/UserWidget.h"

void AMainMenuGameMode::BeginPlay()
{
    Super::BeginPlay();

    UUserWidget* Menu = CreateWidget(GetWorld(), LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/FirstPerson/UI/WBP_MainMenu.WBP_MainMenu'")));

    if (Menu)
    {
        Menu->AddToViewport();

        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC)
        {
            PC->SetShowMouseCursor(true);
            PC->SetInputMode(FInputModeUIOnly());
        }
    }
}