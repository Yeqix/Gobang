#include <conio.h>
#include <graphics.h>
#include <vector>
#include "Chess.h"

#ifndef BOARD_H
#define BOARD_H
class Board {
   public:
    std::vector<std::vector<Chess>> chess;
    Board();
    void setBoard();           // 画棋盘
    void setChess();           // 设置棋子坐标
    void showBoard(int, int);  // 显示棋子
};
#endif