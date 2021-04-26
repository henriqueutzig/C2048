#define RAYGUI_IMPLEMENTATION
#define GUI_FILE_DIALOG_IMPLEMENTATION
#include "includes/globals.h"
#include "includes/mainMenu.h"
#include "includes/gameScene.h"
#include "includes/creditsScene.h"
#include "includes/ranking.h"
#include "includes/highScoresScene.h"

int main(void)
{
    srand(time(NULL));
    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();
    SetExitKey(KEY_F4);
    GuiLoadStyle(DRACULA_STYLE);

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

    // HighScoresScene init
    HighScoresScene highScoresScene = initHighScores();

    SetTargetFPS(60);
    // Main Scene loop
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
            drawGameScene(&gameScreen, gameState, highScores, N_MAX_RANKERS);
            break;
        case highScore:
            highScoresSceneAction(&highScoresScene, &(window.screenState));
            drawHighScoresScene(highScoresScene, highScores);
            break;
        case credits:
            creditsSceneAction(&creditsScreen, &(window.screenState));
            drawCreditsScene(creditsScreen);
            break;
        case quit:
            deInitMainMenu(&menuScreen);
            deInitGameScene(&gameScreen);
            deInitCreditsScene(&creditsScreen);
            deInitHighScores(&highScoresScene);
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
    deInitHighScores(&highScoresScene);
    // Close window and OpenGL context
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
