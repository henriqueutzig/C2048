#ifndef _GameLogic
#define _GameLogic

#include "raylib.h"
#include "assets.h"
#include "UI.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BOARD_SIZE 4
#define CARD_SIZE 80
#define REC_SRC_NULL (Rectangle) { 0, 0, CARD_SIZE, CARD_SIZE }
#define CARD_VOID (Card) { REC_SRC_NULL, 0 }

#define FILES_PATH 
#define SGAME_PATH FILES_PATH "game.bin"

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

enum move
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
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

typedef struct SavedGame
{
    bool exists;
    Card boardState[BOARD_SIZE][BOARD_SIZE];
    GameState gameState;
} SavedGame;

GameState initGameState(Card *currentBoardState, Texture2D cardTexture, int movements, int score);
bool moveCards(GameState *gameState, Card *gameBoard, int moveType);
bool moveCardsUp(Card *gameBoard, int *score);
int keyToMove(int key);
void generateRandomCard(GameState *gameState, Card *gameboard);
void rotateBoardLeft(Card *gameBoard);
bool boardHasEmptySlots(GameState *gameState);
void restartGame(Card *gameBoard, GameState *gameState);
GameState loadGame(char path[512], Card *initialBoardState);
bool saveGame(GameState gameState, Card *boardState, char path[512]);
void copyMatrix(Card *dest, Card *src);

#endif