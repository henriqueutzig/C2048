#include "includes/mainMenu.h"
#include "includes/window.h"

void drawMainMenu(int *screenState, MainMenu *mainMenu)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);


    drawButton(&(mainMenu->btLoadGame));
    drawButton(&(mainMenu->btNewGame));
    drawButton(&(mainMenu->btHighScores));
    drawButton(&(mainMenu->btCredits));
    drawButton(&(mainMenu->btQuit));

    DrawTexture(mainMenu->gameLogo, mainMenu->logoX, mainMenu->logoY, WHITE);
    
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

MainMenu initMainMenu(int w_w, int w_h)
{
    float firstBtH = (float)(w_h / 4);
    float xBtPos = (float)(w_w / 3);
    MainMenu window;

    window.logoX = (float)(w_w / 3);
    window.logoY = w_h/10;

    window.gameLogo = LoadTexture(GAME_LOGO);

    window.btLoadGame = initButton((LoadTexture(BT_LOADGAME)), 3, LoadSound(BT_SOUND),
                                   (Vector2){xBtPos, firstBtH});
    window.btNewGame = initButton(LoadTexture(BT_NEWGAME), 3, LoadSound(BT_SOUND),
                                  (Vector2){xBtPos, (float)(firstBtH * 1.5)});
    window.btHighScores = initButton(LoadTexture(BT_HIGHSCORES), 3, LoadSound(BT_SOUND),
                                     (Vector2){xBtPos, (float)(firstBtH * 2)});
    window.btCredits = initButton(LoadTexture(BT_CREDITS), 3, LoadSound(BT_SOUND),
                                  (Vector2){xBtPos, (float)(firstBtH * 2.5)});
    window.btQuit = initButton(LoadTexture(BT_QUIT), 3, LoadSound(BT_SOUND),
                               (Vector2){xBtPos, (float)(firstBtH * 3)});

    return window;
}

void deInitMainMenu(MainMenu *mainMenu)
{
    UnloadTexture(mainMenu->gameLogo);
    deInitButton(&(mainMenu->btLoadGame));
    deInitButton(&(mainMenu->btNewGame));
    deInitButton(&(mainMenu->btCredits));
    deInitButton(&(mainMenu->btHighScores));
    deInitButton(&(mainMenu->btQuit));
}