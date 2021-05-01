/**
 ******************************************************************************
 * @file    menuScene.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Structs and functions needed for the main menu scene
 ******************************************************************************
 */

#ifndef _MenuScene
#define _MenuScene

/* Includes ------------------------------------------------------------------*/

#include "fileDialog.h"
#include "button.h"
#include "assets.h"
#include "gameLogic.h"
#include "UI.h"
#include "window.h"

/* Exported types ------------------------------------------------------------*/

/**
 *  @struct MenuScene
 *  @brief Struct of all data needed in the main menu scene.
 */
typedef struct MenuScene
{
    ElementUI logo;
    Button btLoadGame;
    Button btNewGame;
    Button btCredits;
    Button btHighScores;
    Button btQuit;
    GuiFileDialogState fileDialogState;
} MenuScene;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn drawMainMenu
 * @brief Draws all elements of the main menu scene in screen.
 * @param mainMenu: MenuScene struct to draw.
 */
void drawMainMenu(MenuScene *mainMenu);

/**
 * @fn mainMenuBtAction
 * @brief Executes all main menu scene logic.
 * @param menuScreen: pointer to a MenuScene struct.
 * @param screenState: pointer to a current screen state.
 * @param gameBoard: pointer to a Card matrix with the current board.
 * @param gameState: pointer to a GameState struct of the current game.
 */
void mainMenuBtAction(MenuScene *menuScreen, ScreenState *screenState, Card *gameBoard, GameState *gameState);

/**
 * @fn initMainMenu
 * @brief Initiaizes all elements whithin a MenuScene struct.
 * @return MenuScene struct initialized.
 */
MenuScene initMainMenu();

/**
 * @fn deInitMainMenu
 * @brief De-initializes all elements used in the main menu scene.
 * @param mainMenu: pointer to a MenuScene struct to de-initialize
 */
void deInitMainMenu(MenuScene *mainMenu);
#endif