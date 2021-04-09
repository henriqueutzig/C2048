#include "includes/globals.h"
#include "includes/mainMenu.h"
#include "includes/gameScene.h"
#include "includes/creditsScene.h"

int main(void)
{

    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();

    // GameState init
    int initialBoardState[BOARD_SIZE][BOARD_SIZE] = {{C2, C2, C4, C8},
                                                     {C16, C32, C64, C128},
                                                     {C256, C512, C1024, C2048},
                                                     {0, 0, 0, 0}};

    GameState gameState = initGameState(initialBoardState, LoadTexture(CARDS), 0, 0);

    // Main menu screen init
    MainMenu menuScreen = initMainMenu();

    // GameScene screen init
    GameScene gameScreen = initGameScene();

    // CreditsScene screen init
    CreditsScene creditsScreen = initCreditsScene();

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        switch (window.screenState)
        {
        case mainMenu:
            // Buttons controll
            mainMenuBtAction(&menuScreen, &(window.screenState));
            drawMainMenu(menuScreen);
            break;
        case game:
            gameSceneAction(&gameScreen, &(window.screenState), &gameState);
            drawGameScene(gameScreen, gameState);
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
