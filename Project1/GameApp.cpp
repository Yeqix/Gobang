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
//	MessageBox(NULL, _T("单机模式开始"), _T("提示"),MB_OK);
//}
//void GameApp::handleMultiPlayer()
//{
//	MessageBox(NULL, _T("局域网模式"), _T("提示"), MB_OK);
//}