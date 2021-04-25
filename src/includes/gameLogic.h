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

#define BOARD_SIZE 4
#define CARD_SIZE 80
#define REC_SRC_NULL (Rectangle) { 0, 0, CARD_SIZE, CARD_SIZE }
#define CARD_VOID (Card) { REC_SRC_NULL, 0 }

#define FILES_PATH "src/files/saves/"
#define SGAME_PATH FILES_PATH "game.bin"
#define SHIGHSCORE_PATH "highscore.txt"

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
    UP = 0,
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
void moveCards(GameState *gameState, Card *gameBoard, int moveType);
void moveCardsUp(GameState *gameState, Card *gameBoard);
void generateRandomCard(GameState *gameState, Card *gameboard);
void rotateBoardLeft(GameState *gameState);
bool boardAsEmptySlots(GameState *gameState);
void restartGame(Card *gameBoard, GameState *gameState);
GameState loadGame(char path[512], Card *initialBoardState);
bool saveGame(GameState gameState, Card *boardState, char path[512]);

#endif