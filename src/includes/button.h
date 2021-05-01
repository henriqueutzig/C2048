/**
 ******************************************************************************
 * @file    button.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Library for a simple UI button.
 ******************************************************************************
 */

#ifndef _Button
#define _Button

/* Includes ------------------------------------------------------------------*/

#include "raylib.h"

/* Exported types ------------------------------------------------------------*/

/**
 *  @struct Button
 *  @brief Struct of a basic UI button with states.
 */
typedef struct Button
{
    int numFrames;
    int frameHeight;
    int state;
    Rectangle bounds;
    Rectangle recSrc;
    Sound clickSound;
    Texture2D texture;
} Button;

/**
 *  @enum ButtonState
 *  @brief Possible states of a button.
 */
typedef enum ButtonState
{
    NORMAL,
    MOUSE_HOVER,
    PRESSED
} ButtonState;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn initButton
 * @brief Initializes a Button struct.
 * @param texture: Texture2D struct with the sprites of the button.
 * @param numFrames: number of vertical frames on the sprite (max of 3, one for each state).
 * @param sound: Sound struct for the click sound.
 * @param position: Vector2 struct with the coordinates of the button in screen.
 * @return Button struct initialized.
 */
Button initButton(Texture texture, int numFrames, Sound sound, Vector2 position);

/**
 * @fn updateButtonState
 * @brief Updates the button state and indicates wether the button was pressed or not.
 * @param button: poiter to the desired Button struct.
 * @return TRUE if button was pressed.
 */
bool updateButtonState(Button *button);

/**
 * @fn drawButton
 * @brief Draws the desired button on screen.
 * @param button: Button struct to draw.
 */
void drawButton(Button button);

/**
 * @fn deInitButton
 * @brief De-initializes all elements used in the desired button.
 * @param button: pointer to a Button struct to de-initialize.
 */
void deInitButton(Button *button);

#endif