#include "includes/gameScene.h"
#include "includes/window.h"

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
void drawRankingBlock(ElementUI rankingBlockUI, ElementUI medal, char names[][MAX_STRING_SIZE], int size, int nameSpacing, int medalXOffset, int nameYOffset)
{
    DrawTexture(rankingBlockUI.texture, rankingBlockUI.pos.x, rankingBlockUI.pos.y, WHITE);

    for (int i = 0; i < size; i++)
    {
        int posX = rankingBlockUI.pos.x + 10;
        int posY = rankingBlockUI.pos.y + (i * nameSpacing) + nameYOffset;
        switch (i)
        {
        case 0:
            DrawText(TextFormat("%s", names[i]), posX, posY, rankingBlockUI.fontSize, DRACULA_YELLOW);
            DrawTextureRec(medal.texture, getRectSpriteFromArray(GOLD_MEDAL, MEDAL_SIZE_W, MEDAL_SIZE_H), (Vector2){posX + medalXOffset, posY + 3}, WHITE);
            break;
        case 1:
            DrawText(TextFormat("%s", names[i]), posX, posY, rankingBlockUI.fontSize, rankingBlockUI.color);
            DrawTextureRec(medal.texture, getRectSpriteFromArray(SILVER_MEDAL, MEDAL_SIZE_W, MEDAL_SIZE_H), (Vector2){posX + medalXOffset, posY + 3}, WHITE);
            break;
        case 2:
            DrawText(TextFormat("%s", names[i]), posX, posY, rankingBlockUI.fontSize, rankingBlockUI.color);
            DrawTextureRec(medal.texture, getRectSpriteFromArray(BRONZE_MEDAL, MEDAL_SIZE_W, MEDAL_SIZE_H), (Vector2){posX + medalXOffset, posY + 3}, WHITE);
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
            DrawTextureRec(gameState.cardTexture,
                           gameState.currentBoardState[i][j] == NULL ? REC_SRC_NULL : gameState.currentBoardState[i][j]->recSrc,
                           (Vector2){(board.pos.x + MARGIN_CARD) + (j * (MARGIN_CARD + CARD_SIZE)),
                                     (board.pos.y + MARGIN_CARD) + (i * (MARGIN_CARD + CARD_SIZE))},
                           WHITE);
        }
    }
}

void drawGameScene(GameScene *gameScene, GameState gameState, char highScores[][MAX_STRING_SIZE], int nHS)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    if (gameScene->saveGameDialog.isActive || gameScene->newGameDialog.isActive || gameScene->quitGameDialog.isActive)
        GuiLock();

    DrawTexture(gameScene->board.texture, gameScene->board.pos.x, gameScene->board.pos.y, WHITE);

    drawBoardCards(gameState, gameScene->board);

    drawScoreBlock(gameScene->scoreBlock, gameState.score);
    drawMovementBlock(gameScene->movementBlock, gameState.movements);
    drawRankingBlock(gameScene->rankingBlock, gameScene->medal, highScores, nHS, NAME_SPACING, MEDAL_X_OFFSET, NAME_Y_OFFSET);

    drawElementUI(gameScene->quitKey);
    drawElementUI(gameScene->newGameKey);
    drawElementUI(gameScene->saveKey);
    drawElementUI(gameScene->movementsKey);

    drawButton(gameScene->btBackToMenu);

    GuiUnlock();
    if (gameScene->newGameDialog.isActive)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BACKGROUND_COLOR, 0.85f));
        gameScene->newGameDialog.buttonPressed = GuiMessageBox((Rectangle){WINDOW_DW / 2 - 100, WINDOW_DH / 2 - 50, 200, 100}, "New Game", "Wish to start a new game ?", "YES;NO");
    }
    else if (gameScene->quitGameDialog.isActive)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BACKGROUND_COLOR, 0.85f));
        gameScene->quitGameDialog.buttonPressed = GuiMessageBox((Rectangle){WINDOW_DW / 2 - 100, WINDOW_DH / 2 - 50, 200, 100}, "Quit", "Wish to quit the game ?", "YES;NO");
    }
    else if (gameScene->saveGameDialog.isActive)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BACKGROUND_COLOR, 0.85f));
        gameScene->saveGameDialog.buttonPressed = GuiTextInputBox((Rectangle){WINDOW_DW / 2 - 100, WINDOW_DH / 2 - 50, 200, 125}, "Save file", "Insert the name of the save", "SAVE;CANCEL", gameScene->saveFileName);
    }

    EndDrawing();
}

