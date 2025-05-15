#include <graphics.h>
#include <conio.h>
#include "Chess.h"
Chess::Chess()
{
    x = 0, y = 0;
}
void Chess::showSpot()
{
    switch (state)
    {
    case NULL:
        break;
    case 1: // play1
        setfillcolor(BLACK);
        break;
    case 2: // play2
        setfillcolor(WHITE);
        break;
    default:
        break;
    }
    solidcircle(x * 30 + 15, y * 30 + 15, 13);
}