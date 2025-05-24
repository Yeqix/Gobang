#include "Game.h"
#include "AI.h"
#include <windows.h>
#include<iostream>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

Game::Game(Man* man, AI* ai, Chess* chess, Man* man2)
{
	this->man = man;
	this->ai = ai;
	this->chess = chess;
	this->man2 = man2;
}
void Game::startGame()
{
	initgraph(897, 895);
	mode = chose_mode();
	if (mode) {//人机
	     chose_color();//选择颜色
	}
	else {
		man->init(chess, 1);
		man2->init(chess, 0);
	}
	chess->init();//初始化棋盘，棋子
	int turn = 1;//1代表黑方，0代表白方
	while (1)
	{
		if (man->get_color() == turn) {
			man->go();
		}
		else {
			if (mode == 1) {
				ai->go();
			}
			else {
				man2->go();
			}
		}
		if (chess->gameover(turn)) {
			break;
		}
		turn ^= 1;
	}
	show_winner();
	return;
}
int Game::chose_mode()
{
	IMAGE img;
	loadimage(&img, _T("res/选模式.jpg"), 897, 895);
	putimage(0, 0, &img);
	MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {//鼠标左键按下
			std::cout << msg.x << " " << msg.y << '\n';
			mciSendString("play res/点击音效.mp3", 0, 0, 0);
			if (msg.x >= 56 && msg.x <= 395 && msg.y >= 740 && msg.y <= 846) {
				return 1;//人机
			}
			else if (msg.x >= 506 && msg.x <= 847 && msg.y >= 740 && msg.y <= 846) {
				return 0;//人人
			}
		}
	}
	cleardevice();//清屏
}
void Game::chose_color()
{
	loadimage(0, "res/选黑白.jpg");
	MOUSEMSG msg;
	int x, y;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {//鼠标左键按下
			mciSendString("play res/点击音效.mp3", 0, 0, 0);
			if (msg.x >= 210 && msg.x <= 416 && msg.y >= 384 && msg.y <= 523) {//选黑
				man->init(chess, 1);
				ai->init(chess, 0);
				break;
			}
			else if (msg.x >= 482 && msg.x <= 689 && msg.y >= 384 && msg.y <= 523) {//选白
				ai->init(chess, 1);
				man->init(chess, 0);
				break;
			}
		}
	}
	Sleep(300);//显示点击音效（bushi
	cleardevice();//清屏
}



void Game::show_winner()
{
	Sleep(1000);
	if (chess->get_win() == 1) {
		IMAGE img;
		loadimage(&img, _T("res/黑胜.png"), 897, 895);
		putimage(0, 0, &img);
	}
	else if (chess->get_win() == 0) {
		IMAGE img;
		loadimage(&img, _T("res/白胜.png"), 897, 895);
		putimage(0, 0, &img);
	}
	else if (chess->get_win() == -1) {
		IMAGE img;
		loadimage(&img, _T("res/平局.png"), 897, 895);
		putimage(0, 0, &img);
	}
	Sleep(1000);
	return;
}

