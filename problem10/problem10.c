#include <stdio.h>

int main()
{
	int times = 0;
	float quan;
	int input[1000];
	float sum;
	float tmp=0;
	int i=0;
	scanf("%d",&times);
	while(i<times)
	{
		sum = 0;
		quan = 0;
		tmp = 0;
		scanf("%f",&quan);
		for(int j=0;j<quan;j++)
		{
			scanf("%d",&input[j]);
			tmp += input[j];
		}
		sum = tmp/quan;
		printf("%.2f\n",sum);
		i++;
	}
	return 0;
}
