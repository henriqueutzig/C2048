#include "includes/globals.h"
#include "includes/mainMenu.h"
#include "includes/gameScene.h"

int main(void)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    // Window initialization
    Window window = {WINDOW_DW, WINDOW_DH, mainMenu, "C2048", true};

    InitWindow(window.width, window.height, window.name);
    InitAudioDevice();

    Shader postProcess = LoadShader(0, SCAN_LINES);
    int noiseLoc = GetShaderLocation(postProcess, "textureNoise");
    int resolutionLoc = GetShaderLocation(postProcess, "resolution");
    int timeLoc = GetShaderLocation(postProcess, "time");

    float resolution[2] = {window.width, window.height};
    SetShaderValueTexture(postProcess, noiseLoc, LoadTexture(RGB_NOISE));
    SetShaderValue(postProcess, resolutionLoc, resolution, UNIFORM_VEC2);

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

    float totalTime = 0.0f;

    SetTargetFPS(60);
    // Main Scene loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        totalTime += GetFrameTime();
        SetShaderValue(postProcess, timeLoc, &totalTime, UNIFORM_FLOAT);

        switch (window.screenState)
        {
        case mainMenu:
            // Buttons controll
            mainMenuBtAction(&menuScreen, &(window.screenState));
            drawMainMenu(menuScreen, postProcess);
            break;
        case game:
            gameSceneAction(&gameScreen, &(window.screenState), &gameState);
            drawGameScene(gameScreen, gameState);
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
            deInitMainMenu(&menuScreen);
            deInitGameScene(&gameScreen);
            UnloadShader(postProcess);
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
    // Close window and OpenGL context
    UnloadShader(postProcess);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
