#pragma once
#include <graphics.h>
#include <vector>

#include "Point.h"
using namespace std;
class Chess : public Point
{
private:
    int board[19][19];
    vector<pair<int, int>> stk; // ���ڴ洢����������
    int top, left, board_size; // ���̵ı߽�(���ײ���)�����̴�С
    double chess_size;
    int turn;           // ��¼��������
    int win;            // 1Ϊ��ʤ��-1Ϊƽ
    IMAGE black, white; // ���ӵ�ͼƬ
public:
    void init();
    void set_information(int board_size, int top, int left, double chess_size);
    int boardsize();                                      // �������̴�С
    int getColor(int x, int y);                           // ����������ɫ
    void chessDown(int x, int y, int color, bool sound);  // ����
    bool isvaild(int x, int y, int *down_x, int *down_y); // �ж��Ƿ��������
    void withdraw(int mode);
    void change_turn();
    int get_turn();
    int menu();
    void record();
    void load_game();
    void delete_chess();      // ɾ������
    bool gameover(int color); // ���ؽ��
    void set_win(int winner); // ����ʤ����
    int get_win();
    void load_map();
    ~Chess();
};
