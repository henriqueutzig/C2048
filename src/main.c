#define RAYGUI_IMPLEMENTATION
#define GUI_FILE_DIALOG_IMPLEMENTATION
#include <stdio.h>

// Raylib
#include "includes/raylib.h"
#include "includes/raygui.h"

// Our libraries
#include "includes/window.h"
#include "includes/mainMenu.h"
#include "includes/gameScene.h"
#include "includes/creditsScene.h"
#include "includes/ranking.h"
#include "includes/highScoresScene.h"

int main(void)
{
    srand(time(NULL));
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048"};
    InitWindow(window.width, window.height, window.name);
    //InitAudioDevice();
    SetExitKey(KEY_F4);
    GuiLoadStyle(DRACULA_STYLE);

    Ranker rankers[10];
    loadRankers(&rankers[0]);

    Card initialBoardState[BOARD_SIZE][BOARD_SIZE] = {CARD_VOID};

    GameState gameState = initGameState(&initialBoardState[0][0], LoadTexture(CARDS), 0, 0);

    MainMenu menuScreen = initMainMenu();

    GameScene gameScreen = initGameScene();

    CreditsScene creditsScreen = initCreditsScene();

    HighScoresScene highScoresScene = initHighScores();

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Detect window close button or F4 key
    {
        switch (window.screenState)
        {
        case mainMenu:
            mainMenuBtAction(&menuScreen, &(window.screenState), &initialBoardState[0][0], &gameState);
            drawMainMenu(&menuScreen);
            break;
        case game:
            gameSceneAction(&gameScreen, &(window.screenState), &gameState, &initialBoardState[0][0]);
            drawGameScene(&gameScreen, gameState, rankers, N_MAX_RANKERS);
            break;
        case highScore:
            highScoresSceneAction(&highScoresScene, &(window.screenState));
            drawHighScoresScene(highScoresScene, rankers, N_MAX_RANKERS);
            break;
        case credits:
            creditsSceneAction(&creditsScreen, &(window.screenState));
            drawCreditsScene(creditsScreen);
            break;
        case quit:
            goto end;
        }
    }
end:
    // De-init stuff
    deInitMainMenu(&menuScreen);
    deInitGameScene(&gameScreen);
    deInitCreditsScene(&creditsScreen);
    deInitHighScores(&highScoresScene);
    //CloseAudioDevice();
    CloseWindow();

    return 0;
}
