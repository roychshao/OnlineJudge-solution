#include <stdio.h>

int main()
{
	int times;
	int input;
	int i;
	int Fibo[1000];	/*if not enough,add it*/
	Fibo[0] = 1;
	Fibo[1] = 1;
	for(i = 2;i < 1000;i++)
		Fibo[i] = Fibo[i-1]+Fibo[i-2];
	i = 0;
	scanf("%d",&times);
	while(i < times)
	{
		scanf("%d",&input);
		printf("%d\n",Fibo[input]);
		i++;
	}
	return 0;
}

