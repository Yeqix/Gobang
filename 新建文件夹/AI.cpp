#include "AI.h"
#include "Chess.h"
#include <cstdlib>
#include <ctime>
void AI::init(Chess* chess, int color)
{
	this->chess = chess;
	this->color = color;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			score[i][j] = 0;
		}
	}
}
void AI::go()
{
	srand(time(0));
	setScore();
	int max_score = -1e9;
	int x = -1, y = -1;
	for (int i = 0; i < chess->boardsize(); i++) {
		for (int j = 0; j < chess->boardsize(); j++) {
			if (chess->getColor(i, j) == -1  ) {
				if (abs(score[i][j] - max_score)<=20) {//随机化，防止过于单一
					if (rand() % 2) {
						max_score = score[i][j];
						x = i;
						y = j;
					}
				}
				else if(score[i][j] > max_score){
					max_score = score[i][j];
					x = i;
					y = j;
				}
			}
		}
	}
	chess->chessDown(x, y, color,1);
}
int rearch(int x, int y, int dx, int dy, Chess* chess, bool& have_other_chess, int color) {
	int count = 0;
	while (true) {
		x += dx;
		y += dy;
		if (x < 0 || x >= chess->boardsize() || y < 0 || y >= chess->boardsize() || chess->getColor(x, y) == -1)  break;
		if (chess->getColor(x, y) == color) count++;
		else {
			have_other_chess = 1;
			break;
		}
	}
	return count;
}
int dx[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };//8个方向，两两成对
void AI::setScore()
{
	for (int i = 0; i < chess->boardsize(); i++)
	{
		for (int j = 0; j < chess->boardsize(); j++)
		{
			score[i][j] = 0;//每次都要清空
			if (chess->getColor(i, j) == -1) {
				int add_score1 = 0;//是否添加分数,一步连成两个三加权值
				int add_score2 = 0;
				for (int k = 0; k < 8; k += 2) {
					bool have_other_chess = 0;
					bool have_other_chess2 = 0;
					int count1 = rearch(i, j, dx[k], dy[k], chess, have_other_chess, color);
					int count2 = rearch(i, j, dx[k + 1], dy[k + 1], chess, have_other_chess2, color);
					if (count1 != 0 && count2 != 0 && have_other_chess + have_other_chess2 == 0) {
						add_score1 ++;
					}
					if (count1 + count2 >= 4) {
						score[i][j] += 400000000;
					}
					else if (count1 + count2 == 3 && have_other_chess + have_other_chess2 == 0) {
						score[i][j] += 3000000;
					}
					else if (count1 + count2 == 3 && have_other_chess + have_other_chess2 == 1) {
						score[i][j] += 100000;
					}
					else if (count1 + count2 == 2 && have_other_chess + have_other_chess2 == 0) {
						score[i][j] += 10000;
					}
					else if (count1 + count2 == 2 && have_other_chess + have_other_chess2 == 1) {
						score[i][j] += 100;
					}
					else if (count1 + count2 == 1 && have_other_chess + have_other_chess2 == 0) {
						score[i][j] += 100;
					}
					else if (count1 + count2 == 1 && have_other_chess + have_other_chess2 == 1) {
						score[i][j] += 30;
					}
					else if (count1 + count2 == 0 && have_other_chess + have_other_chess2 == 0) {
						score[i][j] += 20*(-abs((chess->boardsize())/2-i)-abs((chess->boardsize() ) / 2 - j)) ;//中心越近分数越高
					}
					else if (count1 + count2 == 0 && have_other_chess + have_other_chess2 == 1) {
						score[i][j] += -1;
					}
					else if (have_other_chess + have_other_chess2 == 2) {
						score[i][j] = -10000;
					}
					//搜索另一个颜色，赋予价值
					have_other_chess = 0;
					have_other_chess2 = 0;

					count1 = rearch(i, j, dx[k], dy[k], chess, have_other_chess, color ^ 1);
					count2 = rearch(i, j, dx[k + 1], dy[k + 1], chess, have_other_chess2, color ^ 1);
					if (count1 != 0 && count2 != 0 && have_other_chess + have_other_chess2 == 0) {
						add_score2++;
					}
					if (count1 + count2 + 1 < 5 && have_other_chess + have_other_chess2 == 2) {
						score[i][j] -= 10000;
					}
					if (count1 + count2 + 1 >= 5) {//对方一连五
						score[i][j] += 100000000;
					}
					if (count1 == 3 && have_other_chess == 0|| count2 == 3&& have_other_chess2==0) {
						score[i][j] += 3000000;
					}else if (count1 ==3 && have_other_chess == 1 || count2 == 3 && have_other_chess2 == 1) {
						score[i][j] += 500;
					}
					else if (count1 == 2 && have_other_chess == 0 || count2 == 2 && have_other_chess2 == 0) {
						score[i][j] += 500;
					}
					else if (count1 == 2 && have_other_chess == 1 || count2 == 2 && have_other_chess2 == 1) {
						score[i][j] += 300;
					}
					else if (count1 == 1 && have_other_chess == 0 || count2 == 1 && have_other_chess2 == 0) {
						score[i][j] += 200;
					}
					else if (count1 == 1 && have_other_chess == 1 || count2 == 1 && have_other_chess2 == 1) {
						score[i][j] += 100;
					}
				}
				if(add_score1 >= 2||add_score2>=2) {
					score[i][j] += 9000000;
				}

			}
		}
	}
}
