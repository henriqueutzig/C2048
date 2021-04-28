#ifndef _MainMenu
#define _MainMenu

#include "fileDialog.h"
#include "button.h"
#include "assets.h"
#include "gameLogic.h"
#include "UI.h"

typedef struct MainMenu
{
    ElementUI logo;
    Button btLoadGame;
    Button btNewGame;
    Button btCredits;
    Button btHighScores;
    Button btQuit;
    GuiFileDialogState fileDialogState;
} MainMenu;

void drawMainMenu(MainMenu *mainMenu);
void mainMenuBtAction(MainMenu *menuScreen, int *screenState, Card *initialBoardState, GameState *gameState);
MainMenu initMainMenu();
void deInitMainMenu(MainMenu *mainMenu);
#endif