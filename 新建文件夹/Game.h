#pragma once  
#include "Man.h"  
#include "AI.h"  
#include "Chess.h"  

class Game {  
    Man* man;  
    AI* ai;  
    Chess* chess; 
public:  
    Game(Man* man, AI* ai, Chess* chess);  
    void init();  
    void startGame();
	int chose_mode();
	void chose_color();
    void show_winner();
};