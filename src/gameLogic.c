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

void gameLogicAction(GameState *gameState, Card *gameBoard)
{
    // ARROW-UP
    if(IsKeyPressed(KEY_UP)) 
        moveCardsUp(gameState, gameBoard);
    // ARROW-DOWN
    // if(IsKeyPressed(KEY_DOWN)) 
        // moveCardsDown(gameState);
    // ARROW-LEFT
    // if(IsKeyPressed(KEY_LEFT)) 
        // moveCardsLeft(gameState);
    // ARROW-RIGHT
    // if(IsKeyPressed(KEY_RIGHT)) 
        // moveCardsRight(gameState);

    // Debug newCard .
    if(IsKeyPressed(KEY_F1)) 
        generateRandomCard(gameState, gameBoard);
}

void moveCardsUp(GameState *gameState, Card *gameBoard)
{
    bool isValidMove = false;

    printf("\nUp\n");
    if(isValidMove)
        generateRandomCard(gameState, gameBoard);
}

void generateRandomCard(GameState *gameState, Card *gameBoard)
{    
    int x = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));
    int y = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));

    while (*(gameState->currentBoardState[0] + y * BOARD_SIZE + x) != NULL)
    {
        x = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));
        y = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));
    }
    int newCardEnum = (1 + (rand() % (10 - 1 + 1))) >= 9 ? C4 : C2;
    Card newCard = {getRectSpriteFromMatrix(newCardEnum, 3, 4, CARD_SIZE, CARD_SIZE), newCardEnum};

    // Trying to change the null value into newCard
    // Somehow it works, so lets try and not touch it
    *(gameBoard + y * BOARD_SIZE + x) = newCard;
    *(gameState->currentBoardState[0] + y * BOARD_SIZE + x) = (gameBoard + y * BOARD_SIZE + x);
}