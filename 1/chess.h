#pragma once
#include <graphics.h>
#include <stack>

#include "Point.h"
using namespace std;
class Chess : public Point {
    int board[19][19];
    stack<pair<int, int>> stk;  // 用于存储撤销的棋子
    int top, left, board_size;  // 棋盘的边界(留白部分)，棋盘大小
    double chess_size;
    bool if_back;//是否返回
    int turn;            
    int win;             // 1为黑胜，-1为平
    IMAGE black, white;  // 棋子的图片
   public:
    void init();
    void set_information(int board_size, int top, int left, double chess_size);
    int boardsize();                                       // 返回棋盘大小
    int getColor(int x, int y);                            // 返回棋子颜色
    bool isvaild(int x, int y, int* down_x, int* down_y);  // 判断是否可以下棋
    void change_turn();
    int get_turn();
    void delete_chess();       // 删除棋子
    void chessDown(int x, int y, int color, bool sound);   // 下棋
    void withdraw(int mode);
    bool gameover(int color);  // 返回结果
    void set_win(int winner);  // 设置胜利者
    int get_win();
    void load_map();
    void back();
    bool get_back();//是否返回
};
