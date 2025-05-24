#pragma once
#include<graphics.h>
#include"Point.h"
class Chess :public Point
{
    int board[19][19];
	int top, left, board_size;// ���̵ı߽�(���ײ���)�����̴�С
	double chess_size;
	bool is_black;// �Ƿ��ǵ���
	int win;//1Ϊ��ʤ��-1Ϊƽ
    IMAGE black, white;// ���ӵ�ͼƬ
public:
	void init();
    void set_information(int board_size,int top, int left, double chess_size);
	void chessDown(int x, int y, int color);// ����
	bool isvaild(int x, int y, int* down_x, int* down_y);// �ж��Ƿ��������
	int boardsize();// �������̴�С
	int getColor(int x, int y);// ����������ɫ
	bool gameover(int color);// ���ؽ��
	void set_win(int winner);// ����ʤ����
    int get_win();
};

