#pragma once
#include <graphics.h>
#include <vector>

#include "Point.h"
using namespace std;
class Chess : public Point
{
private:
    int board[19][19];
    vector<pair<int, int>> stk; // 用于存储撤销的棋子
    int top, left, board_size; // 棋盘的边界(留白部分)，棋盘大小
    double chess_size;
    int turn;           // 记录棋子数量
    int win;            // 1为黑胜，-1为平
    IMAGE black, white; // 棋子的图片
public:
    void init();
    void set_information(int board_size, int top, int left, double chess_size);
    int boardsize();                                      // 返回棋盘大小
    int getColor(int x, int y);                           // 返回棋子颜色
    void chessDown(int x, int y, int color, bool sound);  // 下棋
    bool isvaild(int x, int y, int *down_x, int *down_y); // 判断是否可以下棋
    void withdraw(int mode);
    void change_turn();
    int get_turn();
    int menu();
    void record();
    void load_game();
    void delete_chess();      // 删除棋子
    bool gameover(int color); // 返回结果
    void set_win(int winner); // 设置胜利者
    int get_win();
    void load_map();
    ~Chess();
};
