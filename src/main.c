#include "includes/globals.h"
#include "includes/mainMenu.h"

int main(void)
{

    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();

    // Main menu screen init
    MainMenu menuScreen = initMainMenu(window.width, window.height);

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
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("GameWindow", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
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
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("quitWindow", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
            break;
        default:
            break;
        }
    }

    // De-init stuff
    CloseAudioDevice();
    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
