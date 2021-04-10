#include "raylib.h"
#include "assets.h"
#include <stddef.h>
#include <string.h>

#define BOARD_SIZE 4
#define CARD_SIZE 80
#define REC_SRC_NULL (Rectangle){ 0, 0, CARD_SIZE, CARD_SIZE }
#define CARD_VOID (Card) {REC_SRC_NULL, 0 }

enum CardValue
{
    C2 = 1,
    C4,
    C8,
    C16,
    C32,
    C64,
    C128,
    C256,
    C512,
    C1024,
    C2048
};

typedef struct Card
{
    Rectangle recSrc;
    int value;
} Card;

typedef struct GameState
{
    Card *currentBoardState[BOARD_SIZE][BOARD_SIZE];
    Card *oldBoardState[BOARD_SIZE][BOARD_SIZE];
    Texture2D cardTexture;
    int movements;
    int score;
} GameState;

GameState initGameState(Card *currentBoardState, Texture2D cardTexture, int movements, int score);