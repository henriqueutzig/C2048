#include "includes/highScoresScene.h"
#include "includes/window.h"

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
    drawRankingBlockHS(highScoresScene, highScores);

    EndDrawing();
}

void highScoresSceneAction(HighScoresScene *highScoresScene, int *screenState)
{
    if(buttonState(&highScoresScene->btMainMenu))
        *screenState = mainMenu;
}

void drawRankingBlockHS(HighScoresScene highScoresScene, char highScores[][LEN_RANKER])
{
    DrawTexture(highScoresScene.rankingBlock.texture, highScoresScene.rankingBlock.pos.x, highScoresScene.rankingBlock.pos.y, WHITE);

    for (int i = 0; i < N_RANKERS; i++)
    {
        int posX = highScoresScene.rankingBlock.pos.x + 10;
        int posY = highScoresScene.rankingBlock.pos.y + (i * 26) + 45;
        switch (i)
        {
        case 0:
            DrawText(TextFormat("%s", highScores[i]), posX, posY, highScoresScene.rankingBlock.fontSize, DRACULA_YELLOW);
            DrawTextureRec(highScoresScene.medal.texture, getRectSpriteFromArray(_GOLD_MEDAL, _MEDAL_SIZE_W, _MEDAL_SIZE_H), (Vector2){posX + 245, posY + 3}, WHITE);
            break;
        case 1:
            DrawText(TextFormat("%s", highScores[i]), posX, posY, highScoresScene.rankingBlock.fontSize, highScoresScene.rankingBlock.color);
            DrawTextureRec(highScoresScene.medal.texture, getRectSpriteFromArray(_SILVER_MEDAL, _MEDAL_SIZE_W, _MEDAL_SIZE_H), (Vector2){posX + 245, posY + 3}, WHITE);
            break;
        case 2:
            DrawText(TextFormat("%s", highScores[i]), posX, posY, highScoresScene.rankingBlock.fontSize, highScoresScene.rankingBlock.color);
            DrawTextureRec(highScoresScene.medal.texture, getRectSpriteFromArray(_BRONZE_MEDAL, _MEDAL_SIZE_W, _MEDAL_SIZE_H), (Vector2){posX + 245, posY + 3}, WHITE);
            break;
        default:
            DrawText(TextFormat("%s", highScores[i]), posX, posY, highScoresScene.rankingBlock.fontSize, highScoresScene.rankingBlock.color);
            break;
        }
    }
}