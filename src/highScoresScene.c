#include "includes/highScoresScene.h"
#include "includes/window.h"
#include "includes/gameScene.h"

void drawHighScoresScene(HighScoresScene highScoresScene, Ranker rank[N_MAX_RANKERS], int nHS)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    drawButton(highScoresScene.btMainMenu);
    drawRankingBlock(highScoresScene.rankingBlock, highScoresScene.medal, rank, nHS);
    drawElementUI(highScoresScene.leaderboardTitle);

    EndDrawing();
}

void highScoresSceneAction(HighScoresScene *highScoresScene, int *screenState)
{
    if (buttonState(&highScoresScene->btMainMenu))
        *screenState = mainMenu;
}

HighScoresScene initHighScores()
{
    HighScoresScene window;

    window.btMainMenu = initButton(LoadTexture(BT_BACK), 1, LoadSound(BT_SOUND), (Vector2){20, 10});
    window.medal = initElementUI(LoadTexture(MEDAL_SMALL), (Vector2){0, 0});
    window.leaderboardTitle = initElementUI(LoadTexture(LEADERBOARD), (Vector2){198, 68});
    window.rankingBlock = initElementTextUI(LoadTexture(RANKING_BLOCK), (Vector2){227, 151}, WHITE, 16);

    return window;
}

void deInitHighScores(HighScoresScene *highScoresScene)
{
    deinitElementUI(&highScoresScene->rankingBlock);
    deinitElementUI(&highScoresScene->medal);
    deInitButton(&highScoresScene->btMainMenu);
}