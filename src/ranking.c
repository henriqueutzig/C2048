#include "includes/ranking.h"

bool loadRankers(Ranker *rankers)
{
    FILE *file = fopen(SHIGHSCORE_PATH, "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o arquivo\n");
        return false;
    }

    for(int i = 0; i < N_MAX_RANKERS; i++)
    {
        int n = 0;
        char aux;
        do
        {
            aux =  fgetc(file); 
            if(isalpha(aux))
            {
                (rankers + i)->name[n] = aux;
                n++;
            }
            else if(aux == ' ')
                (rankers + i)->name[n] = '\0';
        } while ((aux != ' ') && (n < NAME_SIZE));
        
        fscanf(file, "%i", &(rankers + i)->score);
        printf("(%i) %s %i\n", i, ((rankers + i)->name == ' ')? "null":(rankers + i)->name, (rankers + i)->score);
    }

    fflush(file);
    fclose(file);
    return true;
}


bool saveNewRanker(Ranker *arrRankers , Ranker newRanker)
{
    bool rewriteHighscores = false; 
    Ranker aux, _aux; 
    for (int i = 0; i < N_MAX_RANKERS; i++)
    {
        // if((newRanker.score > (arrRankers+i)->score) && rewriteHighscores == false)
        // {
        //     aux = *(arrRankers+i);
        //     *(arrRankers+i) = newRanker;
        //     rewriteHighscores = true;
        // }
        // else if(rewriteHighscores)
        // {
        //     _aux = *(arrRankers+i);
        //     *(arrRankers+i) = aux;
        // }
    }
    
}