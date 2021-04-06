#include "raylib.h"
#include "assets.h"

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
    Texture2D texture;
    int value;
} Card;

typedef struct GameState
{
    Card *currentBoardState[4][4];
    Card *oldBoardState[4][4];
    int movements;
    int score;
} GameState;