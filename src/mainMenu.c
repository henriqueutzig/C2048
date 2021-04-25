#include "includes/mainMenu.h"
#include "includes/window.h"

void drawMainMenu(MainMenu *mainMenu)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    if (mainMenu->fileDialogState.fileDialogActive)
    {
        GuiFileDialog(&mainMenu->fileDialogState);
    }
    else
    {
        drawButton(mainMenu->btNewGame);
        drawButton(mainMenu->btLoadGame);
        drawButton(mainMenu->btHighScores);
        drawButton(mainMenu->btCredits);
        drawButton(mainMenu->btQuit);

        drawElementUI(mainMenu->logo);
    }

    EndDrawing();
}

void mainMenuBtAction(MainMenu *menuScreen, int *screenState, Card *initialBoardState, GameState *gameState)
{
    if (menuScreen->fileDialogState.SelectFilePressed)
    {
        // Load image file (if supported extension)
        if (IsFileExtension(menuScreen->fileDialogState.fileNameText, ".bin"))
        {
            *gameState = loadGame(TextFormat("%s/%s", menuScreen->fileDialogState.dirPathText, menuScreen->fileDialogState.fileNameText), initialBoardState);
            *(screenState) = game;
        }

        menuScreen->fileDialogState.SelectFilePressed = false;
        menuScreen->fileDialogState.fileDialogActive = false;
    }

    if (menuScreen->fileDialogState.fileDialogActive == true)
    {
        return;
    }

    if (buttonState(&(menuScreen->btLoadGame)))
    {
        menuScreen->fileDialogState.fileDialogActive = true;
    }

    if (buttonState(&(menuScreen->btNewGame)))
    {
        restartGame(initialBoardState, gameState);
        *(screenState) = game;
    }

    if (buttonState(&(menuScreen->btHighScores)))
        *(screenState) = highScore;
    if (buttonState(&(menuScreen->btCredits)))
        *(screenState) = credits;
    if (buttonState(&(menuScreen->btQuit)))
        *(screenState) = quit;
}

MainMenu initMainMenu()
{
    MainMenu window;

    window.fileDialogState = InitGuiFileDialog(420, 310, FILES_PATH, false);

    window.logo = initElementUI(LoadTexture(GAME_LOGO), (Vector2){155, 62});

    window.btLoadGame = initButton((LoadTexture(BT_LOADGAME)), 2, LoadSound(BT_SOUND),
                                   (Vector2){339, 211});
    window.btNewGame = initButton(LoadTexture(BT_NEWGAME), 2, LoadSound(BT_SOUND),
                                  (Vector2){155, 211});
    window.btHighScores = initButton(LoadTexture(BT_HIGHSCORES), 2, LoadSound(BT_SOUND),
                                     (Vector2){247, 273});
    window.btCredits = initButton(LoadTexture(BT_CREDITS), 2, LoadSound(BT_SOUND),
                                  (Vector2){247, 335});
    window.btQuit = initButton(LoadTexture(BT_QUIT), 2, LoadSound(BT_SOUND),
                               (Vector2){247, 397});
    return window;
}

void deInitMainMenu(MainMenu *mainMenu)
{
    UnloadTexture(mainMenu->logo.texture);
    deInitButton(&(mainMenu->btLoadGame));
    deInitButton(&(mainMenu->btNewGame));
    deInitButton(&(mainMenu->btCredits));
    deInitButton(&(mainMenu->btHighScores));
    deInitButton(&(mainMenu->btQuit));
}