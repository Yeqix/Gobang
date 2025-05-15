#ifndef POINT_H
#define POINT_H
class Point
{
public:
    Point();
    void setXY(int, int);
    virtual void showPoint() = 0;

protected:
    int x;
    int y;
};
#endif