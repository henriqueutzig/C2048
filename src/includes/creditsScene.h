/**
 ******************************************************************************
 * @file    creditsScene.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Structs and functions needed for the credits scene
 ******************************************************************************
 */

#ifndef _Credits
#define _Credits

/* Includes ------------------------------------------------------------------*/

#include <string.h>
#include "button.h"
#include "window.h"

/* Exported constants --------------------------------------------------------*/

#define TEXT_MAX 280
#define DEFAULT_TEXT "C2048 was made by Henrique Utzig and Pedro \nAfonso Klein as the final project for INF01202\nAlgorithms and Programming class at UFRGS"

#define URL_GIT_GAME "https://github.com/henriqueutzig/C2048"
#define URL_COLOR_PALLET "https://draculatheme.com/"
#define URL_RAYLIB "https://www.raylib.com/"

/* Exported types ------------------------------------------------------------*/

/**
 *  @struct CreditsScene
 *  @brief Struct of all data needed in the credits scene.
 */
typedef struct CreditsScene
{
    char text[TEXT_MAX];
    Button btMainMenu;
    Button btGitPage;
    Button btColorPallet;
    Button btRaylib;
} CreditsScene;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn drawCreditsScene
 * @brief Draws all elements of the credit scene in screen.
 * @param creditsScene: CreditsScene struct to draw.
 */
void drawCreditsScene(CreditsScene creditsScene);

/**
 * @fn creditsSceneAction
 * @brief Executes all credit scene logic.
 * @param creditsScene: pointer to a CreditsScene struct.
 * @param screenState: pointer to the current screen state.
 */
void creditsSceneAction(CreditsScene *creditsScene, ScreenState *screenState);

/**
 * @fn initCreditsScene
 * @brief Initiaizes all elements whithin a CreditScene struct.
 * @return CreditScene struct initialized.
 */
CreditsScene initCreditsScene();

/**
 * @fn deInitCreditsScene
 * @brief De-initializes all elements used in the credit scene.
 * @param creditsScene: pointer to a CreditsScene struct to de-initialize.
 */
void deInitCreditsScene(CreditsScene *creditsScene);

#endif