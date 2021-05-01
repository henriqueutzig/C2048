/**
 ******************************************************************************
 * @file    highScoresScene.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Structs and functions needed for the high scores scene
 ******************************************************************************
 */

#ifndef _HighScoresScene
#define _HighScoresScene

/* Includes ------------------------------------------------------------------*/

#include "assets.h"
#include "button.h"
#include "UI.h"
#include <string.h>
#include "ranking.h"
#include "window.h"

/* Exported constants --------------------------------------------------------*/

#define N_RANKERS 10

#define HS_NAME_SPACING 28
#define HS_MEDAL_OFFSET 250
#define HS_NAME_OFFSET 45

/* Exported types ------------------------------------------------------------*/

/**
 *  @struct HighScoresScene
 *  @brief Struct of all data needed in the high score scene.
 */
typedef struct HighScoresScene
{
    Button btMainMenu;
    ElementUI leaderboardTitle;
    ElementUI rankingBlock;
    ElementUI medal;
} HighScoresScene;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn initHighScores
 * @brief Initiaizes all elements whithin a HighScoresScene struct.
 * @return HighScoresScene struct initialized.
 */
HighScoresScene initHighScores();

/**
 * @fn deInitHighScores
 * @brief De-initializes all elements used in the high score scene.
 * @param highScoresScene: pointer to  a HighScoresScene struct to de-initialize
 */
void deInitHighScores(HighScoresScene *highScoresScene);

/**
 * @fn drawHighScoresScene
 * @brief Draws all elements of the high score scene in screen.
 * @param highScoresScene: pointer to a HighScoresScene struct to draw.
 * @param rank: array of Ranker structs to display.
 * @param rankSize: number of Ranker structs in the array.
 */
void drawHighScoresScene(HighScoresScene highScoresScene, Ranker rank[N_MAX_RANKERS], int rankSize);

/**
 * @fn highScoresSceneAction
 * @brief Executes all high score scene logic.
 * @param highScoresScene: pointer to a HighScoresScene struct.
 * @param screenState: pointer to the current screen state.
 */
void highScoresSceneAction(HighScoresScene *highScoresScene, ScreenState *screenState);

#endif