#include "Chess.h"
#include "Game.h"
#include <graphics.h>
#include <mmsystem.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#pragma comment(lib, "winmm.lib")
#include <math.h>
#include <vector>
using namespace std;

void putimagePNG(int x, int y, IMAGE *picture) // ȥ��������Χ�ڱ�
{
    DWORD *dst = GetImageBuffer(); // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
    DWORD *draw = GetImageBuffer();
    DWORD *src = GetImageBuffer(picture);      // ��ȡpicture���Դ�ָ��
    int picture_width = picture->getwidth();   // ��ȡpicture�Ŀ�ȣ�EASYX�Դ�
    int picture_height = picture->getheight(); // ��ȡpicture�ĸ߶ȣ�EASYX�Դ�
    int graphWidth = getwidth();               // ��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
    int graphHeight = getheight();             // ��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
    int dstX = 0;
    for (int iy = 0; iy < picture_height; iy++)
    {
        for (int ix = 0; ix < picture_width; ix++)
        {
            int srcX = ix + iy * picture_width;        // ���Դ������صĽǱ�
            int sa = ((src[srcX] & 0xff000000) >> 24); // 0xAArrggbb;AA��͸����
            int sr = GetRValue(src[srcX]);             // ��ȡRGB���R
            int sg = GetGValue(src[srcX]);
            int sb = GetBValue(src[srcX]);
            // int sr =((src[srcX] & 0xff0000) >> 16);             // ��ȡRGB���R
            // int sg = ((src[srcX] & 0xff00) >> 8);  // G
            // int sb = src[srcX] & 0xff;             // B
            if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
            {
                dstX = (ix + x) + (iy + y) * graphWidth; // ���Դ������صĽǱ�
                int dr = ((dst[dstX] & 0xff0000) >> 16);
                int dg = ((dst[dstX] & 0xff00) >> 8);
                int db = dst[dstX] & 0xff;
                draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  // ��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
                             | ((sg * sa / 255 + dg * (255 - sa) / 255) << 8) // ��p=sa/255 , FP=sg , BP=dg
                             | (sb * sa / 255 + db * (255 - sa) / 255);       // ��p=sa/255 , FP=sb , BP=db
            }
        }
    }
}

void Chess::init()
{
    turn = 1; // ����Ϊ����
    for (int i = 0; i < board_size; i++) // �������
    {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = -1;
        }
    }
}

void Chess::set_information(int board_size, int top, int left, double chess_size)
{
    mciSendString("play res/start.wav", 0, 0, 0);
    loadimage(&black, "res/black.png", chess_size, chess_size, 1);
    loadimage(&white, "res/white.png", chess_size, chess_size, 1);
    this->board_size = board_size;
    this->top = top;
    this->left = left;
    this->chess_size = chess_size;
}

void Chess::chessDown(int x, int y, int color, bool sound) // sound==1ʱΪ���壬==0Ϊ���壬���貥����Ч
{
    board[x][y] = color;
    int down_x = top + chess_size * x - 0.5 * chess_size;
    int down_y = left + chess_size * y - 0.5 * chess_size;
    if (sound)
    {
        mciSendString("play res/������.mp3", 0, 0, 0); // ��Ч
        stk.push_back({x, y});
        turn ^= 1;
    }
    if (color == 1)
    {
        putimagePNG(down_x, down_y, &black);
    }
    else
    {
        putimagePNG(down_x, down_y, &white);
    }
}

bool Chess::isvaild(int x, int y, int *down_x, int *down_y)
{
    if (x > 0 && y > 0 && x <= top + (board_size)*chess_size && y <= left + (board_size)*chess_size) // �ж��Ƿ���������
    {
        *down_x = (x - top + chess_size / 2) / chess_size;
        *down_y = (y - left + chess_size / 2) / chess_size;
        if (board[*down_x][*down_y] == -1)
        {
            return true;
        }
        else
        {
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

int dxx[4] = {0, 1, 1, 1};
int dyy[4] = {1, 0, 1, -1};

bool Chess::gameover(int color)
{
    bool _continue = 0; // �Ƿ���λ����
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (board[i][j] == -1)
            {
                _continue = 1;
            }
            if (board[i][j] == color)
            {
                for (int k = 0; k < 4; k++)
                {
                    int cnt = 1;
                    for (int l = 1; l < 5; l++)
                    {
                        int x = i + dxx[k] * l;
                        int y = j + dyy[k] * l;
                        if (x >= 0 && x < board_size && y >= 0 && y < board_size)
                        {
                            if (board[x][y] == color)
                            {
                                cnt++;
                            }
                        }
                    }
                    if (cnt >= 5)
                    {
						stk.clear(); // ��ջ���ջ
                        set_win(color);
                        return true;
                    }
                }
            }
        }
    }
    if (_continue == 0)
    {
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

void Chess::delete_chess()
{
    turn ^= 1;
    if (!stk.empty())
    {
        board[stk.back().first][stk.back().second] = -1;
        stk.pop_back();
    }
}

void Chess::load_map()
{
    IMAGE img;
    if (board_size == 13)
    {
        loadimage(&img, _T("res/13·.jpg"), 897, 895);
    }
    else
    {
        loadimage(&img, _T("res/19·.jpg"), 897, 895);
    }
    putimage(0, 0, &img);
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < boardsize(); j++)
        {
            if (board[i][j] != -1)
            {
                chessDown(i, j, board[i][j], 0); // ������
            }
        }
    }
}


void Chess::withdraw(int mode) // ����
{
    if (stk.empty())
    {
        //turn ^= 1;
        return;
    }
    delete_chess();
    if (mode == 1)
    {
        //turn ^= 1;
        if (stk.empty())
        {
            load_map();

            return;
        }
        delete_chess();
    }
    load_map();
}

void Chess::change_turn()
{
    turn ^= 1;
}

int Chess::get_turn()
{
    return turn;
}

int Chess::menu()
{
    IMAGE img;
    loadimage(&img, _T("res/�˵���.png"), 897, 895);
    putimage(0, 0, &img);
    MOUSEMSG msg;
    while (1)
    {
        msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            if (msg.x >= 500 && msg.x <= 741 && msg.y >= 349 && msg.y <= 434)
            {
                return 1;
            }
            else if (msg.x >= 500 && msg.x <= 741 && msg.y >= 489 && msg.y <= 571)
            {
                return -1;
            }
            else if (msg.x >= 500 && msg.x <= 741 && msg.y >= 627 && msg.y <= 710)
            {
                load_map();
                return 0;
            }
        }
    }
}

void Chess::record()
{
    HWND hnd = GetHWnd();
    MessageBox(hnd, "����ɹ���", "��ʾ", MB_OK);
    ofstream ofs;
    if (board_size == 13) {
        ofs.open("res/date13.txt");
    }
    else {
        ofs.open("res/date19.txt");
    }
    ofs << turn << "\n";
    ofs << board_size << "\n";
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            ofs << board[i][j] << " ";
        }
        ofs << "\n";
    }
    for(int i = 0; i < stk.size(); i++)
    {
        ofs << stk[i].first << " " << stk[i].second << "\n";
	}
    load_map();
    ofs.close();
    return;
}

void Chess::load_game()
{

    ifstream ifs;
    if (board_size == 13) {
       ifs.open("res/date13.txt");
    }
    else {
        ifs.open("res/date19.txt");
    }
    ifs >> turn;
    ifs >> board_size;
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            ifs >> board[i][j];
        }
    }
    int a, b;
    while (ifs >> a >> b) {
		stk.push_back({ a, b });
    }
    ifs.close(); 
    return;
}
