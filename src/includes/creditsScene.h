#ifndef _Credits
#define _Credits

#include <string.h>
#include "button.h"

#define TEXT_MAX 280
#define DEFAULT_TEXT "C2048 was made by Henrique Utzig and Pedro \nAfonso Klein as the final project for INF01202\nAlgorithms and Programming class at UFRGS"

#define URL_GIT_GAME "https://github.com/henriqueutzig/C2048"
#define URL_COLOR_PALLET "https://draculatheme.com/"
#define URL_RAYLIB "https://www.raylib.com/"

typedef struct CreditsScene
{
    char text[TEXT_MAX];
    Button btMainMenu;
    Button btGitPage;
    Button btColorPallet;
    Button btRaylib;
} CreditsScene;

void drawCreditsScene(CreditsScene creditsScene);
void creditsSceneAction(CreditsScene *creditsScene, int *screenState);
CreditsScene initCreditsScene();
void deInitCreditsScene(CreditsScene *creditsScene);

#endif