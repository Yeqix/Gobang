#include <conio.h>
#include <graphics.h>
#include "Point.h"

#ifndef CHESS_H
#define CHESS_H
class Chess : public Point {
public:
    int state;  // ��ǰ����״̬(��˭ռ��) ����-1��ʾδ���κ����ռ��
    Chess();
    void showSpot();  // ������
};
#endif
