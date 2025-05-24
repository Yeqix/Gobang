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
	mciSendString("play res/��������.mp3 repeat", 0, 0, 0);//���ű�������
	mode = chose_mode();//ѡ��ģʽ


	if (mode) {//�˻�
	     chose_color();//ѡ����ɫ
	}
	else {
		man->init(chess, 1);
		man2->init(chess, 0);
	}
		chose_board();//ѡ������
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
void Game::chose_board()
{
	IMAGE img;
	loadimage(&img, _T("res/ѡ����.png"), 897, 895);
	putimage(0, 0, &img);
	MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {//����������
			mciSendString("play res/�����Ч.mp3", 0, 0, 0);
			if (msg.x >= 82 && msg.x <= 399 && msg.y >= 664 && msg.y <= 794) {
				cleardevice();
				chess->set_information(13, 44, 44, 67);
				IMAGE img;
				loadimage(&img, _T("res/13·.jpg"), 897, 895);
				putimage(0, 0, &img);
				return;
			}
			else if (msg.x >= 496 && msg.x <= 814 && msg.y >= 660 && msg.y <= 794) {
				cleardevice();

				chess->set_information(19, 27, 30, 46.5);

				IMAGE img;
				loadimage(&img, _T("res/19·.jpg"), 897, 895);
				putimage(0, 0, &img);
				return ;
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

bool Game::end_game()
{
	cleardevice();
	MOUSEMSG msg;
	IMAGE img;
	loadimage(&img, _T("res/�Ƿ��ؿ�.png"), 897, 895);
	putimage(0, 0, &img);
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {//����������
			mciSendString("play res/�����Ч.mp3", 0, 0, 0);
			if (msg.x >= 108 && msg.x <= 371 && msg.y >= 467 && msg.y <= 679) {
				return 1;
			}
			else if (msg.x >= 518 && msg.x <= 786 && msg.y >= 467 && msg.y <= 680) {
				return 0;
			}
		}
	}
}

