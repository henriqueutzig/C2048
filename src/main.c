#include "includes/globals.h"

int main(void)
{
    // Window initialization 
    Window window = { DEFAULT_W, DEFAULT_H, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        switch (window.screenState)
        {
            case mainMenu:
                    ClearBackground(RAYWHITE);
                    DrawText("Test -> WindowController", 190, 200, 20, LIGHTGRAY);
                break;
            case game:
                
                break;
            case credits:
                
                break;
            default:
                break;
        }
        EndDrawing();
    }

    
    // Close window and OpenGL context
    CloseWindow(); 

    return 0;
}

