#include "button.h"

#define BT_LOADGAME "src/resources/textures/btLoadGame.png"
#define BT_NEWGAME "src/resources/textures/btLoadGame.png"
#define BT_HIGHSCORES "src/resources/textures/btLoadGame.png"
#define BT_CREDITS "src/resources/textures/btLoadGame.png"
#define BT_QUIT "src/resources/textures/btLoadGame.png"

typedef struct MainMenu
{
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