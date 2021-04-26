#include "includes/highScoresScene.h"
#include "includes/window.h"
#include "includes/gameScene.h"

HighScoresScene initHighScores()
{
    HighScoresScene window;

    window.btMainMenu = initButton(LoadTexture(BT_BACK), 1, LoadSound(BT_SOUND), (Vector2){20, 10});
    window.medal = initElementUI(LoadTexture(MEDAL_SMALL), (Vector2){0, 0});
   
    Image rbImg = LoadImage(RANKING_BLOCK);
    ImageResize(&rbImg, (rbImg.width * 1.5), (rbImg.height * 1.5));
    window.rankingBlock = initElementTextUI(LoadTextureFromImage(rbImg), (Vector2){190, 75}, WHITE, 26);

    return window;
}

void deInitHighScores(HighScoresScene *highScoresScene)
{
    deinitElementUI(&highScoresScene->rankingBlock);
    deinitElementUI(&highScoresScene->medal);
    deInitButton(&highScoresScene->btMainMenu);
}

void drawHighScoresScene(HighScoresScene highScoresScene, char highScores[][LEN_RANKER])
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    drawButton(highScoresScene.btMainMenu);
    drawRankingBlock(highScoresScene.rankingBlock, highScoresScene.medal, highScores, N_RANKERS, HS_NAME_SPACING, HS_MEDAL_OFFSET, HS_NAME_OFFSET);

    EndDrawing();
}

void highScoresSceneAction(HighScoresScene *highScoresScene, int *screenState)
{
    if(buttonState(&highScoresScene->btMainMenu))
        *screenState = mainMenu;
}