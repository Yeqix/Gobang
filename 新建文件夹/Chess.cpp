#include "Chess.h"
#include <graphics.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <math.h>
using namespace std;
void putimagePNG(int x, int y, IMAGE* picture) //ȥ��������Χ�ڱ�
{
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}
void Chess::init() {
	
	mciSendString("play res/start.wav", 0, 0, 0);
	loadimage(&black, "res/black.png", chess_size, chess_size, 1);
	loadimage(&white, "res/white.png", chess_size, chess_size, 1);
	for (int i = 0; i < board_size; i++)//�������
	{
		for (int j = 0; j < board_size; j++)
		{
			board[i][j] = -1;
		}
	}
	is_black = true;
}

void Chess::set_information(int board_size, int top, int left, double chess_size)
{
	this->board_size = board_size;
	this->top = top;
	this->left = left;
	this->chess_size = chess_size;
	is_black = true;
}

void Chess::chessDown(int x, int y, int color)
{
	board[x][y] = color;
	int down_x = top + chess_size * x - 0.5 * chess_size;
	int down_y = left + chess_size * y - 0.5 * chess_size;
	if (color == 1) {
		putimagePNG(down_x, down_y, &black);
	}
	else{
		putimagePNG(down_x, down_y, &white);
	}
	mciSendString("play res/������.mp3", 0, 0, 0);
}

bool Chess::isvaild(int x, int y, int *down_x, int *down_y)
{
	if (x > 0 && y > 0 && x <= top + (board_size) * chess_size && y <= left + (board_size ) * chess_size)//�ж��Ƿ���������
	{
		int x1 = (x - top) / chess_size;
		int y1 = (y - left) / chess_size;
		if (x1 * chess_size + chess_size/2+top < x) {
			*down_x = x1 + 1;
		}
		else {
			*down_x = x1;
		}
		if (y1 * chess_size + chess_size/2 +left< y) {
			*down_y = y1 + 1;
		}
		else {
			*down_y = y1;
		}
		if (board[*down_x][*down_y] == -1) {
			return true;
		}
		else {
			return false; 
		}
		
	}
	return false;
}

int Chess::boardsize()
{
	return board_size;
}
int Chess::getColor(int x, int y)
{
	return board[x][y];
}
int dxx[4] = { 0,1,1,1 };
int dyy[4] = { 1,0,1,-1 };
bool Chess::gameover(int color)
{
	bool _continue = 0;//�Ƿ���λ����
	for(int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (board[i][j] == -1) {
				_continue = 1;
			}
			if (board[i][j] == color) {
				for (int k = 0; k < 4; k++) {
					int cnt = 1;
					for(int l = 1; l < 5; l++)
					{
						int x = i + dxx[k] * l;
						int y = j + dyy[k] * l;
						if (x >= 0 && x < board_size && y >= 0 && y < board_size) {
							if (board[x][y] == color) {
								cnt++;
							}
						}
					}
					if (cnt >= 5) {
						
						set_win(color);
						return true;
					}
				}
			}
		}
	}
	if (_continue==0) {
		set_win(-1);
		return true; 
	}
	return false;
}

void Chess::set_win(int winner)
{
	win = winner;
}

int Chess::get_win()
{
	return win;
}

