/**
 ******************************************************************************
 * @file    window.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Types for a window and its states.
 ******************************************************************************
 */

#ifndef _Window
#define _Window

/* Exported constants --------------------------------------------------------*/

#define WINDOW_DW 680
#define WINDOW_DH 480

/* Exported types ------------------------------------------------------------*/

/**
 *  @enum screenState
 *  @brief Possible states of the screen.
 */
typedef enum ScreenState
{
    MENU_SCENE,
    GAME_SCENE,
    HIGH_SCORE_SCENE,
    CREDITS_SCENE,
    QUIT_GAME
} ScreenState;

typedef struct Window
{
    int width;
    int height;
    ScreenState screenState;
    char name[6];
} Window;

#endif