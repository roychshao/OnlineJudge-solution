#include <stdio.h>

int main()
{
	int times,quan;
	float temp,sum;
	int i=0,j=0;
	scanf("%d",&times);
	while(i<times)
	{
		sum = 0;
		scanf("%d",&quan);
		j = 0;
		while(j<quan)
		{
			scanf("%f",&temp);
			sum += temp;
			j++;
		}
		printf("%.2f\n",sum/quan);
		i++;
	}
	return 0;
}


