#include <graphics.h>
#include <conio.h>
#include "Board.h"
Board::Board()
{
    setChess();
}
void Board::setBoard()
{
}
void Board::setChess()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            chess[i][j].setXY(i, j);
            chess[i][j].state = NULL;
        }
    }
}
void Board::showBoard(int x1, int y1)
{
    chess[x1][y1].showSpot();
}