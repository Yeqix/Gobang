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
//	settextstyle(30, 0, _T("宋体"));
//	settextcolor(BLACK);
//}
//void GomokuUI::ShowMainMenu()
//{
//	cleardevice();
//	settextstyle(50, 0, _T("宋体"));
//	settextcolor(BLACK);
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("五子棋游戏")) / 2, 100, _T("五子棋游戏"));
//	settextstyle(30, 0, _T("宋体"));
//	if (selectedMenu == 0)
//	{
//		settextcolor(RED);
//	}
//	else 
//	{
//		settextcolor(BLACK);
//	}
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("单机模式")) / 2,250,_T("单机模式"));
//	if (selectedMenu == 1)
//	{
//		settextcolor(RED);
//	}
//	else
//	{
//		settextcolor(BLACK);
//	}
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("局域网模式")) / 2, 320, _T("局域网模式"));
//	settextstyle(20, 0, _T("宋体"));
//	settextcolor(BLACK);
//	outtextxy(WINDOW_WIDTH / 2 - textwidth(_T("选择游戏模式开始游戏")) / 2, 400, _T("选择游戏模式开始游戏"));
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