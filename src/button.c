#include "includes/button.h"

Button initButton(Texture texture, int numFrames, Sound sound, Vector2 position)
{
    Button button;

    button.numFrames = numFrames;
    button.texture = texture;
    button.clickSound = sound;
    button.frameHeight = button.texture.height / numFrames;
    button.recSrc = (Rectangle){0, 0, texture.width, button.frameHeight};
    button.bounds = (Rectangle){position.x, position.y, texture.width, button.frameHeight};
    button.state = NORMAL;

    return button;
}

bool buttonState(Button *button)
{
    button->mousePoint = GetMousePosition();

    if (CheckCollisionPointRec(button->mousePoint, button->bounds))
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            button->state = PRESSED;
        }
        else
        {
            button->state = MOUSE_HOVER;
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            button->recSrc.y = button->state * button->frameHeight;
            PlaySound(button->clickSound);
            return true;
        }
    }
    else
    {
        button->state = NORMAL;
    }

    button->recSrc.y = button->state * button->frameHeight;

    return false;
}

void drawButton(Button *button)
{
    DrawTextureRec(button->texture, button->recSrc, (Vector2){button->bounds.x, button->bounds.y}, WHITE);
}

void deInitButton(Button *button)
{
    UnloadTexture(button->texture);
    UnloadSound(button->clickSound);
}