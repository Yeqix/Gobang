#include <conio.h>
#include <graphics.h>
#include "Game.h"
#include "UI.h"
using namespace std;

int main() {
    
    initgraph(800, 600);  // �����������ص�
    Game game;
    // game.loadImage();
    game.startGame();
    game.UI();
    system("pause");  // ֹͣ����ִ�У���ֹ���ڱ���
    return 0;
}