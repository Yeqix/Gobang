//#include<stdio.h>
//#include<easyx.h>
//#include <graphics.h>
//#include<Windows.h>
//
//void UI() {
//    initgraph(542, 542);//�������ڵĴ�С
//    IMAGE img;//����һ������ͼƬ�ı���
//    loadimage(&img, "wuziqi.jpg", 542, 542);//���м��ͼƬ�Ž����������������Ǹı�ͼƬ�Ĵ�С
//    putimage(0, 0, &img);//ǰ�������������
//    //
//    while (1) {
//        MOUSEMSG msg = { 0 };
//        if (MouseHit())//����������Ϣ
//        {
//            msg = GetMouseMsg();//��ȡ�����Ϣ
//            if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 32 && msg.x <= 239 && msg.y <= 510 && msg.y >= 453)
//            {
//                printf("�˻�ģʽ");//�����Ｔ��
//
//            }
//            else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 306 && msg.x <= 511 && msg.y <= 512 && msg.y >= 449) {
//                printf("����ģʽ");//�����Ｔ��
//            }
//
//        }
//    }
//    return;
//}