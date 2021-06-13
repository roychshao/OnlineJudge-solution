#include <stdio.h>

int main()
{
	int i=0,j=0,times,N;
	int temp,money;
	scanf("%d",&times);
	while(i<times)
	{
		money = 0;
		j = 0;
		scanf("%d",&N);
		while(j<N)
		{
			scanf("%d",&temp);
			money += temp;
			j++;
		}
		if(money<=500)
		{
			printf("Sheng has his idea.\n");
		}
		else
		{
			printf("Sheng has no idea.\n");
		}
		i++;
	}
	return 0;
}
