#include <conio.h>
#include <graphics.h>
#include "Board.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H
class Game {
public:
    Game();
    Player playerone, playertwo;  // һ����Ϸ���������
    Board* p;
    int winer;                // ��ֵ���ж�˭ΪӮ��
    void loadImage();         // ����ͼ��
    void startGame();         // ��ʼ��Ϸ����
    bool exam(Board* board);  // �ж��Ƿ�����ʤ��
    int Game_();
    void UI();

protected:
    int x;
    int y;
    MOUSEMSG msg;
};
#endif
