#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

typedef struct data
{
	int x;
	int y;
	int step;
}Data;

int main()
{
	int Step;
	int sx, sy, ex, ey;
	int x = 0, y = 0,i;
	char board[8][8];
	int xdir[8] = { 2,1,-1,-2,-2,-1,1,2 };
	int ydir[8] = { 1,2,2,1,-1,-2,-2,-1 };
	queue<Data> que;
	Data temp;
	cin >> sx >> sy;
	cin >> ex >> ey;
	x = sx, y = sy;
	que.push({ x,y });
	memset(board, '.', sizeof(board));
	board[sx][sy] = '*';
	if(sx == ex && sy == ey)
	{
		cout << 0 << endl;
		return 0;
	}
	while (!que.empty())
	{
		temp = que.front();
		x = temp.x, y = temp.y, Step = temp.step;;
		for (i = 0; i < 8; ++i)
		{
			if ((x + xdir[i]) >= 0 && (x + xdir[i]) < 8
					&& (y + ydir[i]) >= 0 && (y + ydir[i]) < 8
					&& board[x+xdir[i]][y+ydir[i]] == '.')
			{
				if ((x + xdir[i]) == ex && (y + ydir[i]) == ey)
				{
					if (Step + 1 > 7)
						printf("NO ANSWER\n");
					else
						printf("%d\n", Step+1);
					return 0;
				}
				temp.x = x + xdir[i], temp.y = y + ydir[i], temp.step = Step + 1;
				que.push(temp);
				board[x + xdir[i]][y + ydir[i]] = '*';
			}
		}
		que.pop();
	}
	printf("NO ANSWER\n");
	return 0;
}
