//#include "GameUI.h"
//#include<conio.h>
//#include<iostream>
//
//GomokuUI::GomokuUI():selectedMenu(0){}
//GomokuUI::~GomokuUI()
//{
//	closegraph();
//}
//void GomokuUI::InitUI()
//{
//	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
//	setbkcolor(RGB(240, 215, 180));
//	cleardevice();
//	settextstyle(30, 0, _T("����"));
//	settextcolor(BLACK);
//}
//void GomokuUI::ShowMainMenu()
//{
//	cleardevice();
//	settextstyle(50, 0, _T("����"));
//	settextcolor(BLACK);
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("��������Ϸ")) / 2, 100, _T("��������Ϸ"));
//	settextstyle(30, 0, _T("����"));
//	if (selectedMenu == 0)
//	{
//		settextcolor(RED);
//	}
//	else 
//	{
//		settextcolor(BLACK);
//	}
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("����ģʽ")) / 2,250,_T("����ģʽ"));
//	if (selectedMenu == 1)
//	{
//		settextcolor(RED);
//	}
//	else
//	{
//		settextcolor(BLACK);
//	}
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("������ģʽ")) / 2, 320, _T("������ģʽ"));
//	settextstyle(20, 0, _T("����"));
//	settextcolor(BLACK);
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("ѡ����Ϸģʽ��ʼ��Ϸ")) / 2, 400, _T("ѡ����Ϸģʽ��ʼ��Ϸ"));
//	FlushBatchDraw();
//}
//GameState GomokuUI::HandleMenuInput()
//{
//	if (GetAsyncKeyState(VK_UP) & 0x8000)
//	{
//		selectedMenu = (selectedMenu - 1 + 2) % 2;
//		Sleep(150);
//	}
//	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
//	{
//		selectedMenu = (selectedMenu + 1) % 2;
//		Sleep(150);
//	}
//	else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
//	{
//		Sleep(150);
//		switch (selectedMenu)
//		{
//		case 0:return SINGLE_PLAYER;
//		case 1:return MULTI_PLAYER;
//		}
//	}
//	else if (GetAsyncKeyState(VK_ESCAPE)&0x8000)
//	{
//		return EXIT;
//	}
//	return MENU;
//}