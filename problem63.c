#include <stdio.h>
#include <string.h>

char board[30][25];
int boardcmp[30];
char cmp[10][25] = { "Royal Straight Flush\n","Straight Flush\n","Four of a kind\n"
	,"Full house\n","Flush\n","Straight\n","Three of a kind\n","Two pair\n","One pair\n","Zitch\n" };

int find(int j)
{
	for (int k = 0; k < 10; ++k)
	{
		if (strcmp(board[j], cmp[k]) == 0)
			return k;
	}
}

int main()
{
	int i = 0;
	char temp[25];
	int tempi;
	while (fgets(board[i], 25, stdin))
		i++;
	for (int j = 0; j < i; ++j)
	{
		boardcmp[j] = find(j);
	}
	for (int j = i - 1; j > 0; j--)
	{
		for (int k = 0; k <= j - 1; ++k)
		{
			if (boardcmp[k] > boardcmp[k + 1])
			{
				strcpy(temp, board[k + 1]);
				strcpy(board[k + 1], board[k]);
				strcpy(board[k], temp);
				tempi = boardcmp[k + 1];
				boardcmp[k + 1] = boardcmp[k];
				boardcmp[k] = tempi;
			}
		}
	}
	for (int j = 0; j < i; ++j)
	{
		printf("%s", board[j]);
	}
}

