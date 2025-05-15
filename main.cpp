#include <graphics.h>
#include <conio.h>
#include "Game.h"
using namespace std;

int main()
{
    initgraph(1080, 1080); // 创建窗口像素点
    Game game;
    // game.loadImage();
    game.startGame();
    system("pause");
    return 0;
}