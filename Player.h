#include <graphics.h>
#include <conio.h>

#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
    int num;
    int foot;
    MOUSEMSG Get();
};
#endif
