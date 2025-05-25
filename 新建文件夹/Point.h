#ifndef POINT_H
#define POINT_H
class Point {
public:
    Point();
    Point(int a, int b);
    void setXY(int, int);
    virtual void showPoint() { return; }

protected:
    int x;
    int y;
};
#endif