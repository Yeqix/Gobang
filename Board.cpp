#include <graphics.h>
#include <conio.h>
#include "Board.h"
Board::Board()
{
    chess.resize(20, std::vector<Chess>(20));
    setChess();
}
void Board::setBoard()
{
    setfillcolor(RGB(125, 125, 255));
    fillrectangle(0, 0, 800, 600);
    setfillcolor(RGB(255, 255, 125));
    fillrectangle(0, 0, 600, 600);
    setlinecolor(BLACK);
    for (int i = 15; i < 600; i += 30)
    {
        line(i, 15, i, 585);
        line(15, i, 585, i);
    }
}
void Board::setChess()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            chess[i][j].setXY(i, j);
            chess[i][j].state = -1;
        }
    }
}
void Board::showBoard(int x1, int y1)
{
    chess[x1][y1].showSpot();
}