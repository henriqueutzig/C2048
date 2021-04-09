#ifndef _Button
#define _Button

#include "raylib.h"
typedef struct Button
{
    int numFrames;
    int frameHeight;
    int state;
    Rectangle bounds;
    Rectangle recSrc;
    Vector2 mousePoint;
    Sound clickSound;
    Texture2D texture;
} Button;

enum ButtonState
{
    NORMAL,
    MOUSE_HOVER,
    PRESSED
};

Button initButton(Texture texture, int numFrames, Sound sound, Vector2 position);
bool buttonState(Button *button);
void drawButton(Button button);
void deInitButton(Button *button);

#endif