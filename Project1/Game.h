#include <conio.h>
#include <graphics.h>
#include "Board.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H
class Game {
public:
    Game();
    Player playerone, playertwo;  // 一盘游戏，两个玩家
    Board* p;
    int winer;                // 赋值，判断谁为赢家
    void loadImage();         // 加载图像
    void startGame();         // 开始游戏加载
    bool exam(Board* board);  // 判断是否有人胜利
    int Game_();
    void UI();

protected:
    int x;
    int y;
    MOUSEMSG msg;
};
#endif
