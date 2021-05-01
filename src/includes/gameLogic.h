/**
 ******************************************************************************
 * @file    gameLogic.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Structs and functions needed for the game logic.
 ******************************************************************************
 */

#ifndef _GameLogic
#define _GameLogic

/* Includes ------------------------------------------------------------------*/

#include "raylib.h"
#include "assets.h"
#include "UI.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Exported constants --------------------------------------------------------*/

#define BOARD_SIZE 4
#define CARD_SIZE 80
#define REC_SRC_NULL (Rectangle) { 0, 0, CARD_SIZE, CARD_SIZE }
#define CARD_VOID (Card) { REC_SRC_NULL, 0 }
#define FILES_PATH "src/files/saves/"
#define MAX_FILE_PATH 256

/* Exported types ------------------------------------------------------------*/

/**
 *  @enum CardValue
 *  @brief Possible values for a card.
 */
typedef enum CardValue
{
    C0,
    C2,
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
} CardValue;

/**
 *  @enum Move
 *  @brief Possible board movements.
 */
typedef enum Move
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
} Move;

/**
 *  @enum GameSituation
 *  @brief Possible games situation.
 */
typedef enum GameSituation
{
    ON_GOING,
    GAME_OVER,
    WON
} GameSituation;

/**
 *  @struct Card
 *  @brief Struct of a card.
 */
typedef struct Card
{
    Rectangle recSrc;
    CardValue value;
} Card;

/**
 *  @struct GameState
 *  @brief Struct of the game state.
 */
typedef struct GameState
{
    Card *currentBoardState[BOARD_SIZE][BOARD_SIZE];
    Texture2D cardTexture;
    int movements;
    int score;
} GameState;

/**
 *  @struct SavedGame
 *  @brief Struct of the game to be saved.
 */
typedef struct SavedGame
{
    bool exists;
    Card boardState[BOARD_SIZE][BOARD_SIZE];
    GameState gameState;
} SavedGame;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn initGameState
 * @brief Initiaizes all elements whithin GameState struct.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param cardTexture: Texture2D struct with the sprite of all cards.
 * @param movements: initial value for movements.
 * @param score: initial value for score.
 * @return GameState struct initialized.
 */
GameState initGameState(Card *gameBoard, Texture2D cardTexture, int movements, int score);

/**
 * @fn moveCards
 * @brief Executes a board movement.
 * @param gameState: pointer to a GameState struct with the current game state.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param moveType: movement to be performed.
 * @return game situation after the movement.
 */
GameSituation moveCards(GameState *gameState, Card *gameBoard, Move moveType);

/**
 * @fn getGameSituation
 * @brief Gets current game situation.
 * @param gameState: pointer to a GameState struct with the current game state.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @return current game situation.
 */
GameSituation getGameSituation(GameState *gameState, Card *gameBoard);

/**
 * @fn moveCardsUp
 * @brief Moves up all cards in the board.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param score: pointer to the current score.
 * @return TRUE if any card could move up or sum.
 */
bool moveCardsUp(Card *gameBoard, int *score);

/**
 * @fn keyToMove
 * @brief Maps a key to a movement type.
 * @param key: ASCII code of the desired key.
 * @return movement type equivalent with the key, -1 if non where found.
 */
Move keyToMove(int key);

/**
 * @fn generateRandomCard
 * @brief Generates a random card in the board (2 or 4).
 * @param gameState: pointer to a GameState struct with the current game state.
 * @param gameBoard: pointer to a Card matrix with the current board.
 */
void generateRandomCard(GameState *gameState, Card *gameboard);

/**
 * @fn rotateBoardLeft
 * @brief Rotates the matrix of cards to the left.
 * @param gameBoard: pointer to a Card matrix with the current board.
 */
void rotateBoardLeft(Card *gameBoard);

/**
 * @fn boardHasEmptySlots
 * @brief Checks if the board has any empty slot.
 * @param gameState: pointer to a GameState struct with the current game state.
 * @return TRUE if the board has a empty slot.
 */
bool boardHasEmptySlots(GameState *gameState);

/**
 * @fn restartGame
 * @brief Restarts the game board and game state.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param gameState: pointer to a GameState struct with the current game state.
 */
void restartGame(Card *gameBoard, GameState *gameState);

/**
 * @fn loadGame
 * @brief Loads a game state from a file.
 * @param path: path of the file to load.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @return GameState struct with the contents of the file.
 */
GameState loadGame(char path[MAX_FILE_PATH], Card *gameBoard);

/**
 * @fn saveGame
 * @brief Saves a game state in a file.
 * @param gameState: GameState struct with the current game state.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param path: path to save the file.
 */
void saveGame(GameState gameState, Card *gameBoard, char path[MAX_FILE_PATH]);

/**
 * @fn copyCardMatrix
 * @brief Copies a card matrix to another.
 * @param dest: pointer to the source Card matrix.
 * @param src: pointer to the destine Card matrix.
 */
void copyCardMatrix(Card *dest, Card *src);

/**
 * @fn deslocateCards
 * @brief Deslocate all card from the current row and column to the next row of the same column ultil the end.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param currentRow: row to start the deslocation.
 * @param column: column where de deslocation will occur.
 */
void deslocateCards(Card *gameBoard, int currentRow, int column);

/**
 * @fn checkNonZerosBelowRow
 * @brief Checks if there are any non zero card below the current row in the same column.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param currentRow: row to start the deslocation.
 * @param column: column where de deslocation will occur.
 */
bool checkNonZerosBelowRow(Card *gameBoard, int currentRow, int column);

#endif