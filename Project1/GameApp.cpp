//#include "GameApp.h"
//#include "Windows.h"
//GameApp::GameApp() :currentState(MENU)
//{
//	ui.InitUI();
//}
//void GameApp::Run()
//{
//	while (currentState != EXIT)
//	{
//		switch (currentState)
//		{
//		case MENU:
//			ui.ShowMainMenu();
//			currentState = ui.HandleMenuInput();
//			break;
//		case SINGLE_PLAYER:
//			handleSinglePlayer();
//			currentState = MENU;
//			break;
//		case MULTI_PLAYER:
//			handleMultiPlayer();
//			currentState = MENU;
//			break;
//		case EXIT:
//			break;
//		}
//		Sleep(10);
//	}
//}
//void GameApp::handleSinglePlayer()
//{
//	MessageBox(NULL, _T("����ģʽ��ʼ"), _T("��ʾ"),MB_OK);
//}
//void GameApp::handleMultiPlayer()
//{
//	MessageBox(NULL, _T("������ģʽ"), _T("��ʾ"), MB_OK);
//}