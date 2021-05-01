#include "includes/gameLogic.h"

GameState initGameState(Card *currentBoardState, Texture2D cardTexture, int movements, int score)
{
    GameState gameState = (GameState){.cardTexture = cardTexture, .movements = movements, .score = score};
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            gameState.currentBoardState[i][j] = (currentBoardState + i * BOARD_SIZE + j)->value == 0 ? NULL : (currentBoardState + i * BOARD_SIZE + j);

    return gameState;
}

void deslocateCards(Card *gameBoard, int currentRow, int column)
{
    for (int r = currentRow; r < BOARD_SIZE - 1; r++)
    {
        Card *currentCard = (gameBoard + r * BOARD_SIZE + column);
        currentCard->value = (currentCard + BOARD_SIZE)->value;
        currentCard->recSrc = getRectFrameFromMatrix(currentCard->value, 3, 4, CARD_SIZE, CARD_SIZE);
    }
    *(gameBoard + (BOARD_SIZE - 1) * BOARD_SIZE + column) = CARD_VOID;
}

bool checkNonZerosBelowRow(Card *gameBoard, int currentRow, int column)
{
    for (int r = currentRow + 1; r < BOARD_SIZE; r++)
        if ((gameBoard + r * BOARD_SIZE + column)->value != 0)
            return true;
    return false;
}

bool moveCardsUp(Card *gameBoard, int *score)
{
    bool isValidMove = false;

    for (int c = 0; c < BOARD_SIZE; c++)
    {
        for (int r = BOARD_SIZE - 1; r >= 0; r--)
        {
            if ((gameBoard + r * BOARD_SIZE + c)->value == 0)
            {
                if (checkNonZerosBelowRow(gameBoard, r, c))
                {
                    deslocateCards(gameBoard, r, c);
                    isValidMove = true;
                }
            }
        }

        for (int r = 0; r < BOARD_SIZE; r++)
        {
            Card *currentCard = (gameBoard + r * BOARD_SIZE + c);
            if (currentCard->value == 0)
                break;
            if (currentCard->value == (currentCard + BOARD_SIZE)->value)
            {
                currentCard->value++;
                currentCard->recSrc = getRectFrameFromMatrix(currentCard->value, 3, 4, CARD_SIZE, CARD_SIZE);
                *score += pow(2, currentCard->value);
                deslocateCards(gameBoard, r + 1, c);
                isValidMove = true;
            }
        }
    }

    return isValidMove;
}

GameSituation moveCards(GameState *gameState, Card *gameBoard, Move moveType)
{
    bool isValidMove = false;

    if (moveType == UP)
        isValidMove = moveCardsUp(gameBoard, &gameState->score);
    else
    {
        for (int i = 0; i < moveType; i++)
            rotateBoardLeft(gameBoard);
        isValidMove = moveCardsUp(gameBoard, &gameState->score);
        for (int i = 0, n = (4 - moveType); i < n; i++)
            rotateBoardLeft(gameBoard);
    }

    if (isValidMove)
    {
        gameState->movements++;
        *gameState = initGameState(gameBoard, gameState->cardTexture, gameState->movements, gameState->score);
        generateRandomCard(gameState, gameBoard);
    }
    return getGameSituation(gameState, gameBoard);
}

GameSituation getGameSituation(GameState *gameState, Card *gameBoard)
{
    Card auxBoard[BOARD_SIZE][BOARD_SIZE];

    // Verify if there is a 2048 card on the board
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            if ((gameBoard + r * BOARD_SIZE + c)->value == C2048)
                return WON;
            else
                auxBoard[r][c] = *(gameBoard + r * BOARD_SIZE + c);
        }
    }

    // Check if there are still valid moves, if not then gameSituation = GAME_OVER
    int tempScore = gameState->score;
    bool validMoves = false;
    for (int i = 0; i < 4; i++)
    {
        for (int r = 0; r < i; r++)
            rotateBoardLeft(&auxBoard[0][0]);
        validMoves |= moveCardsUp(&auxBoard[0][0], &tempScore);
        for (int r = 0, n = (4 - i); r < n; r++)
            rotateBoardLeft(&auxBoard[0][0]);
    }

    return validMoves ? ON_GOING : GAME_OVER;
}

Move keyToMove(int key)
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
    default:
        return -1;
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

void generateRandomCard(GameState *gameState, Card *gameBoard)
{
    int x, y;

    do
    {
        x = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));
        y = 0 + (rand() % ((BOARD_SIZE - 1) - 0 + 1));
    } while ((*(gameState->currentBoardState[0] + y * BOARD_SIZE + x) != NULL));

    int newCardEnum = (1 + (rand() % (10 - 1 + 1))) > 9 ? C4 : C2;
    Card newCard = {getRectFrameFromMatrix(newCardEnum, 3, 4, CARD_SIZE, CARD_SIZE), newCardEnum};

    *(gameBoard + y * BOARD_SIZE + x) = newCard;
    *(gameState->currentBoardState[0] + y * BOARD_SIZE + x) = (gameBoard + y * BOARD_SIZE + x);
}

void restartGame(Card *gameBoard, GameState *gameState)
{
    Card boardEmpty[BOARD_SIZE][BOARD_SIZE] = {CARD_VOID};

    copyCardMatrix(gameBoard, &boardEmpty[0][0]);
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

    copyCardMatrix(initialBoardState, &data.boardState[0][0]);

    return initGameState(initialBoardState, data.gameState.cardTexture, data.gameState.movements, data.gameState.score);
}

void saveGame(GameState gameState, Card *gameBoard, char path[MAX_FILE_PATH])
{
    FILE *saveFile = fopen(path, "wb+");
    SavedGame data;

    if (saveFile == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o arquivo\n");
        return;
    }

    data.exists = true;
    data.gameState = gameState;

    copyCardMatrix(&data.boardState[0][0], gameBoard);

    fwrite(&data, sizeof(SavedGame), 1, saveFile);
    fflush(saveFile);
    fclose(saveFile);
}

void copyCardMatrix(Card *dest, Card *src)
{
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            *(dest + r * BOARD_SIZE + c) = *(src + r * BOARD_SIZE + c);
}