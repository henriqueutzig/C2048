#include "includes/globals.h"

int main(void)
{
    // Window initialization 
    Window window = { 800, 450, mainMenu, "C2048", true};
    InitWindow(window.width, window.height, window.name);
    

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch (window.screenState)
        {
            case mainMenu:
                BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawText("Test -> WindowController", 190, 200, 20, LIGHTGRAY);
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

    
    // Close window and OpenGL context
    CloseWindow(); 

    return 0;
}

