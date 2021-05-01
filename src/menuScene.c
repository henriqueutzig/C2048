#include "includes/menuScene.h"
#include "includes/window.h"

void drawMainMenu(MenuScene *menuScene)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    if (menuScene->fileDialogState.fileDialogActive)
        GuiLock();

    drawButton(menuScene->btNewGame);
    drawButton(menuScene->btLoadGame);
    drawButton(menuScene->btHighScores);
    drawButton(menuScene->btCredits);
    drawButton(menuScene->btQuit);

    drawElementUI(menuScene->logo);

    GuiUnlock();
    GuiFileDialog(&menuScene->fileDialogState);

    EndDrawing();
}

void mainMenuBtAction(MenuScene *menuScene, ScreenState *screenState, Card *initialBoardState, GameState *gameState)
{
    if (menuScene->fileDialogState.SelectFilePressed)
    {
        if (IsFileExtension(menuScene->fileDialogState.fileNameText, ".bin"))
        {
            *gameState = loadGame(TextFormat("%s/%s", menuScene->fileDialogState.dirPathText, menuScene->fileDialogState.fileNameText), initialBoardState);
            *(screenState) = GAME_SCENE;
        }

        menuScene->fileDialogState.SelectFilePressed = false;
        menuScene->fileDialogState.fileDialogActive = false;
    }

    if (menuScene->fileDialogState.fileDialogActive == true)
    {
        return;
    }

    if (updateButtonState(&(menuScene->btLoadGame)))
    {
        menuScene->fileDialogState.fileDialogActive = true;
    }

    if (updateButtonState(&(menuScene->btNewGame)))
    {
        restartGame(initialBoardState, gameState);
        *(screenState) = GAME_SCENE;
    }

    if (updateButtonState(&(menuScene->btHighScores)))
        *(screenState) = HIGH_SCORE_SCENE;
    if (updateButtonState(&(menuScene->btCredits)))
        *(screenState) = CREDITS_SCENE;
    if (updateButtonState(&(menuScene->btQuit)))
        *(screenState) = QUIT_GAME;
}

MenuScene initMainMenu()
{
    MenuScene menuScene;

    menuScene.fileDialogState = InitGuiFileDialog(420, 310, FILES_PATH, false);

    menuScene.logo = initElementUI(LoadTexture(GAME_LOGO), (Vector2){155, 62});

    menuScene.btLoadGame = initButton((LoadTexture(BT_LOADGAME)), 2, LoadSound(BT_SOUND),
                                   (Vector2){339, 211});
    menuScene.btNewGame = initButton(LoadTexture(BT_NEWGAME), 2, LoadSound(BT_SOUND),
                                  (Vector2){155, 211});
    menuScene.btHighScores = initButton(LoadTexture(BT_HIGHSCORES), 2, LoadSound(BT_SOUND),
                                     (Vector2){247, 273});
    menuScene.btCredits = initButton(LoadTexture(BT_CREDITS), 2, LoadSound(BT_SOUND),
                                  (Vector2){247, 335});
    menuScene.btQuit = initButton(LoadTexture(BT_QUIT), 2, LoadSound(BT_SOUND),
                               (Vector2){247, 397});
    return menuScene;
}

void deInitMainMenu(MenuScene *menuScene)
{
    UnloadTexture(menuScene->logo.texture);
    deInitButton(&(menuScene->btLoadGame));
    deInitButton(&(menuScene->btNewGame));
    deInitButton(&(menuScene->btCredits));
    deInitButton(&(menuScene->btHighScores));
    deInitButton(&(menuScene->btQuit));
}