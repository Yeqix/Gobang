#include <graphics.h>
#include <conio.h>
#ifndef GAME_H
#define GAME_H
class Game
{
public:
    Game();
    int winer;
    void startGame();
    bool exam();

private:
    int x;
    int y;
    MOUSEMSG msg;
};
#endif // !GAME_H
