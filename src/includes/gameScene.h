#include "UI.h"
#include "gameLogic.h"
#include "button.h"

#define MAX_STRING_SIZE 40

#define MARGIN_CARD 16

#define MEDAL_SIZE_W 12
#define MEDAL_SIZE_H 15

enum MedalNumber
{
    GOLD_MEDAL,
    SILVER_MEDAL,
    BRONZE_MEDAL
};

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
} GameScene;

void drawBoardCards(GameState gameState, ElementUI board);
void drawMovementBlock(ElementUI movementBlockUI, int movement);
void drawScoreBlock(ElementUI scoreBlockUI, int score);
void drawRankingBlock(ElementUI rankingBlockUI, ElementUI medal, char names[][MAX_STRING_SIZE], int size);

void drawGameScene(GameScene gameScene, GameState gameState);

void gameSceneAction(GameScene *gameScene, int *screenState, GameState *gameState);
GameScene initGameScene();
void deInitGameScene(GameScene *gameScene);