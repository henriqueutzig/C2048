#ifndef _HighScoresScene
#define _HighScoresScene

#include "assets.h"
#include "button.h"
#include "UI.h"
#include <string.h>

#define TITLE_TXT "LEADERBOARD:"

#define N_RANKERS 10
#define LEN_RANKER 31

#define HS_NAME_SPACING 28
#define HS_MEDAL_OFFSET 250
#define HS_NAME_OFFSET 45

typedef struct HighScoresScene
{
    Button btMainMenu;
    ElementUI rankingBlock;
    ElementUI medal;
} HighScoresScene;

HighScoresScene initHighScores();
void deInitHighScores(HighScoresScene *highScoresScene);

void drawHighScoresScene(HighScoresScene highScoresScene, char highScores[][LEN_RANKER]);
void highScoresSceneAction(HighScoresScene *highScoresScene, int *screenState);
#endif