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
    void setBoard();           // ������
    void setChess();           // ������������
    void showBoard(int, int);  // ��ʾ����
};
#endif