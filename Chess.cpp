#include "Chess.h"
#include <conio.h>
#include <graphics.h>
#include "Point.h"

Chess::Chess() : Point() {  // 初始化为无人放置
    state = -1;
}
void Chess::showSpot() {
    switch (state) {
        case -1:
            break;
        case 1:  // play1
            setfillcolor(BLACK);
            break;
        case 2:  // play2
            setfillcolor(WHITE);
            break;
        default:
            break;
    }
    solidcircle(x * 30 + 15, y * 30 + 15, 13);
}