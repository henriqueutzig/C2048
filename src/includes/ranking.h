/**
 ******************************************************************************
 * @file    ranking.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Structs and functions needed for the ranking
 ******************************************************************************
 */

#ifndef _Ranking
#define _Ranking

/* Includes ------------------------------------------------------------------*/

#include "raylib.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Exported constants --------------------------------------------------------*/

#define HIGHSCORE_PATH "src/files/highscores/highscores.txt"

#define NAME_SIZE 9
#define N_MAX_RANKERS 10

/* Exported types ------------------------------------------------------------*/
/**
 *  @struct Ranker
 *  @brief Struct of all data needed for a ranker.
 */
typedef struct Ranker
{
    char name[NAME_SIZE];
    int score;
} Ranker;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn loadRankers
 * @brief Loads the rankers from a file.
 * @param rankers: pointer to a Ranker array with the current ranking.
 * @return TRUE if the file was opened successfully.
 */
bool loadRankers(Ranker *rankers);

/**
 * @fn saveNewRanker
 * @brief Saves a new ranker into the current rankers array.
 * @param arrRankers: pointer to a Ranker array with the current ranking.
 * @param newRanker: Ranker struct of the new ranker.
 */
void saveNewRanker(Ranker *arrRankers, Ranker newRanker);

/**
 * @fn sortRankers
 * @brief sort the rankings array downwards.
 * @param arrRankers: pointer to a Ranker array with the current ranking.
 */
void sortRankers(Ranker *arrRankers);

/**
 * @fn updateHighScoresFile
 * @brief updates the high scores file.
 * @param arrRankers: pointer to a Ranker array with the current ranking.
 * @return TRUE if the file was updated successfully.
 */
bool updateHighScoresFile(Ranker *arrRankers);

#endif