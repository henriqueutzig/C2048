#include "includes/gameLogic.h"

GameState initGameState(Card *currentBoardState, Texture2D cardTexture, int movements, int score)
{
    GameState gameState = (GameState){.oldBoardState = {NULL}};
    gameState.cardTexture = cardTexture;
    gameState.movements = movements;
    gameState.score = score;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            gameState.currentBoardState[i][j] = (currentBoardState + i * BOARD_SIZE + j)->value == 0 ? NULL : (currentBoardState + i * BOARD_SIZE + j);
        }
    }
    return gameState;
}