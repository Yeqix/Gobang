#include <graphics.h>
#include <conio.h>
#include "Player.h"

MOUSEMSG Player::Get()
{
    MOUSEMSG m;
    while (1)
    {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN || m.uMsg == WM_RBUTTONDOWN)
        {
            break;
        }
    }
    return m;
}