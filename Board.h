#include <graphics.h>
#include <conio.h>
#include "chess.h"

#ifndef BOARD_H
#define BOARD_H
class Board
{
public:
    Chess chess[20][20];
    Board *next;
    Board();
    void setBoard();          // 画棋盘
    void setChess();          // 设置棋子坐标
    void showBoard(int, int); // 显示棋子
};
#endif