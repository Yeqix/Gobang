#ifndef CHESS_H
#define CHESS_H
class chess
{
public:
    chess();
    chess(int, int);
    void setX(int);
    void setY(int);

private:
    int x;
    int y;
}