#include "includes/button.h"
#include "includes/raylib.h"

Button initButton(Texture texture, int numFrames, Sound sound, Window window)
{
    Button button;

    button.numFrames = numFrames;
    button.texture = texture;
    button.clickSound = sound;
    button.frameHeight = button.texture.height / numFrames;
    button.position = (Rectangle){0, 0, texture.width, button.frameHeight};
    button.bounds = (Rectangle){window.width / 2 - texture.width / 2, window.height / 2 - texture.height / numFrames / 2, texture.width, button.frameHeight};
    button.state = NORMAL;
    button.action = false;

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
            button->position.y = button->state * button->frameHeight;
            PlaySound(button->clickSound);
            return true;
        }
    }
    else
    {
        button->state = NORMAL;
    }

    button->position.y = button->state * button->frameHeight;

    return false;
}

void drawButton(Button button)
{
    DrawTextureRec(button.texture, button.position, (Vector2){button.bounds.x, button.bounds.y}, WHITE);
}

void deInitButton(Button button)
{
    UnloadTexture(button.texture);
    UnloadSound(button.clickSound);
}