#include "Player.h"
#include <conio.h>
#include <graphics.h>

MOUSEMSG Player::Get() {
    MOUSEMSG m;
    while (1) {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_RBUTTONDOWN)  // ����ȡ����Ч��Ϣ���ٷ���ֵ
        {
            break;
        }
    }
    return m;
}