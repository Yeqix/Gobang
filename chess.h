#include <graphics.h>
#include <conio.h>
#include "Point.h"
#ifndef CHESS_H
#define CHESS_H
class Chess : public Point
{
public:
    Chess();
    int state = -1; // 当前棋子状态
    void showSpot();
};
#endif