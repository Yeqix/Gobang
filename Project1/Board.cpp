#include "Board.h"
#include <conio.h>
#include <graphics.h>
Board::Board() {
    chess.resize(20, std::vector<Chess>(20));
    setChess();
}
void Board::setBoard() {  // 画棋盘
    setfillcolor(RGB(125, 125, 255));
    fillrectangle(0, 0, 800, 600);
    setfillcolor(RGB(255, 255, 125));
    fillrectangle(0, 0, 600, 600);
    setlinecolor(BLACK);
    for (int i = 15; i < 600; i += 30) {
        line(i, 15, i, 585);
        line(15, i, 585, i);
    }
}
void Board::setChess() {  // 初始化chess数组内的棋子元素的位置
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            chess[i][j].setXY(i, j);
        }
    }
}
void Board::showBoard(int x1, int y1) {  // 调用画棋子
    chess[x1][y1].showSpot();
}