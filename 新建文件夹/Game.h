#pragma once  
#include "Man.h"  
#include "AI.h"  
#include "Chess.h"  

class Game {  
    Man* man,*man2;  
    AI* ai;  
    Chess* chess; 
    int mode;
public:  
    Game(Man* man, AI* ai, Chess* chess,Man* man2);  
    void init();  
    void startGame();
	int chose_mode();
    void chose_board();
	void chose_color();
    void show_winner();
    bool end_game();
};