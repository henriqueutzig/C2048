#include "includes/globals.h"


int main(void)
{
    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();
   
    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        switch (window.screenState)
        {
        case mainMenu:
            BeginDrawing();
            ClearBackground(RAYWHITE);
            
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
    
    // De-init stuff
    CloseAudioDevice();
    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
