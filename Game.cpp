#include "Game.h"
#include <mmsystem.h>
#include <windows.h>
#include <iostream>
#include "AI.h"
#include "Chess.h"
#pragma comment(lib, "winmm.lib")
Game::Game(Man *man, AI *ai, Chess *chess, Man *man2)
{
    this->man = man;
    this->ai = ai;
    this->chess = chess;
    this->man2 = man2;
}
void Game::startGame()
{
    chose_mode(); // 选择模式
    // std::cout << mode << "\n";
    if (mode.second == 0)
    {
        chose_board();
        chess->init();
    }
    else
    {
        chose_board();
        mode.second = 0;
    }
    if (mode.first)
    {
        chose_color();
    }
    else
    {
        man->init(chess, 1, 0);
        man2->init(chess, 0, 0);
    }
    chess->load_map();
    while (1)
    {
        int state = 0;
        if (man->get_color() == chess->get_turn())
        {
            state = man->go();
        }
        else
        {
            if (mode.first)
            {
                Sleep(1000);
                ai->go();
            }
            else
            {
                state = man2->go();
            }
        }
        if (state == -1)
        {
            return;
        }
        else if (state == 1)
        {
            chess->record();
        }
        if (chess->gameover(chess->get_turn()))
        {
            break;
        }
    }
    show_winner();
    return;
}
void Game::chose_mode()
{
    IMAGE img;
    loadimage(&img, _T("res/选模式.png"), 897, 895);
    putimage(0, 0, &img);
    MOUSEMSG msg;
    while (1)
    {
        msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        { // 鼠标左键按下
            mciSendString("play res/点击音效.mp3", 0, 0, 0);
            if (msg.x >= 56 && msg.x <= 395 && msg.y >= 740 && msg.y <= 846)
            {
                cleardevice();  // 清屏
                mode.first = 1; // 人机
                return;
            }
            else if (msg.x >= 506 && msg.x <= 847 && msg.y >= 740 && msg.y <= 846)
            {
                cleardevice();  // 清屏
                mode.first = 0; // 人人
                return;
            }
            else if (msg.x >= 713 && msg.x <= 874 && msg.y >= 58 && msg.y <= 106)
            {
                chess->load_game();
                mode.second = 1;
            }
        }
    }
}
void Game::chose_board()
{
    IMAGE img;
    loadimage(&img, _T("res/选棋盘.png"), 897, 895);
    putimage(0, 0, &img);
    MOUSEMSG msg;
    while (1)
    {
        msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        { // 鼠标左键按下
            mciSendString("play res/点击音效.mp3", 0, 0, 0);
            if (msg.x >= 82 && msg.x <= 399 && msg.y >= 664 && msg.y <= 794)
            {
                cleardevice();
                chess->set_information(13, 44, 44, 67);
                // IMAGE img;
                // loadimage(&img, _T("res/13路.jpg"), 897, 895);
                // putimage(0, 0, &img);
                return;
            }
            else if (msg.x >= 496 && msg.x <= 814 && msg.y >= 660 && msg.y <= 794)
            {
                cleardevice();
                chess->set_information(19, 27, 30, 46.5);
                // IMAGE img;
                // loadimage(&img, _T("res/19路.jpg"), 897, 895);
                // putimage(0, 0, &img);
                return;
            }
        }
    }
}
void Game::chose_color()
{
    IMAGE img;
    loadimage(&img, _T("res//选黑白.jpg"), 897, 895);
    putimage(0, 0, &img);
    MOUSEMSG msg;
    int x, y;
    while (1)
    {
        msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        { // 鼠标左键按下
            mciSendString("play res/点击音效.mp3", 0, 0, 0);
            if (msg.x >= 210 && msg.x <= 416 && msg.y >= 384 && msg.y <= 523)
            { // 选黑
                man->init(chess, 1, 1);
                ai->init(chess, 0);
                break;
            }
            else if (msg.x >= 482 && msg.x <= 689 && msg.y >= 384 && msg.y <= 523)
            { // 选白
                ai->init(chess, 1);
                man->init(chess, 0, 1);
                break;
            }
        }
    }
    Sleep(300);    // 显示点击音效（bushi
    cleardevice(); // 清屏
}

void Game::show_winner()
{
    Sleep(1000);
    if (chess->get_win() == 1)
    {
        IMAGE img;
        loadimage(&img, _T("res/黑胜.png"), 897, 895);
        putimage(0, 0, &img);
    }
    else if (chess->get_win() == 0)
    {
        IMAGE img;
        loadimage(&img, _T("res/白胜.png"), 897, 895);
        putimage(0, 0, &img);
    }
    else if (chess->get_win() == -1)
    {
        IMAGE img;
        loadimage(&img, _T("res/平局.png"), 897, 895);
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
    loadimage(&img, _T("res/是否重开.png"), 897, 895);
    putimage(0, 0, &img);
    while (1)
    {
        msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        { // 鼠标左键按下
            mciSendString("play res/点击音效.mp3", 0, 0, 0);
            if (msg.x >= 108 && msg.x <= 371 && msg.y >= 467 && msg.y <= 679)
            {
                return 1;
            }
            else if (msg.x >= 518 && msg.x <= 786 && msg.y >= 467 && msg.y <= 680)
            {
                return 0;
            }
        }
    }
}

Game::~Game()
{
    man = nullptr;
    man2 = nullptr;
    ai = nullptr;
    chess = nullptr;
}
