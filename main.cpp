#include <conio.h>
#include <graphics.h>
#include <iostream>
#include "AI.h"
#include "Chess.h"
#include "Game.h"
#include "Man.h"
using namespace std;
int main()
{
    initgraph(897, 895);
    Chess chess;
    Man man, man2;
    AI ai;
    Game game(&man, &ai, &chess, &man2);
    while (1)
    {
        game.startGame();
        if (game.end_game())
        {
            break;
        }
    }
    return 0;
}