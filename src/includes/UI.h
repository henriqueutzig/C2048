/**
 ******************************************************************************
 * @file    UI.h
 * @author  Henrique Utzig and Pedro Klein
 * @version V1.0
 * @date    30-April-2021
 * @brief   Library for a simple UI element.
 ******************************************************************************
 */

#ifndef _UI
#define _UI

/* Includes ------------------------------------------------------------------*/

#include "raylib.h"

/* Exported types ------------------------------------------------------------*/

/**
 *  @struct ElementUI
 *  @brief Struct of all data needed for a simple element on the UI.
 */
typedef struct ElementUI
{
    Texture2D texture;
    Vector2 pos;
    Color color;
    int fontSize;
} ElementUI;

/* Exported functions ------------------------------------------------------- */

/**
 * @fn initElementTextUI
 * @brief Initializes a ElementUI struct with text.
 * @param texture: Texture2D struct with the sprites of the element.
 * @param pos: Vector2 struct with the coordinates of the element in screen.
 * @param color: Color struct with the color of the text.
 * @param fontSize: font size of the text.
 * @return ElementUI struct with text initialized.
 */
ElementUI initElementTextUI(Texture2D texture, Vector2 pos, Color color, int fontSize);

/**
 * @fn initElementUI
 * @brief Initializes a ElementUI struct without text.
 * @param texture: Texture2D struct with the sprites of the element.
 * @param pos: Vector2 struct with the coordinates of the element in screen.
 * @return ElementUI struct without text initialized.
 */
ElementUI initElementUI(Texture2D texture, Vector2 pos);

/**
 * @fn drawElementUI
 * @brief Draws the desired element ui on screen.
 * @param elementUI: ElementUI struct to draw.
 */
void drawElementUI(ElementUI elementUI);

/**
 * @fn deinitElementUI
 * @brief De-initializes all elements used in the desired elementUI.
 * @param elementUI: pointer to a ElementUI struct to de-initialize.
 */
void deinitElementUI(ElementUI *elementUI);

/**
 * @fn getRectFrameFromMatrix
 * @brief Get a rectangle frame from a matrix of frames of a sprite.
 * @param value: one dimensional representation of a frame in the sprite.
 * @param column: number of columns in the matrix.
 * @param row: number of rows in the matrix.
 * @param width: width of a frame in the matrix.
 * @param height: height of a frame in the matrix.
 * @return Rectangle struct that represents the cuted frame of the matrix.
 */
Rectangle getRectFrameFromMatrix(int value, int column, int row, int width, int height);

/**
 * @fn getRectFrameFromArray
 * @brief Get a rectangle frame from a array of frames of a sprite.
 * @param value: one dimensional representation of a frame in the sprite.
 * @param width: width of a frame in the array.
 * @param height: height of a frame in the array.
 * @return Rectangle struct that represents the cuted frame of the array.
 */
Rectangle getRectFrameFromArray(int value, int width, int height);
#endif