void gameSceneAction(GameScene *gameScene, int *screenState, GameState *gameState, Card *gameBoard)
{
    if (gameScene->saveGameDialog.isActive || gameScene->newGameDialog.isActive || gameScene->quitGameDialog.isActive)
    {
        if (gameScene->newGameDialog.buttonPressed == -1 || gameScene->saveGameDialog.buttonPressed == -1 || gameScene->quitGameDialog.buttonPressed == -1)
        {
            return;
        }
        if (gameScene->saveGameDialog.buttonPressed == YES)
        {
            gameScene->saveGameDialog.buttonPressed = NO;
            gameScene->saveGameDialog.isActive = false;
            saveGame(*gameState, gameBoard, TextFormat("%s/%s%s", FILES_PATH, gameScene->saveFileName, ".bin"));
        }
        else if (gameScene->newGameDialog.buttonPressed == YES)
        {
            gameScene->newGameDialog.buttonPressed = NO;
            gameScene->newGameDialog.isActive = false;
            restartGame(gameBoard, gameState);
        }
        else if (gameScene->quitGameDialog.buttonPressed == YES)
        {
            gameScene->quitGameDialog.buttonPressed = NO;
            gameScene->quitGameDialog.isActive = false;
            *screenState = mainMenu;
        }
        else
        {
            gameScene->saveGameDialog.isActive = false;
            gameScene->newGameDialog.isActive = false;
            gameScene->quitGameDialog.isActive = false;
        }
        return;
    }

    if (buttonState(&(gameScene->btBackToMenu)))
        *screenState = mainMenu;

    int keyPressed = GetKeyPressed();

    switch (keyPressed)
    {
    case KEY_UP:
    case KEY_DOWN:
    case KEY_LEFT:
    case KEY_RIGHT:
        moveCards(gameState, gameBoard, keyToMove(keyPressed));
        break;

    case KEY_S:
        gameScene->saveGameDialog.isActive = true;
        break;
    case KEY_N:
        gameScene->newGameDialog.isActive = true;
        break;
    case KEY_ESCAPE:
        gameScene->quitGameDialog.isActive = true;
        break;
    }
}

GameScene initGameScene()
{
    GameScene window;
    window.board = initElementUI(LoadTexture(BOARD_BG), (Vector2){18, 40});
    window.movementBlock = initElementTextUI(LoadTexture(MOVEMENT_BLOCK), (Vector2){436, 40}, WHITE, 20);
    window.scoreBlock = initElementTextUI(LoadTexture(SCORE_BLOCK), (Vector2){555, 40}, WHITE, 20);
    window.rankingBlock = initElementTextUI(LoadTexture(RANKING_BLOCK), (Vector2){436, 109}, WHITE, 18);

    window.quitKey = initElementUI(LoadTexture(QUIT_KEY), (Vector2){436, 343});
    window.newGameKey = initElementUI(LoadTexture(NEW_GAME_KEY), (Vector2){436, 379});
    window.saveKey = initElementUI(LoadTexture(SAVE_KEY), (Vector2){436, 415});
    window.movementsKey = initElementUI(LoadTexture(MOVEMENTS_KEY), (Vector2){539, 349});

    window.medal = initElementUI(LoadTexture(MEDAL_SMALL), (Vector2){0, 0});

    window.btBackToMenu = initButton(LoadTexture(BT_BACK), 1, LoadSound(BT_SOUND), (Vector2){20, 10});

    window.newGameDialog = initDialogState();
    window.saveGameDialog = initDialogState();
    window.quitGameDialog = initDialogState();

    window.saveFileName[0] = '\0';

    return window;
}

DialogState initDialogState()
{
    DialogState dialogState;
    dialogState.buttonPressed = 0;
    dialogState.isActive = false;
    return dialogState;
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