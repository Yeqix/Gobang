#pragma once
#include<graphics.h>
#include"Point.h"
class Chess :public Point
{
    int board[19][19];
	int top, left, board_size;// 棋盘的边界(留白部分)，棋盘大小
	double chess_size;
	bool is_black;// 是否是到黑
	int win;//1为黑胜，-1为平
    IMAGE black, white;// 棋子的图片
public:
	void init();
    void set_information(int board_size,int top, int left, double chess_size);
	void chessDown(int x, int y, int color);// 下棋
	bool isvaild(int x, int y, int* down_x, int* down_y);// 判断是否可以下棋
	int boardsize();// 返回棋盘大小
	int getColor(int x, int y);// 返回棋子颜色
	bool gameover(int color);// 返回结果
	void set_win(int winner);// 设置胜利者
    int get_win();
};

