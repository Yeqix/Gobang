#include <conio.h>
#include <graphics.h>

#ifndef PLAYER_H
#define PLAYER_H
class Player {
public:
    int num;         // num区分玩家
    int foot;        // 步数
    MOUSEMSG Get();  // 获取鼠标信息
};
#endif
