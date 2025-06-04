//#include<stdio.h>
//#include<easyx.h>
//#include <graphics.h>
//#include<Windows.h>
//
//void UI() {
//    initgraph(542, 542);//创建窗口的大小
//    IMAGE img;//定义一个储存图片的变量
//    loadimage(&img, "wuziqi.jpg", 542, 542);//将中间的图片放进变量里，后面的数字是改变图片的大小
//    putimage(0, 0, &img);//前面的数字是坐标
//    //
//    while (1) {
//        MOUSEMSG msg = { 0 };
//        if (MouseHit())//如果有鼠标消息
//        {
//            msg = GetMouseMsg();//获取鼠标消息
//            if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 32 && msg.x <= 239 && msg.y <= 510 && msg.y >= 453)
//            {
//                printf("人机模式");//改这里即可
//
//            }
//            else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 306 && msg.x <= 511 && msg.y <= 512 && msg.y >= 449) {
//                printf("联机模式");//改这里即可
//            }
//
//        }
//    }
//    return;
//}