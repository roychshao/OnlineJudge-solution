#include <stdio.h>

int main()
{
	int times,i=0;
	int n,m,counter,quan;
	scanf("%d",&times);
	while(i < times)
	{
		scanf("%d%d",&n,&m);
		quan = n*m;
		counter = 0;
		while(quan != 0)
		{
			counter++;
			quan = quan - n - m + 1;
			n--,m--;
		}
		if(counter % 2 == 0)
			printf("Malvika\n");
		else
			printf("Akshat\n");
		i++;
	}
	return 0;
}
	
