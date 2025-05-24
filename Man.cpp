#include "Man.h"
#include <graphics.h>
void Man::init(Chess* chess, int color) {
    this->color = color;
    this->chess = chess;
}
void Man::go() {
    MOUSEMSG msg;
    int x, y;
    while (1) {
        msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN) {  // Êó±ê×ó¼ü°´ÏÂ
            if (chess->isvaild(msg.x, msg.y, &x, &y)) {
                break;
            }
        }
    }
    chess->chessDown(x, y, color);
}

int Man::get_color() {
    return color;
}
