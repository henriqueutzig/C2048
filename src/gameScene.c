#include "includes/gameScene.h"
#include "includes/window.h"

//Test
#define MAX_STRING_SIZE 40
char testNames[4][MAX_STRING_SIZE] =
    {"Test1",
     "Test2",
     "Test3",
     "Test4"};

void drawMovementBlock(ElementUI movementBlockUI, int movement)
{
    DrawTexture(movementBlockUI.texture, movementBlockUI.pos.x, movementBlockUI.pos.y, WHITE);
    DrawText(TextFormat("%04i", movement), movementBlockUI.pos.x + 10, movementBlockUI.pos.y + 22, movementBlockUI.fontSize, movementBlockUI.color);
}

void drawScoreBlock(ElementUI scoreBlockUI, int score)
{
    DrawTexture(scoreBlockUI.texture, scoreBlockUI.pos.x, scoreBlockUI.pos.y, WHITE);
    DrawText(TextFormat("%04i", score), scoreBlockUI.pos.x + 10, scoreBlockUI.pos.y + 22, scoreBlockUI.fontSize, scoreBlockUI.color);
}

void drawRankingBlock(ElementUI rankingBlockUI, char names[][MAX_STRING_SIZE], int size)
{
    DrawTexture(rankingBlockUI.texture, rankingBlockUI.pos.x, rankingBlockUI.pos.y, WHITE);

    for (int i = 0; i < size; i++)
    {
        DrawText(TextFormat("%s", names[i]), rankingBlockUI.pos.x + 10, rankingBlockUI.pos.y + (i * 22) + 22, rankingBlockUI.fontSize, rankingBlockUI.color);
    }
}

void drawGameScene(int *screenState, GameScene *gameScene)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    DrawTexture(gameScene->board.texture, gameScene->board.pos.x, gameScene->board.pos.y, WHITE);

    drawScoreBlock(gameScene->scoreBlock, 10);
    drawMovementBlock(gameScene->movementBlock, 70);
    drawRankingBlock(gameScene->rankingBlock, testNames, 4);

    EndDrawing();
}

void gameSceneAction(GameScene *gameScene, int *screenState)
{
    // if (buttonState(&(menuScreen->btLoadGame)) || buttonState(&(menuScreen->btNewGame)))
    //     *(screenState) = game;
    // if (buttonState(&(menuScreen->btHighScores)))
    //     *(screenState) = highScore;
    // if (buttonState(&(menuScreen->btCredits)))
    //     *(screenState) = credits;
    // if (buttonState(&(menuScreen->btQuit)))
    //     *(screenState) = quit;
}

GameScene initGameScene(int w_w, int w_h)
{
    GameScene window;

    window.board = initElementUI(LoadTexture(BOARD_BG), (Vector2){18, 40});
    window.movementBlock = initElementTextUI(LoadTexture(MOVEMENTBLOCK), (Vector2){436, 40}, WHITE, 20);
    window.scoreBlock = initElementTextUI(LoadTexture(SCORE_BLOCK), (Vector2){555, 40}, WHITE, 20);
    window.rankingBlock = initElementTextUI(LoadTexture(RANKING_BLOCK), (Vector2){436, 109}, WHITE, 20);

    return window;
}

void deInitGameScene(GameScene *gameScene)
{
    deinitElementUI(&gameScene->board);
    deinitElementUI(&gameScene->movementBlock);
    deinitElementUI(&gameScene->scoreBlock);
    deinitElementUI(&gameScene->rankingBlock);
}