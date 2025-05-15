#include <graphics.h>
#include <conio.h>
using namespace std;
IMAGE BACKGROUND;
void PutBackGround()
{
    putimage(0, 0, 1080, 1080, &BACKGROUND, 0, 0);
}
int main()
{
    initgraph(1080, 1080); // 创建窗口像素点
    loadimage(&BACKGROUND, _T("Source//background.jpg"));
    PutBackGround();
    setlinecolor(BLACK);
    // 初始位置50,50
    // 间隔像素85
    setfillcolor(BLACK);
    fillcircle(50, 50, 35);
    fillcircle(50, 135, 35);
    fillcircle(135, 50, 35);
    setfillcolor(WHITE);
    fillcircle(220, 50, 35);
    fillcircle(305, 50, 35);
    _getch();
    closegraph();
    return 0;
}