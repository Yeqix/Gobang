#include <conio.h>
#include <graphics.h>

#ifndef PLAYER_H
#define PLAYER_H
class Player {
public:
    int num;         // num�������
    int foot;        // ����
    MOUSEMSG Get();  // ��ȡ�����Ϣ
};
#endif
