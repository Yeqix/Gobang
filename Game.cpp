#include <graphics.h>
#include <conio.h>
#include "Game.h"
#include "Player.h"

Game::Game()
{
    playerone.num = play1;
    playertwo.num = play2;
}
void Game::loadImage()
{
    IMAGE BACKGROUND;
    loadimage(&BACKGROUND, _T("Source//background.jpg"));
    putimage(0, 0, 1080, 1080, &BACKGROUND, 0, 0);
    // 初始位置50,50
    // 间隔像素85
}

void Game::startGame()
{
    setbkmode(TRANSPARENT); // 设置字符背景透明
    settextcolor(BLACK);    // 设置文本颜色
    while (1)
    {
        Game_();
    }
}
bool Game::exam(Board *a)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (a->chess[i][j].state != NULL)
            {
                if (i != 0 && i != 1 && i != 18 && i != 19)
                {
                    if (a->chess[i][j].state == a->chess[i - 1][j].state && a->chess[i][j].state == a->chess[i - 2][j].state && a->chess[i][j].state == a->chess[i + 1][j].state && a->chess[i][j].state == a->chess[i + 2][j].state)
                    {
                        winer = a->chess[i][j].state;
                        return true;
                    }
                }
                if (j != 0 && j != 1 && j != 18 && j != 19)
                {
                    if (a->chess[i][j].state == a->chess[i][j - 1].state && a->chess[i][j].state == a->chess[i][j - 2].state && a->chess[i][j].state == a->chess[i][j + 1].state && a->chess[i][j].state == a->chess[i][j + 2].state)
                    {
                        winer = a->chess[i][j].state;
                        return true;
                    }
                }
                if (j != 0 && j != 1 && j != 18 && j != 19 && i != 0 && i != 1 && i != 18 && i != 19)
                {
                    if (
                        (a->chess[i][j].state == a->chess[i - 1][j - 1].state && a->chess[i][j].state == a->chess[i - 2][j - 2].state && a->chess[i][j].state == a->chess[i + 1][j + 1].state && a->chess[i][j].state == a->chess[i + 2][j + 2].state) ||
                        (a->chess[i][j].state == a->chess[i + 1][j - 1].state && a->chess[i][j].state == a->chess[i + 2][j - 2].state && a->chess[i][j].state == a->chess[i - 1][j + 1].state && a->chess[i][j].state == a->chess[i - 2][j + 2].state))
                    {
                        winer = a->chess[i][j].state;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int Game::Game_()
{
    playerone.foot = 0;
    playertwo.foot = 0;
    playerone.num = play1;
    playertwo.num = play2;
    boardH = p = q = r = new Board;
    p->setBoard();
    outtextxy(660, 90, L"五子棋");
    boardH->next = p->next = q->next = NULL;
    Player player;
    player.num = playerone.num;
    while (true)
    {
        q = p;
        p = new Board;
    c:
        *p = *q;
        q->next = p;
        p->next = NULL;
        if (player.num == playerone.num)
        {
        a:
            msg = playerone.Get();
            x = m1.x / 30;
            y = m1.y / 30;
            if (m1.uMsg == WM_RBUTTONDOWN)
            {
                goto c;
            }
            if (p->chess[x][y].state != null)
                goto a;
            playerone.foot++;
            p->chess[x][y].state = playerone.num;
            p->showBoard(x, y);
            player.num = playertwo.num;
        }
        else if (player.num == playertwo.num)
        {
        b:
            msg = playertwo.Get();
            x = m1.x / 30;
            y = m1.y / 30;
            if (m1.uMsg == WM_RBUTTONDOWN)
            {
                goto c;
            }
            if (p->chess[x][y].state != null)
                goto b;
            playertwo.foot++;
            p->chess[x][y].state = playertwo.num;
            p->showBoard(x, y);
            player.num = playerone.num;
        }

        else
        {
        }
        if (exam(p) == true)
        {
            if (winer == playerone.num)
            {
                outtextxy(100, 100, L"BLACK IS WINER");
            }
            else
            {
                outtextxy(100, 100, L"WHITE IS WINER");
            }
            Sleep(3000);
            return 0;
        }
    }
    return 1;
}