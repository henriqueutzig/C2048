#ifndef _Window
#define _Window

#define WINDOW_DW 680
#define WINDOW_DH 480

typedef struct Window
{
    int width;
    int height;
    int screenState;
    char name[6];
} Window;

enum screenState
{
    mainMenu,
    game,
    highScore,
    credits,
    quit
};

#endif