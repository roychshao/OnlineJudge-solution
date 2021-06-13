#include <stdio.h>

int min(int a,int b,int c,int d)
{
	int temp = a;
	if(b < temp) temp = b;
	if(c < temp) temp = c;
	if(d < temp) temp = d;
	return temp;
}

int main()
{
	int bow,cloak,dagger;
	int quan = 0;
	int coin;
	scanf("%d%d%d%d",&coin,&bow,&cloak,&dagger);
	quan += min(bow,cloak,dagger,coin/880);
	bow -= quan,cloak -= quan,dagger -= quan, coin -= (quan*880);
	while(1)
	{
		if(bow == 0)
		{
			if(coin >= 1000)
			{
				coin -= 1000;
				bow++;
			}
			else
				break;
		}
		if(cloak == 0)
		{
			if(coin >= 720)
			{
				coin -= 720;
				cloak++;
			}
			else
				break;
		}
		if(dagger == 0)
		{
			if(coin >= 300)
			{
				coin -= 300;
				dagger++;
			}
			else
				break;
		}
		if(coin < 880) break;
		quan++,bow--,cloak--,dagger--,coin -= 880;
	}
	printf("%d\n",quan);
	return 0;
}
