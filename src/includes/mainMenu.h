#include "button.h"

#define GAME_LOGO "src/resources/textures/logo.png"

#define BT_LOADGAME "src/resources/textures/btLoadGame.png"
#define BT_NEWGAME "src/resources/textures/btNewGame.png"
#define BT_HIGHSCORES "src/resources/textures/btHighScores.png"
#define BT_CREDITS "src/resources/textures/btCredits.png"
#define BT_QUIT "src/resources/textures/btQuit.png"

typedef struct MainMenu
{
    Texture2D gameLogo;
    float logoX;
    float  logoY;
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