#include "Point.h"
#include <conio.h>
#include <graphics.h>
Point::Point()
{
    x = y = 0;
}
Point::Point(int a, int b)
{
    x = a, y = b;
}

void Point::setXY(int x1, int y1)
{
    x = x1;
    y = y1;
}