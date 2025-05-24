#pragma once
#include "Chess.h"
class Man {
Chess* chess;
int color;
public:
    void init(Chess *chess,int color);
    void go();
    int get_color();
};

