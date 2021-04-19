#ifndef _SaveManager
#define _SaveManager

#include "gameLogic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILES_PATH "src/files/saves/"
#define SGAME_PATH FILES_PATH "game.bin"
#define SHIGHSCORE_PATH "highscore.txt"

typedef struct SavedGame
{
    bool exists;
    Card boardState[BOARD_SIZE][BOARD_SIZE];
    GameState gameState;
} SavedGame;

SavedGame loadGame();
bool saveGame(GameState gameState, Card *boardState);

#endif