#include "button.h"
#include "assets.h"

typedef struct MainMenu
{
    Texture2D gameLogo;
    float logoX;
    float logoY;
    Button btLoadGame;
    Button btNewGame;
    Button btCredits;
    Button btHighScores;
    Button btQuit;
} MainMenu;

void drawMainMenu(int *screenState, MainMenu *mainMenu);
void mainMenuBtAction(MainMenu *menuScreen, int *screenState);
MainMenu initMainMenu(int w_w, int w_h);
void deInitMainMenu(MainMenu *mainMenu);