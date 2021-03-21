#define WINDOW_DW 1280
#define WINDOW_DH 720

typedef struct Window
{
    int width;
    int height;
    int screenState;
    char name[6];
    bool darkMode;
} Window;

enum screenState {
    mainMenu,
    game,
    highScore,
    credits,
    quit
};