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

void creditsSceneAction(CreditsScene *creditsScene, ScreenState *screenState)
{
    if (updateButtonState(&(creditsScene->btMainMenu)))
        *screenState = MENU_SCENE;
    if (updateButtonState(&(creditsScene->btColorPallet)))
        OpenURL(URL_COLOR_PALLET);
    if (updateButtonState(&(creditsScene->btGitPage)))
        OpenURL(URL_GIT_GAME);
    if (updateButtonState(&(creditsScene->btRaylib)))
        OpenURL(URL_RAYLIB);
}

CreditsScene initCreditsScene()
{
    CreditsScene creditsScene;
    strcpy(creditsScene.text, DEFAULT_TEXT);
    creditsScene.btColorPallet = initButton(LoadTexture(DRACULA_ICON), 1, LoadSound(BT_SOUND),
                                       (Vector2){144, 247});
    creditsScene.btRaylib = initButton(LoadTexture(RAYLIB_ICON), 1, LoadSound(BT_SOUND),
                                    (Vector2){273, 247});
    creditsScene.btGitPage = initButton(LoadTexture(GITHUB_ICON), 1, LoadSound(BT_SOUND),
                                   (Vector2){402, 247});

    creditsScene.btMainMenu = initButton(LoadTexture(BT_BACK), 1, LoadSound(BT_SOUND),
                                    (Vector2){20, 20});

    return creditsScene;
}

void deInitCreditsScene(CreditsScene *creditsScene)
{
    deInitButton(&(creditsScene->btColorPallet));
    deInitButton(&(creditsScene->btGitPage));
    deInitButton(&(creditsScene->btRaylib));
    deInitButton(&(creditsScene->btMainMenu));
}