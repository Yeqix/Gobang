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
	if (mode) {//�˻�
	     chose_color();//ѡ����ɫ
	}
	else {
		man->init(chess, 1);
		man2->init(chess, 0);
	}
	chess->init();//��ʼ�����̣�����
	int turn = 1;//1����ڷ���0����׷�
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
	loadimage(&img, _T("res/ѡģʽ.jpg"), 897, 895);
	putimage(0, 0, &img);
	MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {//����������
			std::cout << msg.x << " " << msg.y << '\n';
			mciSendString("play res/�����Ч.mp3", 0, 0, 0);
			if (msg.x >= 56 && msg.x <= 395 && msg.y >= 740 && msg.y <= 846) {
				return 1;//�˻�
			}
			else if (msg.x >= 506 && msg.x <= 847 && msg.y >= 740 && msg.y <= 846) {
				return 0;//����
			}
		}
	}
	cleardevice();//����
}
void Game::chose_color()
{
	loadimage(0, "res/ѡ�ڰ�.jpg");
	MOUSEMSG msg;
	int x, y;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {//����������
			mciSendString("play res/�����Ч.mp3", 0, 0, 0);
			if (msg.x >= 210 && msg.x <= 416 && msg.y >= 384 && msg.y <= 523) {//ѡ��
				man->init(chess, 1);
				ai->init(chess, 0);
				break;
			}
			else if (msg.x >= 482 && msg.x <= 689 && msg.y >= 384 && msg.y <= 523) {//ѡ��
				ai->init(chess, 1);
				man->init(chess, 0);
				break;
			}
		}
	}
	Sleep(300);//��ʾ�����Ч��bushi
	cleardevice();//����
}



void Game::show_winner()
{
	Sleep(1000);
	if (chess->get_win() == 1) {
		IMAGE img;
		loadimage(&img, _T("res/��ʤ.png"), 897, 895);
		putimage(0, 0, &img);
	}
	else if (chess->get_win() == 0) {
		IMAGE img;
		loadimage(&img, _T("res/��ʤ.png"), 897, 895);
		putimage(0, 0, &img);
	}
	else if (chess->get_win() == -1) {
		IMAGE img;
		loadimage(&img, _T("res/ƽ��.png"), 897, 895);
		putimage(0, 0, &img);
	}
	Sleep(1000);
	return;
}

