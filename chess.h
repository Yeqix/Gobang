#include <graphics.h>
#include <conio.h>
#include "Point.h"
#ifndef CHESS_H
#define CHESS_H
class Chess : public Point
{
public:
    int state; // 当前棋子状态
    void showSpot();
};
#endif