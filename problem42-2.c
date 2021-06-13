#include <stdio.h>

int board[1000][1000] = { 0 };

int main()
{
	int N,i=0;
	char input[10];;
	int lxi,lyi,rxi,ryi;
	int pigment = 0;
	scanf("%d",&N);
	while(i < N)
	{
		scanf("%s",input);
		lxi = (int)(input[0] - '0');
		lyi = (int)(input[1] - '0');
		rxi = (int)(input[2] - '0');
		ryi = (int)(input[3] - '0');
		pigment += (rxi-lxi)*(ryi-lyi);
		for(int j=lxi;j<rxi;++j)
		{
			for(int k=lyi;k<ryi;++k)
			{
				board[j][k] = 1;
			}
		}
		i++;
	}
	int area = 0;
	for(int j=0;j<1000;++j)
	{
		for(int k=0;k<1000;++k)
		{
			if(board[j][k])
				area++;
		}
	}
	printf("%d\n%d\n",pigment,area);
	return 0;
}
