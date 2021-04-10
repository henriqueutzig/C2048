#include "includes/gameScene.h"
#include "includes/window.h"

//Test
char testNames[4][MAX_STRING_SIZE] =
    {"Test1",
     "Test2",
     "Test3",
     "Test4"};

void drawMovementBlock(ElementUI movementBlockUI, int movement)
{
    DrawTexture(movementBlockUI.texture, movementBlockUI.pos.x, movementBlockUI.pos.y, WHITE);
    DrawText(TextFormat("%04i", movement), movementBlockUI.pos.x + 28, movementBlockUI.pos.y + 22, movementBlockUI.fontSize, movementBlockUI.color);
}

void drawScoreBlock(ElementUI scoreBlockUI, int score)
{
    DrawTexture(scoreBlockUI.texture, scoreBlockUI.pos.x, scoreBlockUI.pos.y, WHITE);
    DrawText(TextFormat("%04i", score), scoreBlockUI.pos.x + 14, scoreBlockUI.pos.y + 22, scoreBlockUI.fontSize, scoreBlockUI.color);
}

// TODO: rank com linked list
void drawRankingBlock(ElementUI rankingBlockUI, ElementUI medal, char names[][MAX_STRING_SIZE], int size)
{
    DrawTexture(rankingBlockUI.texture, rankingBlockUI.pos.x, rankingBlockUI.pos.y, WHITE);

    for (int i = 0; i < size; i++)
    {
        int posX = rankingBlockUI.pos.x + 10;
        int posY = rankingBlockUI.pos.y + (i * 22) + 32;
        switch (i)
        {
        case 0:
            DrawText(TextFormat("%s", names[i]), posX, posY, rankingBlockUI.fontSize, DRACULA_YELLOW);
            DrawTextureRec(medal.texture, getRectSpriteFromArray(GOLD_MEDAL, MEDAL_SIZE_W, MEDAL_SIZE_H), (Vector2){posX + 100, posY + 3}, WHITE);
            break;
        case 1:
            DrawText(TextFormat("%s", names[i]), posX, posY, rankingBlockUI.fontSize, rankingBlockUI.color);
            DrawTextureRec(medal.texture, getRectSpriteFromArray(SILVER_MEDAL, MEDAL_SIZE_W, MEDAL_SIZE_H), (Vector2){posX + 100, posY + 3}, WHITE);
            break;
        case 2:
            DrawText(TextFormat("%s", names[i]), posX, posY, rankingBlockUI.fontSize, rankingBlockUI.color);
            DrawTextureRec(medal.texture, getRectSpriteFromArray(BRONZE_MEDAL, MEDAL_SIZE_W, MEDAL_SIZE_H), (Vector2){posX + 100, posY + 3}, WHITE);
            break;
        default:
            DrawText(TextFormat("%s", names[i]), posX, posY, rankingBlockUI.fontSize, rankingBlockUI.color);
            break;
        }
    }
}

void drawBoardCards(GameState gameState, ElementUI board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            Rectangle recSrc = getRectSpriteFromMatrix(gameState.currentBoardState[i][j], 3, 4, CARD_SIZE, CARD_SIZE);
            DrawTextureRec(gameState.cardTexture, recSrc,
                           (Vector2){(board.pos.x + MARGIN_CARD) + (j * (MARGIN_CARD + CARD_SIZE)),
                                     (board.pos.y + MARGIN_CARD) + (i * (MARGIN_CARD + CARD_SIZE))},
                           WHITE);
        }
    }
}

void drawGameScene(GameScene gameScene, GameState gameState)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    DrawTexture(gameScene.board.texture, gameScene.board.pos.x, gameScene.board.pos.y, WHITE);

    drawBoardCards(gameState, gameScene.board);

    drawScoreBlock(gameScene.scoreBlock, 10);
    drawMovementBlock(gameScene.movementBlock, 70);
    drawRankingBlock(gameScene.rankingBlock, gameScene.medal, testNames, 4);

    drawElementUI(gameScene.quitKey);
    drawElementUI(gameScene.newGameKey);
    drawElementUI(gameScene.saveKey);
    drawElementUI(gameScene.movementsKey);

    drawButton(gameScene.btBackToMenu);

    EndDrawing();
}

void gameSceneAction(GameScene *gameScene, int *screenState, GameState *gameState)
{
    // Acoes de tecla aqui
    if(buttonState(&(gameScene->btBackToMenu)))
        *screenState = mainMenu;
}

GameScene initGameScene()
{
    GameScene window;
    window.board = initElementUI(LoadTexture(BOARD_BG), (Vector2){18, 40});
    window.movementBlock = initElementTextUI(LoadTexture(MOVEMENT_BLOCK), (Vector2){436, 40}, WHITE, 20);
    window.scoreBlock = initElementTextUI(LoadTexture(SCORE_BLOCK), (Vector2){555, 40}, WHITE, 20);
    window.rankingBlock = initElementTextUI(LoadTexture(RANKING_BLOCK), (Vector2){436, 109}, WHITE, 20);

    window.quitKey = initElementUI(LoadTexture(QUIT_KEY), (Vector2){436, 343});
    window.newGameKey = initElementUI(LoadTexture(NEW_GAME_KEY), (Vector2){436, 379});
    window.saveKey = initElementUI(LoadTexture(SAVE_KEY), (Vector2){436, 415});
    window.movementsKey = initElementUI(LoadTexture(MOVEMENTS_KEY), (Vector2){539, 349});

    window.medal = initElementUI(LoadTexture(MEDAL_SMALL), (Vector2){0, 0});

    window.btBackToMenu = initButton(LoadTexture(BT_BACK), 1, LoadSound(BT_SOUND), (Vector2){20, 10});

    return window;
}

void deInitGameScene(GameScene *gameScene)
{
    deinitElementUI(&gameScene->board);
    deinitElementUI(&gameScene->movementBlock);
    deinitElementUI(&gameScene->scoreBlock);
    deinitElementUI(&gameScene->rankingBlock);

    deinitElementUI(&gameScene->quitKey);
    deinitElementUI(&gameScene->newGameKey);
    deinitElementUI(&gameScene->saveKey);
    deinitElementUI(&gameScene->movementsKey);

    deInitButton(&(gameScene->btBackToMenu));
}