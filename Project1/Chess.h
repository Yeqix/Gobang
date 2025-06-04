#include <conio.h>
#include <graphics.h>
#include "Point.h"

#ifndef CHESS_H
#define CHESS_H
class Chess : public Point {
public:
    int state;  // 当前棋子状态(被谁占用) 其中-1表示未被任何玩家占用
    Chess();
    void showSpot();  // 画棋子
};
#endif
