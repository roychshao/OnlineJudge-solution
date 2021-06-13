#include <stdio.h>

int compare(int *bet,int *prices)
{
	int counter = 0,special = 0;
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
		{
			if(bet[i] == prices[j])
				counter++;
		}
	}
	for(int i=0;i<6;++i)
	{
		if(bet[i] == prices[6])
			special = 1;
	}
	if(counter == 5 && special == 1)
		return 100;
	else
		return counter;
}

int main()
{
	int prices[7];
	int bet[7];
	int i,money=0,counter=0;
	for(i=0;i<7;++i)
	{
		scanf("%d",&prices[i]);
	}
	while(scanf("%d",&bet[0])!=EOF)
	{
		for(i=1;i<6;++i)
		{
			scanf("%d",&bet[i]);
		}
		counter = compare(bet,prices);
		if(counter == 6)
		{
			money += 5000000;
		}
		else if(counter == 100)
		{
			money += 3000000;
		}
		else if(counter == 5)
		{
			money += 1000000;
		}
		else if(counter == 4)
		{
			money += 200000;
		}
		else if(counter == 3)
		{
			money += 60000;
		}
	}
	printf("%d",money);
	return 0;
}


