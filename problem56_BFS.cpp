#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define _fio \
	ios::sync_with_studio(0); \
cin.tie(0);

typedef struct data
{
	int x;
	int y;
	int step;
}Data;

char board[1005][1005];
int counter = 0;
queue<Data> que;

int BFS(int n,int m)
{
	while (!que.empty())
		que.pop();
	Data temp, pop, judge;
	int x = 0, y = 0,step = 0;
	temp.x = 0, temp.y = 0, temp.step = 0;
	que.push(temp);
	board[0][0] = '*';
	while (!que.empty())
	{
		counter++;
		pop = que.front();
		x = pop.x, y = pop.y, step = pop.step;
		judge = que.back();
		if (judge.x == n - 1 && judge.y == m - 1)
			return judge.step;
		if (board[x - 1][y] == '.')
		{
			temp.x = x - 1, temp.y = y, temp.step = step + 1;
			que.push(temp);
			board[x - 1][y] = '*';
		}
		if (board[x][y - 1] == '.')
		{
			temp.x = x, temp.y = y - 1, temp.step = step + 1;
			que.push(temp);
			board[x][y - 1] = '*';
		}
		if (board[x][y + 1] == '.')
		{
			temp.x = x, temp.y = y + 1, temp.step = step + 1;
			que.push(temp);
			board[x][y + 1] = '*';
		}
		if (board[x + 1][y] == '.')
		{
			temp.x = x + 1, temp.y = y, temp.step = step + 1;
			que.push(temp);
			board[x + 1][y] = '*';
		}
		que.pop();
	}
	return -1;
}

int main()
{
	int times, i = 0;
	int n, m,ans;
	cin >> times;
	while (i < times)
	{
		counter = 0;
		memset(board, NULL, sizeof(board));
		cin >> n >> m;
		for (int s = 0; s < n; ++s)
		{
			cin >> board[s];
		}
		ans = BFS(n,m);
		cout << "Run " << counter <<" times"<< endl;
		if (ans != -1)
			cout << ans << endl;
		else
			cout << "unbelievable" << endl;
		i++;
	}
}
