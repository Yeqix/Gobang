#pragma once
#include <graphics.h>
#include <stack>

#include "Point.h"
using namespace std;
class Chess : public Point {
    int board[19][19];
    stack<pair<int, int>> stk;  // ���ڴ洢����������
    int top, left, board_size;  // ���̵ı߽�(���ײ���)�����̴�С
    double chess_size;
    bool if_back;//�Ƿ񷵻�
    int turn;            
    int win;             // 1Ϊ��ʤ��-1Ϊƽ
    IMAGE black, white;  // ���ӵ�ͼƬ
   public:
    void init();
    void set_information(int board_size, int top, int left, double chess_size);
    int boardsize();                                       // �������̴�С
    int getColor(int x, int y);                            // ����������ɫ
    bool isvaild(int x, int y, int* down_x, int* down_y);  // �ж��Ƿ��������
    void change_turn();
    int get_turn();
    void delete_chess();       // ɾ������
    void chessDown(int x, int y, int color, bool sound);   // ����
    void withdraw(int mode);
    bool gameover(int color);  // ���ؽ��
    void set_win(int winner);  // ����ʤ����
    int get_win();
    void load_map();
    void back();
    bool get_back();//�Ƿ񷵻�
};
