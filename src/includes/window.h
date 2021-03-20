typedef struct Window
{
    int width;
    int height;
    int screenState;
    char name[5];
    bool darkMode;
} Window;

enum screenState {
    mainMenu,
    game,
    credits
};