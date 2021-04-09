#include "includes/gameLogic.h"

GameState initGameState(int currentBoardState[BOARD_SIZE][BOARD_SIZE], Texture2D cardTexture, int movements, int score)
{
    GameState gameState = (GameState){.oldBoardState = {0}};
    gameState.cardTexture = cardTexture;
    gameState.movements = movements;
    gameState.score = score;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            gameState.currentBoardState[i][j] = currentBoardState[i][j];
        }
    }
    //memcpy(gameState.currentBoardState, currentBoardState, sizeof(currentBoardState)); // TODO: ver decay
    return gameState;
}