#include "includes/highScoresScene.h"
#include "includes/window.h"
#include "includes/gameScene.h"

void drawHighScoresScene(HighScoresScene highScoresScene, Ranker rank[N_MAX_RANKERS], int rankSize)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    drawButton(highScoresScene.btMainMenu);
    drawRankingBlock(highScoresScene.rankingBlock, highScoresScene.medal, rank, rankSize);
    drawElementUI(highScoresScene.leaderboardTitle);

    EndDrawing();
}

void highScoresSceneAction(HighScoresScene *highScoresScene, ScreenState *screenState)
{
    if (updateButtonState(&highScoresScene->btMainMenu))
        *screenState = MENU_SCENE;
}

HighScoresScene initHighScores()
{
    HighScoresScene highScoresScene;

    highScoresScene.btMainMenu = initButton(LoadTexture(BT_BACK), 1, LoadSound(BT_SOUND), (Vector2){20, 10});
    highScoresScene.medal = initElementUI(LoadTexture(MEDAL_SMALL), (Vector2){0, 0});
    highScoresScene.leaderboardTitle = initElementUI(LoadTexture(LEADERBOARD), (Vector2){198, 68});
    highScoresScene.rankingBlock = initElementTextUI(LoadTexture(RANKING_BLOCK), (Vector2){227, 151}, WHITE, 16);

    return highScoresScene;
}

void deInitHighScores(HighScoresScene *highScoresScene)
{
    deinitElementUI(&highScoresScene->rankingBlock);
    deinitElementUI(&highScoresScene->medal);
    deInitButton(&highScoresScene->btMainMenu);
}