/**
 ******************************************************************************
 * @file    gameScene.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Structs and functions needed for the game scene
 ******************************************************************************
 */

#ifndef _GameScene
#define _GameScene

/* Includes ------------------------------------------------------------------*/

#include "UI.h"
#include "gameLogic.h"
#include "button.h"
#include "raygui.h"
#include "window.h"
#include "ranking.h"

/* Exported constants --------------------------------------------------------*/

#define MAX_STRING_SIZE 31
#define MAX_FILE_NAME_SIZE 256

#define NAME_SPACING 18
#define MEDAL_X_OFFSET 150
#define NAME_Y_OFFSET 32
#define SCORE_X_OFFSET 90

#define MARGIN_CARD 16

#define MEDAL_SIZE_W 12
#define MEDAL_SIZE_H 15

#define WIN_MESSAGE "YOU WON"
#define GAME_OVER_MESSAGE "GAME OVER"

/* Exported types ------------------------------------------------------------*/

/**
 *  @enum MedalNumber
 *  @brief Medals index on sprite.
 */
enum MedalNumber
{
    GOLD_MEDAL,
    SILVER_MEDAL,
    BRONZE_MEDAL
};

/**
 *  @enum DialogButtonState
 *  @brief Possible dialog button states.
 */
typedef enum DialogButtonState
{
    QUIT = -1,
    NONE,
    YES,
    NO
} DialogButtonState;

/**
 *  @struct DialogState
 *  @brief Struct of a dialog state.
 */
typedef struct DialogState
{
    DialogButtonState buttonPressed;
    bool isActive;
} DialogState;

/**
 *  @struct GameScene
 *  @brief Struct of all data needed in the game scene.
 */
typedef struct GameScene
{
    ElementUI board;
    ElementUI movementBlock;
    ElementUI scoreBlock;
    ElementUI rankingBlock;
    ElementUI quitKey;
    ElementUI newGameKey;
    ElementUI saveKey;
    ElementUI movementsKey;
    ElementUI medal;
    Button btBackToMenu;
    DialogState newGameDialog;
    DialogState saveGameDialog;
    DialogState quitGameDialog;
    DialogState endGameDialog;
    char saveFileName[MAX_FILE_NAME_SIZE];
    char rankingName[NAME_SIZE];
    GameSituation gameSituation;
} GameScene;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn drawBoardCards
 * @brief Draws all the cards in the board.
 * @param gameState: GameState struct with the current game state.
 * @param board: ElementUI struct that represents the board.
 */
void drawBoardCards(GameState gameState, ElementUI board);

/**
 * @fn drawMovementBlock
 * @brief Draws the movement block.
 * @param movementBlockUI: ElementUI struct that represents the movement block sprite.
 * @param movement: number of movements to display.
 */
void drawMovementBlock(ElementUI movementBlockUI, int movement);

/**
 * @fn drawScoreBlock
 * @brief Draws the score block.
 * @param scoreBlockUI: ElementUI struct that represents a score block sprite.
 * @param score: score value to display.
 */
void drawScoreBlock(ElementUI scoreBlockUI, int score);

/**
 * @fn drawRankingBlock
 * @brief Draws the ranking block.
 * @param rankingBlockUI: ElementUI struct that represents a ranking block sprite.
 * @param medal: ElementUI struct that represents a medal sprite.
 * @param rank: array of Ranker structs to display.
 * @param rankSize: number of Ranker structs in the array.
 */
void drawRankingBlock(ElementUI rankingBlockUI, ElementUI medal, Ranker rank[N_MAX_RANKERS], int rankSize);

/**
 * @fn drawGameScene
 * @brief Draws all elements of the game scene in screen.
 * @param gameScene: pointer to a GameScene struct to draw.
 * @param gameState: GameState struct of the current game.
 * @param rank: array of Ranker structs.
 * @param rankSize: number of Ranker structs in the array.
 */
void drawGameScene(GameScene *gameScene, GameState gameState, Ranker rank[N_MAX_RANKERS], int rankSize);

/**
 * @fn gameSceneAction
 * @brief Executes all game scene logic.
 * @param gameScene: pointer to a GameScene struct.
 * @param screenState: pointer to the current screen state.
 * @param gameState: pointer to a GameState struct of the current game.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param rank: pointer to a array of Ranker structs.
 */
void gameSceneAction(GameScene *gameScene, ScreenState *screenState, GameState *gameState, Card *gameBoard, Ranker *rank);

/**
 * @fn initGameScene
 * @brief Initiaizes all elements whithin a GameScene struct.
 * @return GameScene struct initialized.
 */
GameScene initGameScene();

/**
 * @fn initDialogState
 * @brief Initiaizes all default values in a DialogState struct.
 * @return DialogState struct initialized.
 */
DialogState initDialogState();

/**
 * @fn deInitGameScene
 * @brief De-initializes all elements used in the game scene.
 * @param gameScene: pointer to a GameScene struct to de-initialize
 */
void deInitGameScene(GameScene *gameScene);

#endif