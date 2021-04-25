#ifndef _Ranking
#define _Ranking

#include "raylib.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SHIGHSCORE_PATH "src/files/saves/highscores.txt"

#define NAME_SIZE 10
#define N_MAX_RANKERS 10

#define MAX_HS_LENGTH 31

typedef struct Ranker
{
    char name[10];
    int score;
} Ranker;

bool loadRankers(Ranker *rankers);
bool saveNewRanker(Ranker *arrRankers , Ranker newRanker);
int getHighScores(Ranker *arrRankers, char *str);

#endif