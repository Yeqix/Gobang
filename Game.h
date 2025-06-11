#pragma once
#include "Man.h"
#include "AI.h"
#include "Chess.h"

class Game
{
private:
    Man *man, *man2;
    AI *ai;
    Chess *chess;
    pair<int, int> mode;
    IMAGE Return;

public:
    Game(Man *man, AI *ai, Chess *chess, Man *man2);
    ~Game();
    void init();
    void startGame();
    void chose_mode();
    void chose_board();
    void chose_color();
    void show_winner();
    bool end_game();
};