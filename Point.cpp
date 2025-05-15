#include <graphics.h>
#include <conio.h>
#include "Point.h"
Point::Point()
{
    x = y = 0;
}
void Point::setXY(int x1, int y1)
{
    x = x1;
    y = y1;
}