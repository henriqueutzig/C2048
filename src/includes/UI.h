#include "raylib.h"

typedef struct ElementUI
{
    Texture2D texture;
    Vector2 pos;
    Color color;
    int fontSize;
} ElementUI;

ElementUI initElementTextUI(Texture2D texture, Vector2 pos, Color color, int fontSize);
ElementUI initElementUI(Texture2D texture, Vector2 pos);
void deinitElementUI(ElementUI *elementUI);