#include "includes/UI.h"

ElementUI initElementTextUI(Texture2D texture, Vector2 pos, Color color, int fontSize)
{
    return (ElementUI){texture = texture, pos = pos, color = color, fontSize = fontSize};
}
ElementUI initElementUI(Texture2D texture, Vector2 pos)
{
    return (ElementUI){texture = texture, pos = pos};
}

void drawElementUI(ElementUI elementUI)
{
    DrawTexture(elementUI.texture, elementUI.pos.x, elementUI.pos.y, WHITE);
}

void deinitElementUI(ElementUI *elementUI)
{
    UnloadTexture(elementUI->texture);
}

Rectangle getRectFrameFromMatrix(int value, int column, int row, int width, int height)
{
    int count = 0;

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (count == value)
            {
                return (Rectangle){j * width, i * height, width, height};
            }
            count++;
        }
    }
    return (Rectangle){0, 0, width, height};
}

Rectangle getRectFrameFromArray(int value, int width, int height)
{
    return (Rectangle){0, value * height, width, height};
}