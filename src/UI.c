#include "includes/UI.h"

ElementUI initElementTextUI(Texture2D texture, Vector2 pos, Color color, int fontSize)
{
    return (ElementUI){texture = texture, pos = pos, color = color, fontSize = fontSize};
}
ElementUI initElementUI(Texture2D texture, Vector2 pos)
{
    return (ElementUI){texture = texture, pos = pos};
}

void deinitElementUI(ElementUI *elementUI)
{
    UnloadTexture(elementUI->texture);
}