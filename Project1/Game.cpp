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
    // ��ʼλ��50,50
    // �������85
}

void Game::startGame() {
    setbkmode(TRANSPARENT);  // �����ַ�����͸��
    settextcolor(BLACK);     // �����ı���ɫ
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
    p->setBoard();  // ��ʼ������
    outtextxy(660, 90, (LPTSTR)"Gobang");
    Player player;               // ��ǰ���в��������
    player.num = playerone.num;  // ��ʼ����������
    while (true) {
    c:
        if (player.num == playerone.num) {
        a:
            msg = playerone.Get();
            if (msg.x > 600 || msg.y > 600) {  // �����겻�������ڣ����»�ȡ�����Ϣ
                goto a;
            }
            x = msg.x / 30;
            y = msg.y / 30;
            if (msg.uMsg == WM_RBUTTONDOWN) {
                goto c;
            }
            if (p->chess[x][y].state != -1)  // ���������Ѿ������ӣ����»�ȡ�����Ϣ
                goto a;
            playerone.foot++;
            p->chess[x][y].state = playerone.num;  // ������״̬����
            p->showBoard(x, y);                    // ִ���޸�
            player.num = playertwo.num;            // ������ǰ�ж����
        }
        else if (player.num == playertwo.num) {  // ��������
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
        if (exam(p) == true) {  // ˵����ʱ�Ѿ�����ʤ��������ֹ
            if (winer == playerone.num) {
                outtextxy(100, 100, (LPTSTR)"BLACK IS WINER");  //(LPTSTR)Ϊǿ��ת�������ʤ����Ϣ
            }
            else {
                outtextxy(100, 100, (LPTSTR)"WHITE IS WINER");
            }
            Sleep(3000);  // ��ʤ����ͣһ��ʱ�����ؿ���һ��
            return 0;
        }
    }

    return 1;
}
void Game::UI() {
    initgraph(542, 542);//�������ڵĴ�С
    IMAGE img;//����һ������ͼƬ�ı���
    loadimage(&img, "wuziqi.jpg", 542, 542);//���м��ͼƬ�Ž����������������Ǹı�ͼƬ�Ĵ�С
    putimage(0, 0, &img);//ǰ�������������
    //
    while (1) {
        MOUSEMSG msg = { 0 };
        if (MouseHit())//����������Ϣ
        {
            msg = GetMouseMsg();//��ȡ�����Ϣ
            if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 32 && msg.x <= 239 && msg.y <= 510 && msg.y >= 453)
            {
                printf("�˻�ģʽ");//�����Ｔ��

            }
            else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 306 && msg.x <= 511 && msg.y <= 512 && msg.y >= 449) {
                printf("����ģʽ");//�����Ｔ��
            }

        }
    }
    return;
}