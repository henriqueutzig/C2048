#include "includes/saveManager.h"

SavedGame loadGame()
{
    FILE *saveFile = fopen(SGAME_PATH, "rb+");
    if(saveFile == NULL)
    {
        return (SavedGame){false, {}, {}};
    }

    SavedGame data;
    fread(&data, sizeof(SavedGame), 1, saveFile);
    fflush(saveFile);
    fclose(saveFile);

    data.exists = true;

    return data;
}

bool saveGame(GameState gameState, Card *boardState)
{
    FILE *saveFile = fopen(SGAME_PATH, "wb+");
    if(saveFile == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o arquivo\n");
        return false;
    }

    SavedGame data;
    data.exists = true;
    data.gameState = gameState;
    for (int r = 0; r < BOARD_SIZE; r++)
        for (int c = 0; c < BOARD_SIZE; c++)
            data.boardState[r][c] = *(boardState + r * BOARD_SIZE + c);
    
    fwrite(&data, sizeof(SavedGame), 1, saveFile);
    fflush(saveFile);
    fclose(saveFile);

    return true;
}