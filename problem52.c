#include <stdio.h>

int board[50][50];

int main()
{
	int N, drct, step = 0, limit = 1, times = 0;
	int x, y;
	scanf("%d", &N);
	x = y = (N - 1) / 2;
	scanf("%d", &drct);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &board[i][j]);
		}
	}
	printf("%d", board[x][y]);
	while (x < N && x >= 0 && y < N && y >= 0)
	{
		if (drct > 3)
			drct = 0;
		if (drct == 0)
			y--;
		else if (drct == 1)
			x--;
		else if (drct == 2)
			y++;
		else if (drct == 3)
			x++;
		if (x >= N || x < 0 || y >= N || y < 0)
			break;
		printf("%d", board[x][y]);
		step++;
		if (step == limit)
		{
			times++;
			if (times == 2)
			{
				limit++;
				times = 0;
			}
			drct++;
			step = 0;
		}
	}
	printf("\n");
	return 0;
}

