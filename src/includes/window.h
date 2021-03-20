#define WINDOW_DW 800
#define WINDOW_DH 450

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
    credits
};