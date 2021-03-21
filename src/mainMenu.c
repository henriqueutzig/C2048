#include "includes/mainMenu.h"
#include "includes/window.h"

void drawMainMenu(int *screenState, MainMenu *mainMenu)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    drawButton(&(mainMenu->btLoadGame));
    drawButton(&(mainMenu->btNewGame));
    drawButton(&(mainMenu->btHighScores));
    drawButton(&(mainMenu->btCredits));
    drawButton(&(mainMenu->btQuit));

    EndDrawing();
}

void mainMenuBtAction(MainMenu *menuScreen, int *screenState)
{
    if (buttonState(&(menuScreen->btLoadGame)) || buttonState(&(menuScreen->btNewGame)))
        *(screenState) = game;
    if (buttonState(&(menuScreen->btHighScores)))
        *(screenState) = highScore;
    if (buttonState(&(menuScreen->btCredits)))
        *(screenState) = credits;
    if (buttonState(&(menuScreen->btQuit)))
        *(screenState) = quit;
}

// TODO: remake buttons pixel art and crop them
MainMenu initMainMenu(int w_w, int w_h)
{
    //ImageResize(Image *image, int newWidth, int newHeight);
    MainMenu window;

    window.btLoadGame = initButton((LoadTexture(BT_LOADGAME)), 3, LoadSound(BT_SOUND),
                                   (Vector2){(float)w_w / 3, (float)w_h / 4});
    window.btNewGame = initButton(LoadTexture(BT_NEWGAME), 3, LoadSound(BT_SOUND),
                                  (Vector2){(float)w_w / 3, (float)(w_h / 4 + (w_h * 0.12))});
    window.btHighScores = initButton(LoadTexture(BT_LOADGAME), 3, LoadSound(BT_SOUND),
                                     (Vector2){(float)w_w / 3, (float)(w_h / 4 + (w_h * 0.24))});
    window.btCredits = initButton(LoadTexture(BT_LOADGAME), 3, LoadSound(BT_SOUND),
                                  (Vector2){(float)w_w / 3, (float)(w_h / 4 + (w_h * 0.36))});
    window.btQuit = initButton(LoadTexture(BT_LOADGAME), 3, LoadSound(BT_SOUND),
                               (Vector2){(float)w_w / 3, (float)(w_h / 4 + (w_h * 0.48))});

    return window;
}

void deInitMainMenu(MainMenu *mainMenu)
{
    deInitButton(&(mainMenu->btLoadGame));
    deInitButton(&(mainMenu->btNewGame));
    deInitButton(&(mainMenu->btCredits));
    deInitButton(&(mainMenu->btHighScores));
    deInitButton(&(mainMenu->btQuit));
}