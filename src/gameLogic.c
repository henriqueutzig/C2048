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

void moveCardsUp(GameState *gameState, Card *gameBoard)
{
    bool isValidMove = false;
    // TODO: I'm baging me head against the keyboard for 3 hours and I couldn't implement this
    if (isValidMove && boardAsEmptySlots(gameState))
        generateRandomCard(gameState, gameBoard);
}

void moveCards(GameState *gameState, Card *gameBoard, int moveType)
{
    if (moveType > 0)
    {
        for (int i = 0; i < moveType; i++)
            rotateBoardLeft(gameState);
        moveCardsUp(gameState, gameBoard);
        for (int i = 0, n = (BOARD_SIZE - moveType); i < n; i++)
            rotateBoardLeft(gameState);
    }
    else
        moveCardsUp(gameState, gameBoard);
}

bool boardAsEmptySlots(GameState *gameState)
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            if (*(gameState->currentBoardState[0] + r * BOARD_SIZE + c) == NULL)
            {
                return true;
            }
        }
    }

    return false;
}

void rotateBoardLeft(GameState *gameState)
{
    // based on https://github.com/mevdschee/2048.c/blob/main/2048.c rotateBoard function
    for (int r = 0; r < BOARD_SIZE / 2; r++)
    {
        for (int c = r; c < BOARD_SIZE - r - 1; c++)
        {
            Card *tmp = *(gameState->currentBoardState[0] + r * BOARD_SIZE + c);
            *(gameState->currentBoardState[0] + r * BOARD_SIZE + c) = *(gameState->currentBoardState[0] + c * BOARD_SIZE + (BOARD_SIZE - r - 1));
            *(gameState->currentBoardState[0] + c * BOARD_SIZE + (BOARD_SIZE - r - 1)) = *(gameState->currentBoardState[0] + (BOARD_SIZE - r - 1) * BOARD_SIZE + (BOARD_SIZE - c - 1));
            *(gameState->currentBoardState[0] + (BOARD_SIZE - r - 1) * BOARD_SIZE + (BOARD_SIZE - c - 1)) = *(gameState->currentBoardState[0] + (BOARD_SIZE - c - 1) * BOARD_SIZE + r);
            *(gameState->currentBoardState[0] + (BOARD_SIZE - c - 1) * BOARD_SIZE + r) = tmp;
        }
    }
}

// Only call this function when the currentBoardState is the same as initialBoardState
void generateRandomCard(GameState *gameState, Card *gameBoard)
{
    int x, y;

    do
    {
        x = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));
        y = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));
    } while ((*(gameState->currentBoardState[0] + y * BOARD_SIZE + x) != NULL));

    int newCardEnum = (1 + (rand() % (10 - 1 + 1))) > 9 ? C4 : C2;
    Card newCard = {getRectSpriteFromMatrix(newCardEnum, 3, 4, CARD_SIZE, CARD_SIZE), newCardEnum};

    // Trying to change the null value into newCard
    // Somehow it works, so lets try and not touch it
    *(gameBoard + y * BOARD_SIZE + x) = newCard;
    *(gameState->currentBoardState[0] + y * BOARD_SIZE + x) = (gameBoard + y * BOARD_SIZE + x);
}

void restartGame(Card *gameBoard, GameState *gameState)
{
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            *(gameBoard + r * BOARD_SIZE + c) = CARD_VOID;
    *gameState = initGameState(gameBoard, LoadTexture(CARDS), 0, 0);
    for (int i = 0; i < 2; i++)
        generateRandomCard(gameState, gameBoard);
}

GameState loadGame(char path[512], Card *initialBoardState)
{
    FILE *saveFile = fopen(path, "rb+");
    if (saveFile == NULL)
    {
        return initGameState(initialBoardState, LoadTexture(CARDS), 0, 0);
    }

    SavedGame data;
    fread(&data, sizeof(SavedGame), 1, saveFile);
    fflush(saveFile);
    fclose(saveFile);

    data.exists = true;

    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            *(initialBoardState + r * BOARD_SIZE + c) = data.boardState[r][c];

    return initGameState(initialBoardState, LoadTexture(CARDS), 0, 0);
}

bool saveGame(GameState gameState, Card *boardState, char path[512])
{
    FILE *saveFile = fopen(path, "wb+");
    SavedGame data;

    if (saveFile == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o arquivo\n");
        return false;
    }

    data.exists = true;
    data.gameState = gameState;
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            data.boardState[r][c] = *(boardState + r * BOARD_SIZE + c);

    fwrite(&data, sizeof(SavedGame), 1, saveFile);
    fflush(saveFile);
    fclose(saveFile);

    return true;
}