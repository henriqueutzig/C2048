#include "UI.h"
#include "gameLogic.h"
#include "button.h"
#include "raygui.h"
#include "window.h"
#include "ranking.h"

#define MAX_STRING_SIZE 31
#define MAX_FILE_NAME_SIZE 256

#define NAME_SPACING 18
#define MEDAL_X_OFFSET 150
#define NAME_Y_OFFSET 32
#define SCORE_X_OFFSET 90

#define MARGIN_CARD 16

#define MEDAL_SIZE_W 12
#define MEDAL_SIZE_H 15

#define WIN_MESSAGE "YOU WON"
#define GAME_OVER_MESSAGE "GAME OVER"

enum MedalNumber
{
    GOLD_MEDAL,
    SILVER_MEDAL,
    BRONZE_MEDAL
};

enum DialogButton
{
    YES = 1,
    NO
};

typedef struct DialogState
{
    int buttonPressed;
    bool isActive;
} DialogState;

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
    DialogState newGameDialog;
    DialogState saveGameDialog;
    DialogState quitGameDialog;
    DialogState endGameDialog;
    char saveFileName[MAX_FILE_NAME_SIZE];
    char rankingName[NAME_SIZE];
    int gameSituation;
} GameScene;

void drawBoardCards(GameState gameState, ElementUI board);
void drawMovementBlock(ElementUI movementBlockUI, int movement);
void drawScoreBlock(ElementUI scoreBlockUI, int score);
void drawRankingBlock(ElementUI rankingBlockUI, ElementUI medal, Ranker rank[N_MAX_RANKERS], int nHS);

void drawGameScene(GameScene *gameScene, GameState gameState, Ranker rank[N_MAX_RANKERS], int nHS);

void gameSceneAction(GameScene *gameScene, int *screenState, GameState *gameState, Card *gameBoard, Ranker *rank);
GameScene initGameScene();
DialogState initDialogState();
void deInitGameScene(GameScene *gameScene);