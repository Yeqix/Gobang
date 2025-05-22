#include <conio.h>
#include <graphics.h>
#include "Game.h"
using namespace std;

int main() {
    initgraph(800, 600);  // 创建窗口像素点
    Game game;
    // game.loadImage();
    game.startGame();
    system("pause");  // 停止命令执行，防止窗口被关
    return 0;
}