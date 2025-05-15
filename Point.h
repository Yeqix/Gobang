#ifndef POINT_H
#define POINT_H
class Point
{
public:
    void setXY(int, int);
    virtual void showPoint() = 0;

protected:
    int x;
    int y;
};
#endif