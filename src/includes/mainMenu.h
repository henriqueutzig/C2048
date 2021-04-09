#include "button.h"
#include "assets.h"
#include "UI.h"

typedef struct MainMenu
{
    ElementUI logo;
    Button btLoadGame;
    Button btNewGame;
    Button btCredits;
    Button btHighScores;
    Button btQuit;
} MainMenu;

void drawMainMenu(MainMenu mainMenu);
void mainMenuBtAction(MainMenu *menuScreen, int *screenState);
MainMenu initMainMenu();
void deInitMainMenu(MainMenu *mainMenu);