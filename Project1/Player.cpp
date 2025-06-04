#include "Player.h"
#include <conio.h>
#include <graphics.h>

MOUSEMSG Player::Get() {
    MOUSEMSG m;
    while (1) {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_RBUTTONDOWN)  // 当获取到有效信息后再返回值
        {
            break;
        }
    }
    return m;
}