#define RAYGUI_IMPLEMENTATION
#define GUI_FILE_DIALOG_IMPLEMENTATION
#include "includes/globals.h"
#include "includes/mainMenu.h"
#include "includes/gameScene.h"
#include "includes/creditsScene.h"

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

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose()) // Detect window close button or F4 key
    {
        switch (window.screenState)
        {
        case mainMenu:
            // TODO: make new game button not use the saveData board
            mainMenuBtAction(&menuScreen, &(window.screenState), &initialBoardState[0][0], &gameState);
            drawMainMenu(&menuScreen);
            break;
        case game:
            gameSceneAction(&gameScreen, &(window.screenState), &gameState, &initialBoardState[0][0]);
            drawGameScene(&gameScreen, gameState);
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
