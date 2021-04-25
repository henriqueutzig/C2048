#include "includes/globals.h"
#include "includes/mainMenu.h"
#include "includes/gameScene.h"
#include "includes/creditsScene.h"
#include "includes/ranking.h"

int main(void)
{
    srand(time(NULL));
    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();

    // SaveManager init
    SavedGame saveData = loadGame();

    //GameState init
    Card initialBoardState[BOARD_SIZE][BOARD_SIZE] = {CARD_VOID};

    GameState gameState = initGameState(&initialBoardState[0][0], LoadTexture(CARDS), 0, 0);

    // Main menu screen init
    MainMenu menuScreen = initMainMenu();

    // GameScene screen init
    GameScene gameScreen = initGameScene();

    // CreditsScene screen init
    CreditsScene creditsScreen = initCreditsScene();

    // Ranking init
    Ranker rankers[10];
    loadRankers(&rankers[0]);

    // Converts Ranker[] to char[][]
    char highScores[N_MAX_RANKERS][MAX_HS_LENGTH];
    getHighScores(&rankers[0], &highScores[0][0]);    

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        switch (window.screenState)
        {
        case mainMenu:
            // TODO: make new game button not use the saveData board
            mainMenuBtAction(&menuScreen, &(window.screenState), &initialBoardState[0][0], saveData, &gameState);
            drawMainMenu(menuScreen, saveData.exists);
            break;
        case game:
            gameLogicAction(&gameState, &initialBoardState[0][0], &saveData);
            gameSceneAction(&gameScreen, &(window.screenState), &gameState);
            drawGameScene(gameScreen, gameState, highScores, N_MAX_RANKERS);
            break;
        case highScore:
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("HighScoreWindow", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
            break;
        case credits:
            creditsSceneAction(&creditsScreen, &(window.screenState));
            drawCreditsScene(creditsScreen);
            break;
        case quit:
            deInitMainMenu(&menuScreen);
            deInitGameScene(&gameScreen);
            deInitCreditsScene(&creditsScreen);
            CloseAudioDevice();
            CloseWindow();
            return 0;
            break;
        default:
            break;
        }
    }

    // De-init stuff
    deInitMainMenu(&menuScreen);
    deInitGameScene(&gameScreen);
    deInitCreditsScene(&creditsScreen);
    // Close window and OpenGL context
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
