#include "Man.h"
#include <graphics.h>
#include<iostream>
void Man::init(Chess * chess,int color,int mode) {
	this->color = color;
	this->chess = chess;
	this->mode = mode;
}
void Man::go() {
	MOUSEMSG msg;
	int x,y;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {//Êó±ê×ó¼ü°´ÏÂ
			if (chess->isvaild(msg.x, msg.y, & x, & y)) {
				chess->chessDown(x, y, color, 1);
				return;
			}
			else if (msg.y>897 && msg.x<115) {
				chess->withdraw(mode);
				return;
			}
		}
	}
	
}

int Man::get_color()
{
	return color;
}
