#include <graphics.h>
#include <conio.h>
#include "Board.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H
class Game
{
public:
    Game();
    Player playerone, playertwo;
    Board *boardH, *p, *q, *r;
    int winer;
    void loadImage();
    void startGame();
    bool exam(Board *board);
    int Game_();

protected:
    int x;
    int y;
    MOUSEMSG msg;
};
#endif // !GAME_H
