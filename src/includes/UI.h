#include "raylib.h"

#ifndef UI
#define UI

typedef struct ElementUI
{
    Texture2D texture;
    Vector2 pos;
    Color color;
    int fontSize;
} ElementUI;

ElementUI initElementTextUI(Texture2D texture, Vector2 pos, Color color, int fontSize);
ElementUI initElementUI(Texture2D texture, Vector2 pos);
void drawElementUI(ElementUI elementUI);
void deinitElementUI(ElementUI *elementUI);

Rectangle getRectSpriteFromMatrix(int value, int column, int row, int width, int height);
Rectangle getRectSpriteFromArray(int value, int width, int height);
#endif