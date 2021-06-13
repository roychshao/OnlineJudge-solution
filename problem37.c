#include <stdio.h>
#include <string.h>

char board[20][20];

void print(int N)
{
	int i,j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf(" %c ", board[i][j]);
		}
		if(j != N-1)	
			printf("\n");
	}
}

int main()
{
	char input[30];
	int N, len, x = 0, y = 0;
	memset(board,'.', sizeof(board));
	board[0][0] = '@';
	scanf("%d", &N);
	scanf(" ");
	fgets(input,30,stdin);
	len = strlen(input)-1;
	print(N);
	printf("\n");
	for (int i = 0; i < len; ++i)
	{
		board[x][y] = '.';
		if (input[i] == 'R')
		{
			y++;
			board[x][y] = '@';
		}
		else if (input[i] == 'L')
		{
			y--;
			board[x][y] = '@';
		}
		else if (input[i] == 'D')
		{
			x++;
			board[x][y] = '@';
		}
		else if (input[i] == 'T')
		{
			x--;
			board[x][y] = '@';
		}
		print(N);
		printf("\n");
	}
	return 0;
}

