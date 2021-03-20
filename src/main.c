#include "includes/globals.h"

int main(void)
{
    // Window initialization
    Window window = {800, 450, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();
    Button button = initButton(LoadTexture("src/resources/textures/button.png"), 3, LoadSound("src/resources/audio/buttonfx.wav"), (Vector2){100, 100});

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (buttonState(&button))
        {
            printf("Foi!!!!");
        }

        switch (window.screenState)
        {
        case mainMenu:
            BeginDrawing();
            ClearBackground(RAYWHITE);
            drawButton(button);
            EndDrawing();
            break;
        case game:

            break;
        case credits:

            break;
        default:
            break;
        }
    }
    deInitButton(button);
    CloseAudioDevice();
    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
