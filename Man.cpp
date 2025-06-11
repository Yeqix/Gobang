#include "Man.h"
#include <graphics.h>
#include <iostream>
void Man::init(Chess *chess, int color, int mode)
{
    this->color = color;
    this->chess = chess;
    this->mode = mode;
}
int Man::go()
{
    MOUSEMSG msg;
    int x, y;
    while (1)
    {
        msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            if (chess->isvaild(msg.x, msg.y, &x, &y))
            {
                chess->chessDown(x, y, color, 1);
                return 0;
            }
        }
        else if (msg.uMsg == WM_RBUTTONDOWN)
        {
            chess->withdraw(mode);
            return 0;
        }
        else if (msg.uMsg == WM_MBUTTONDOWN)
        {
            return chess->menu();
        }
    }
}

int Man::get_color()
{
    return color;
}
