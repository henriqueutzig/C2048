/**
 ******************************************************************************
 * @file    assets.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Definition of all assets paths used and colors.
 ******************************************************************************
 */

#ifndef _Assets
#define _Assets

/* Root directories ------------------------------------------------------------*/
#define TEXTURES_PATH "src/resources/textures/"
#define SOUNDS_PATH "src/resources/audio/"
#define STYLES_PATH "styles/"

/* Game Scene ------------------------------------------------------------------*/
#define BOARD_BG TEXTURES_PATH "board.png"
#define RANKING_BLOCK TEXTURES_PATH "rankingBlock.png"
#define SCORE_BLOCK TEXTURES_PATH "scoreBlock.png"
#define MOVEMENT_BLOCK TEXTURES_PATH "movementBlock.png"
#define CARDS TEXTURES_PATH "cards.png"
#define KEYS TEXTURES_PATH "keys.png"
#define QUIT_KEY TEXTURES_PATH "quit.png"
#define SAVE_KEY TEXTURES_PATH "save.png"
#define NEW_GAME_KEY TEXTURES_PATH "new_game.png"
#define MOVEMENTS_KEY TEXTURES_PATH "movements.png"
#define MEDAL_SMALL TEXTURES_PATH "medalsSmall.png"

/* Main Menu Scene -------------------------------------------------------------*/
#define GAME_LOGO TEXTURES_PATH "logo.png"
#define BT_LOADGAME TEXTURES_PATH "btLoadGame.png"
#define BT_NEWGAME TEXTURES_PATH "btNewGame.png"
#define BT_HIGHSCORES TEXTURES_PATH "btHighScores.png"
#define BT_CREDITS TEXTURES_PATH "btCredits.png"
#define BT_QUIT TEXTURES_PATH "btQuit.png"

/* Credits Scene ---------------------------------------------------------------*/
#define BT_BACK TEXTURES_PATH "back-arrow2.png"
#define GITHUB_ICON TEXTURES_PATH "github-icon.png"
#define DRACULA_ICON TEXTURES_PATH "dracula-icon.png"
#define RAYLIB_ICON TEXTURES_PATH "raylib-icon.png"

/* Ranking Scene ---------------------------------------------------------------*/
#define LEADERBOARD TEXTURES_PATH "leaderboard.png"

/* Button Sound ----------------------------------------------------------------*/
#define BT_SOUND SOUNDS_PATH "buttonfx.wav"

/* Colors and Styles -----------------------------------------------------------*/
#define BACKGROUND_COLOR \
    (Color) { 40, 42, 54, 255 }
#define DRACULA_YELLOW \
    (Color) { 241, 250, 140, 255 }
#define DRACULA_STYLE STYLES_PATH "dracula.rgs"

#endif