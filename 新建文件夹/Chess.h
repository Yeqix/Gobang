#pragma once
#include<graphics.h>
#include"Point.h"
class Chess :public Point
{
    int board[19][19];
    int top, left;// ���̵ı߽�(���ײ���)
	int chess_size ,board_size;
	bool is_black;// �Ƿ��ǵ���
	int win;//1Ϊ��ʤ��-1Ϊƽ
    IMAGE black, white;// ���ӵ�ͼƬ
public:
    Chess(int board_size,int top, int left, int chess_size);
	void init();
	void chessDown(int x, int y, int color);// ����
	bool isvaild(int x, int y, int* down_x, int* down_y);// �ж��Ƿ��������
	int boardsize();// �������̴�С
	int getColor(int x, int y);// ����������ɫ
	bool gameover(int color);// ���ؽ��
	void set_win(int winner);// ����ʤ����
    int get_win();
};

