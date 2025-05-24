#pragma once
#include "Chess.h"
#ifndef AI_H
#define AI_H
class AI {
    int color;
    Chess* chess; 
    int score[19][19];
public:

    void init(Chess *chess,int color);
    void go();
	void setScore();
};
#endif

