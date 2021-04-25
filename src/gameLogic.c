#include "includes/gameLogic.h"

GameState initGameState(Card *currentBoardState, Texture2D cardTexture, int movements, int score)
{
    GameState gameState = (GameState){.oldBoardState = {NULL}};
    gameState.cardTexture = cardTexture;
    gameState.movements = movements;
    gameState.score = score;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            gameState.currentBoardState[i][j] = (currentBoardState + i * BOARD_SIZE + j)->value == 0 ? NULL : (currentBoardState + i * BOARD_SIZE + j);

    return gameState;
}

void deslocateCards(Card *gameBoard, int currentRow, int column)
{
    for (size_t r = currentRow; r < BOARD_SIZE - 1; r++)
    {
        (gameBoard + r * BOARD_SIZE + column)->value = (gameBoard + (r + 1) * BOARD_SIZE + column)->value;
        (gameBoard + r * BOARD_SIZE + column)->recSrc = getRectSpriteFromMatrix((gameBoard + r * BOARD_SIZE + column)->value, 3, 4, CARD_SIZE, CARD_SIZE);
    }
    *(gameBoard + (BOARD_SIZE - 1) * BOARD_SIZE + column) = CARD_VOID;
}

bool moveCardsUp(Card *gameBoard, int *score)
{
    bool isValidMove = false;
    int sumControl = 0;

    for (int c = 0; c < BOARD_SIZE; c++)
    {
        for (int r = BOARD_SIZE - 1; r >= 0; r--)
        {
            if (sumControl == 1)
                sumControl++;
            else if (sumControl == 2)
                sumControl = 0;

            if ((gameBoard + r * BOARD_SIZE + c)->value != 0 && (gameBoard + r * BOARD_SIZE + c)->value == (gameBoard + (r - 1) * BOARD_SIZE + c)->value && !sumControl)
            {
                (gameBoard + (r - 1) * BOARD_SIZE + c)->value++;
                (gameBoard + (r - 1) * BOARD_SIZE + c)->recSrc = getRectSpriteFromMatrix((gameBoard + (r - 1) * BOARD_SIZE + c)->value, 3, 4, CARD_SIZE, CARD_SIZE);
                *score += pow(2, (gameBoard + (r - 1) * BOARD_SIZE + c)->value);
                deslocateCards(gameBoard, r, c);
                sumControl++;
                isValidMove = true;
            }
            else if ((gameBoard + (r - 1) * BOARD_SIZE + c)->value == 0)
            {
                (gameBoard + (r - 1) * BOARD_SIZE + c)->value = (gameBoard + r * BOARD_SIZE + c)->value;
                (gameBoard + (r - 1) * BOARD_SIZE + c)->recSrc = getRectSpriteFromMatrix((gameBoard + (r - 1) * BOARD_SIZE + c)->value, 3, 4, CARD_SIZE, CARD_SIZE);
                deslocateCards(gameBoard, r, c);
                isValidMove = true;
            }
        }
    }

    return isValidMove;
}

bool moveCards(GameState *gameState, Card *gameBoard, int moveType)
{
    bool isValidMove = false;
    Card tmpGameBoard[BOARD_SIZE][BOARD_SIZE] = {CARD_VOID};

    copyMatrix(&tmpGameBoard[0][0], gameBoard);

    if (moveType > 0)
    {
        for (int i = 0; i < moveType; i++)
            rotateBoardLeft(&tmpGameBoard[0][0]);
        isValidMove = moveCardsUp(&tmpGameBoard[0][0], &gameState->score);
        for (int i = 0, n = (4 - moveType); i < n; i++)
            rotateBoardLeft(&tmpGameBoard[0][0]);
    }
    else
        isValidMove = moveCardsUp(&tmpGameBoard[0][0], &gameState->score);

    if (isValidMove)
    {
        gameState->movements++;
        copyMatrix(gameBoard, &tmpGameBoard[0][0]);
        *gameState = initGameState(gameBoard, gameState->cardTexture, gameState->movements, gameState->score);
        generateRandomCard(gameState, gameBoard);
    }
    return isValidMove;
}

int keyToMove(int key)
{
    switch (key)
    {
    case KEY_UP:
        return UP;
    case KEY_RIGHT:
        return RIGHT;
    case KEY_DOWN:
        return DOWN;
    case KEY_LEFT:
        return LEFT;
    }
}

bool boardHasEmptySlots(GameState *gameState)
{
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            if (*(gameState->currentBoardState[0] + r * BOARD_SIZE + c) == NULL)
                return true;
    return false;
}

void rotateBoardLeft(Card *gameBoard)
{
    // based on https://github.com/mevdschee/2048.c/blob/main/2048.c rotateBoard function
    for (int r = 0; r < BOARD_SIZE / 2; r++)
    {
        for (int c = r; c < BOARD_SIZE - r - 1; c++)
        {
            Card tmp = *(gameBoard + r * BOARD_SIZE + c);
            *(gameBoard + r * BOARD_SIZE + c) = *(gameBoard + c * BOARD_SIZE + (BOARD_SIZE - r - 1));
            *(gameBoard + c * BOARD_SIZE + (BOARD_SIZE - r - 1)) = *(gameBoard + (BOARD_SIZE - r - 1) * BOARD_SIZE + (BOARD_SIZE - c - 1));
            *(gameBoard + (BOARD_SIZE - r - 1) * BOARD_SIZE + (BOARD_SIZE - c - 1)) = *(gameBoard + (BOARD_SIZE - c - 1) * BOARD_SIZE + r);
            *(gameBoard + (BOARD_SIZE - c - 1) * BOARD_SIZE + r) = tmp;
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
    Card boardEmpty[BOARD_SIZE][BOARD_SIZE] = {CARD_VOID};

    copyMatrix(gameBoard, &boardEmpty[0][0]);
    *gameState = initGameState(gameBoard, gameState->cardTexture, 0, 0);
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

    copyMatrix(initialBoardState, &data.boardState[0][0]);

    return initGameState(initialBoardState, data.gameState.cardTexture, data.gameState.movements, data.gameState.score);
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

void copyMatrix(Card *dest, Card *src)
{
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            *(dest + r * BOARD_SIZE + c) = *(src + r * BOARD_SIZE + c);
}