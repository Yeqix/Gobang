#include "Game.h"
#include <conio.h>
#include <graphics.h>
#include "Player.h"

Game::Game() {
    playerone.num = 1;
    playertwo.num = 2;
}
void Game::loadImage() {
    IMAGE BACKGROUND;
    loadimage(&BACKGROUND, _T("Source//background.jpg"));
    putimage(0, 0, 1080, 1080, &BACKGROUND, 0, 0);
    // 初始位置50,50
    // 间隔像素85
}

void Game::startGame() {
    setbkmode(TRANSPARENT);  // 设置字符背景透明
    settextcolor(BLACK);     // 设置文本颜色
    while (1) {
        Game_();
    }
}
bool Game::exam(Board* a) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (a->chess[i][j].state != -1) {
                if (i != 0 && i != 1 && i != 18 && i != 19) {
                    if (a->chess[i][j].state == a->chess[i - 1][j].state && a->chess[i][j].state == a->chess[i - 2][j].state &&
                        a->chess[i][j].state == a->chess[i + 1][j].state && a->chess[i][j].state == a->chess[i + 2][j].state) {
                        winer = a->chess[i][j].state;
                        return true;
                    }
                }
                if (j != 0 && j != 1 && j != 18 && j != 19) {
                    if (a->chess[i][j].state == a->chess[i][j - 1].state && a->chess[i][j].state == a->chess[i][j - 2].state &&
                        a->chess[i][j].state == a->chess[i][j + 1].state && a->chess[i][j].state == a->chess[i][j + 2].state) {
                        winer = a->chess[i][j].state;
                        return true;
                    }
                }
                if (j != 0 && j != 1 && j != 18 && j != 19 && i != 0 && i != 1 && i != 18 && i != 19) {
                    if ((a->chess[i][j].state == a->chess[i - 1][j - 1].state && a->chess[i][j].state == a->chess[i - 2][j - 2].state &&
                         a->chess[i][j].state == a->chess[i + 1][j + 1].state && a->chess[i][j].state == a->chess[i + 2][j + 2].state) ||
                        (a->chess[i][j].state == a->chess[i + 1][j - 1].state && a->chess[i][j].state == a->chess[i + 2][j - 2].state &&
                         a->chess[i][j].state == a->chess[i - 1][j + 1].state && a->chess[i][j].state == a->chess[i - 2][j + 2].state)) {
                        winer = a->chess[i][j].state;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int Game::Game_() {
    playerone.foot = 0;
    playertwo.foot = 0;
    playerone.num = 1;
    playertwo.num = 2;
    p = new Board;
    p->setBoard();  // 初始化棋盘
    outtextxy(660, 90, (LPTSTR) "Gobang");
    Player player;               // 当前进行操作的玩家
    player.num = playerone.num;  // 初始化黑棋先行
    while (true) {
    c:
        if (player.num == playerone.num) {
        a:
            msg = playerone.Get();
            if (msg.x > 600 || msg.y > 600) {  // 若坐标不在棋盘内，重新获取鼠标消息
                goto a;
            }
            x = msg.x / 30;
            y = msg.y / 30;
            if (msg.uMsg == WM_RBUTTONDOWN) {
                goto c;
            }
            if (p->chess[x][y].state != -1)  // 若该坐标已经有棋子，重新获取鼠标信息
                goto a;
            playerone.foot++;
            p->chess[x][y].state = playerone.num;  // 将棋子状态设置
            p->showBoard(x, y);                    // 执行修改
            player.num = playertwo.num;            // 更换当前行动玩家
        } else if (player.num == playertwo.num) {  // 与上类似
        b:
            msg = playertwo.Get();
            if (msg.x > 600 || msg.y > 600) {
                goto a;
            }
            x = msg.x / 30;
            y = msg.y / 30;
            if (msg.uMsg == WM_RBUTTONDOWN) {
                goto c;
            }
            if (p->chess[x][y].state != -1)
                goto b;
            playertwo.foot++;
            p->chess[x][y].state = playertwo.num;
            p->showBoard(x, y);
            player.num = playerone.num;
        }
        if (exam(p) == true) {  // 说明此时已经有人胜利进行终止
            if (winer == playerone.num) {
                outtextxy(100, 100, (LPTSTR) "BLACK IS WINER");  //(LPTSTR)为强制转换，输出胜利信息
            } else {
                outtextxy(100, 100, (LPTSTR) "WHITE IS WINER");
            }
            Sleep(3000);  // 将胜利暂停一段时间再重开下一局
            return 0;
        }
    }
    return 1;
}