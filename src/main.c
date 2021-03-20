#include "includes/globals.h"

int main(void)
{
    // Window initialization
    Window window = {800, 450, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();

    Button button = initButton(LoadTexture("resources\\buttons\\button.png"), 3, LoadSound("resources/buttons/buttonfx.wav"), window);

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
             DrawTextureRec(button.texture, button.position, (Vector2){button.bounds.x, button.bounds.y}, WHITE);
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
