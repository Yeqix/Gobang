#pragma once
#include "Chess.h"
class Man
{
    Chess *chess;
    int color;
    int mode;

public:
    void init(Chess *chess, int color, int mode);
    int go();
    int get_color();
};
