 #include <graphics.h>
 #include <conio.h>
 #include <iostream>
 #include "Man.h"
 #include "AI.h"
 #include "Chess.h"
 #include "Game.h"
using namespace std;
signed main() {
	Chess chess(13, 44, 44, 67);//几路棋盘，左，右侧边框宽度，每个格子宽度
     Man man ;
     AI ai ;
     Game game(&man,&ai,&chess) ;
     game.startGame() ;
    return 0;
}