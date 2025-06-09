#include <conio.h>
#include <graphics.h>
#include <mmsystem.h>
#include <iostream>
#include "AI.h"
#include "Chess.h"
#include "Game.h"
#include "Man.h"
#pragma comment(lib, "winmm.lib")
using namespace std;
signed main() {
    initgraph(897, 895);
    Chess chess;
    Man man, man2;
    AI ai;
    Game game(&man, &ai, &chess, &man2);
    while (1) {
        game.startGame();
        if (game.end_game()) {
            break;
        }
    }
    return 0;
}