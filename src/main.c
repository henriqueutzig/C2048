#include "includes/globals.h"
#include "includes/button.h"

int main(void)
{
    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();
    Button button = initButton(LoadTexture(BT_TEXTURE), 3, LoadSound(BT_SOUND), (Vector2){200, 100});

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
            drawButton(&button);
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
    deInitButton(&button);
    CloseAudioDevice();
    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
