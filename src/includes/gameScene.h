#include "UI.h"
#include "gameLogic.h"
#include "button.h"

#define MAX_STRING_SIZE 31

#define NAME_SPACING 18
#define MEDAL_X_OFFSET 150
#define NAME_Y_OFFSET 32

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
void drawRankingBlock(ElementUI rankingBlockUI, ElementUI medal, char names[][MAX_STRING_SIZE], int size, int nameSpacing, int medalXOffset, int yOffset);

void drawGameScene(GameScene gameScene, GameState gameState, char highScores[][MAX_STRING_SIZE], int nHS);

void gameSceneAction(GameScene *gameScene, int *screenState, GameState *gameState);
GameScene initGameScene();
void deInitGameScene(GameScene *gameScene);