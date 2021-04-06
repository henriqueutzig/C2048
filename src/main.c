#include "includes/globals.h"
#include "includes/mainMenu.h"
#include "includes/gameScene.h"

int main(void)
{

    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();

    // Main menu screen init
    MainMenu menuScreen = initMainMenu(window.width, window.height);

    // GameScene screen init
    GameScene gameScreen = initGameScene(window.width, window.height);

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        switch (window.screenState)
        {
        case mainMenu:
            // Buttons controll
            mainMenuBtAction(&menuScreen, &(window.screenState));
            drawMainMenu(&window.screenState, &menuScreen);
            break;
        case game:
            gameSceneAction(&gameScreen, &(window.screenState));
            drawGameScene(&window.screenState, &gameScreen);
            break;
        case highScore:
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("highScoreWindow", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
            break;
        case credits:
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("CreditsWindow", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
            break;
        case quit:
            CloseAudioDevice();
            deInitMainMenu(&menuScreen);
            deInitGameScene(&gameScreen);
            CloseWindow();
            return 0;
            break;
        default:
            break;
        }
    }

    // De-init stuff
    CloseAudioDevice();
    deInitMainMenu(&menuScreen);
    deInitGameScene(&gameScreen);
    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
