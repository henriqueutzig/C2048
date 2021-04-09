#include "includes/creditsScene.h"
#include "includes/assets.h"
#include "includes/window.h"

void drawCreditsScene(CreditsScene creditsScene)
{
    BeginDrawing();

    ClearBackground(BACKGROUND_COLOR);

    DrawText(creditsScene.text, 105, 90, 20, DRACULA_YELLOW);

    drawButton(creditsScene.btGitPage);
    drawButton(creditsScene.btColorPallet);
    drawButton(creditsScene.btRaylib);

    drawButton(creditsScene.btMainMenu);

    EndDrawing();
}

void creditsSceneAction(CreditsScene *creditsScene, int *screenState)
{
    if (buttonState(&(creditsScene->btMainMenu)))
        *screenState = mainMenu;
    if (buttonState(&(creditsScene->btColorPallet)))
        OpenURL(URL_COLOR_PALLET);
    if (buttonState(&(creditsScene->btGitPage)))
        OpenURL(URL_GIT_GAME);
    if (buttonState(&(creditsScene->btRaylib)))
        OpenURL(URL_RAYLIB);
}

CreditsScene initCreditsScene()
{
    CreditsScene credits;
    strcpy(credits.text, DEFAULT_TEXT);
    credits.btColorPallet = initButton(LoadTexture(DRACULA_ICON), 1, LoadSound(BT_SOUND),
                                       (Vector2){144, 247});
    credits.btRaylib = initButton(LoadTexture(RAYLIB_ICON), 1, LoadSound(BT_SOUND),
                                    (Vector2){273, 247});
    credits.btGitPage = initButton(LoadTexture(GITHUB_ICON), 1, LoadSound(BT_SOUND),
                                   (Vector2){402, 247});

    credits.btMainMenu = initButton(LoadTexture(BT_BACK), 1, LoadSound(BT_SOUND),
                                    (Vector2){20, 20});

    return credits;
}

void deInitCreditsScene(CreditsScene *creditsScene)
{
    deInitButton(&(creditsScene->btColorPallet));
    deInitButton(&(creditsScene->btGitPage));
    deInitButton(&(creditsScene->btRaylib));
    deInitButton(&(creditsScene->btMainMenu));
}