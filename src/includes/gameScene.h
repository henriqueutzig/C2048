#include "gameLogic.h"
#include "UI.h"

#define MAX_STRING_SIZE 40
typedef struct GameScene
{
    ElementUI board;
    ElementUI movementBlock;
    ElementUI scoreBlock;
    ElementUI rankingBlock;
} GameScene;

typedef struct BoardUI
{
    Texture2D texture;
    Vector2 pos;
} BoardUI;

void drawMovementBlock(ElementUI movementBlockUI, int movement);
void drawScoreBlock(ElementUI scoreBlockUI, int score);
void drawRankingBlock(ElementUI rankingBlockUI, char names[][MAX_STRING_SIZE], int size);

void drawGameScene(int *screenState, GameScene *gameScene);

void gameSceneAction(GameScene *gameScene, int *screenState);
GameScene initGameScene(int w_w, int w_h);
void deInitGameScene(GameScene *gameScene);