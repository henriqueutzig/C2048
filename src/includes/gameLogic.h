#include "raylib.h"
#include "assets.h"

#define BOARD_SIZE 4

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

// typedef struct Card
// {
//     // retangulo de recorte da sprite
//     Rectangle recSrc;
//     int value;
// } Card;

typedef struct GameState
{
    int currentBoardState[BOARD_SIZE][BOARD_SIZE];
    int oldBoardState[BOARD_SIZE][BOARD_SIZE];
    Texture2D cardTexture;
    int movements;
    int score;
} GameState;

GameState initGameState(int currentBoardState[BOARD_SIZE][BOARD_SIZE], Texture2D cardTexture, int movements, int score);