#ifndef _HighScoresScene
#define _HighScoresScene

#include "assets.h"
#include "button.h"
#include "UI.h"
#include <string.h>

#define N_RANKERS 10
#define LEN_RANKER 31

#define _MEDAL_SIZE_W 12
#define _MEDAL_SIZE_H 15

enum _MedalNumber
{
    _GOLD_MEDAL,
    _SILVER_MEDAL,
    _BRONZE_MEDAL
};

typedef struct HighScoresScene
{
    Button btMainMenu;
    ElementUI rankingBlock;
    ElementUI medal;
} HighScoresScene;

HighScoresScene initHighScores();
void deInitHighScores(HighScoresScene *highScoresScene);

void drawHighScoresScene(HighScoresScene highScoresScene, char highScores[][LEN_RANKER]);
void drawRankingBlockHS(HighScoresScene highScoresScene, char highScores[][LEN_RANKER]);

void highScoresSceneAction(HighScoresScene *highScoresScene, int *screenState);
#endif