#include "includes/ranking.h"

bool loadRankers(Ranker *rankers)
{
    FILE *file = fopen(HIGHSCORE_PATH, "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o arquivo\n");
        return false;
    }

    for (int i = 0; i < N_MAX_RANKERS; i++)
    {
        int n = 0;
        char aux;
        do
        {
            aux = fgetc(file);
            if (aux != ' ' && aux != '\n')
            {
                (rankers + i)->name[n] = aux;
                n++;
            }
            else if (aux == ' ')
                (rankers + i)->name[n] = '\0';
        } while ((aux != ' ') && (n < NAME_SIZE));

        fscanf(file, "%i", &(rankers + i)->score);
    }

    fflush(file);
    fclose(file);
    return true;
}

bool saveNewRanker(Ranker *arrRankers, Ranker newRanker)
{
    bool rewriteHighScores = false;
    printf("%s %i\t%s %i", newRanker.name, newRanker.score, (arrRankers + N_MAX_RANKERS)->name, (arrRankers + N_MAX_RANKERS)->score);
    if (newRanker.score > (arrRankers + N_MAX_RANKERS)->score)
    {
        *(arrRankers + N_MAX_RANKERS) = newRanker;
        sortRankers(arrRankers);
        updateHighScoresFile(arrRankers);
    }

    return rewriteHighScores;
}

void sortRankers(Ranker *arrRankers)
{
    int n = N_MAX_RANKERS;

    while (((arrRankers + n)->score > (arrRankers + n - 1)->score) && (n > 0))
    {
        Ranker aux = *(arrRankers + n - 1);
        *(arrRankers + n - 1) = *(arrRankers + n);
        *(arrRankers + n) = aux;
        n--;
    }
}

int updateHighScoresFile(Ranker *arrRankers)
{
    FILE *file = fopen(HIGHSCORE_PATH, "w");
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o arquivo\n");
        return false;
    }

    for (int i = 0; i < N_MAX_RANKERS; i++)
    {
        fprintf(file, "%s %i", (arrRankers + i)->name, (arrRankers + i)->score);
        if (i < (N_MAX_RANKERS - 1))
            fputc('\n', file);
    }
    fflush(file);
    return fclose(file);
}