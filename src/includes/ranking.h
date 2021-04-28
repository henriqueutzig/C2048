#ifndef _Ranking
#define _Ranking

#include "raylib.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HIGHSCORE_PATH "src/files/saves/highscores.txt"

#define NAME_SIZE 8
#define N_MAX_RANKERS 10

typedef struct Ranker
{
    char name[10];
    int score;
} Ranker;

bool loadRankers(Ranker *rankers);
bool saveNewRanker(Ranker *arrRankers, Ranker newRanker);
void sortRankers(Ranker *arrRankers);
int updateHighScoresFile(Ranker *arrRankers);

#endif