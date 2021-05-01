#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#define GUI_FILE_DIALOG_IMPLEMENTATION
#include <stdio.h>

// Raylib
#include "includes/raylib.h"
#include "includes/raygui.h"

// Our libraries
#include "includes/window.h"
#include "includes/menuScene.h"
#include "includes/gameScene.h"
#include "includes/creditsScene.h"
#include "includes/ranking.h"
#include "includes/highScoresScene.h"

int main(void)
{
    srand(time(NULL));
    Window window = (Window){WINDOW_DW, WINDOW_DH, MENU_SCENE, "C2048"};
    InitWindow(window.width, window.height, window.name);
    //InitAudioDevice();
    SetExitKey(KEY_F4);
    GuiLoadStyle(DRACULA_STYLE);

    Ranker rankers[N_MAX_RANKERS];
    loadRankers(&rankers[0]);

    Card initialBoardState[BOARD_SIZE][BOARD_SIZE] = {CARD_VOID};

    GameState gameState = initGameState(&initialBoardState[0][0], LoadTexture(CARDS), 0, 0);

    MenuScene menuScene = initMainMenu();

    GameScene gameScene = initGameScene();

    CreditsScene creditsScene = initCreditsScene();

    HighScoresScene highScoresScene = initHighScores();

    SetTargetFPS(60);
    bool windowShouldClose = false;

    while (!windowShouldClose) // Detect window close button or F4 key
    {
        windowShouldClose = WindowShouldClose();
        switch (window.screenState)
        {
        case MENU_SCENE:
            mainMenuBtAction(&menuScene, &(window.screenState), &initialBoardState[0][0], &gameState);
            drawMainMenu(&menuScene);
            break;
        case GAME_SCENE:
            gameSceneAction(&gameScene, &(window.screenState), &gameState, &initialBoardState[0][0], &rankers[0]);
            drawGameScene(&gameScene, gameState, rankers, N_MAX_RANKERS);
            break;
        case HIGH_SCORE_SCENE:
            highScoresSceneAction(&highScoresScene, &(window.screenState));
            drawHighScoresScene(highScoresScene, rankers, N_MAX_RANKERS);
            break;
        case CREDITS_SCENE:
            creditsSceneAction(&creditsScene, &(window.screenState));
            drawCreditsScene(creditsScene);
            break;
        case QUIT_GAME:
            windowShouldClose = true;
            break;
        }
    }
    // De-init stuff
    deInitMainMenu(&menuScene);
    deInitGameScene(&gameScene);
    deInitCreditsScene(&creditsScene);
    deInitHighScores(&highScoresScene);
    //CloseAudioDevice();
    CloseWindow();

    return 0;
}
