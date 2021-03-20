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