#include <stdio.h>

int Fibo[1000];

int main()
{
	Fibo[0] = 0;
	Fibo[1] = 1;
	for(int i=2;i<1000;++i)
		Fibo[i] = Fibo[i-1] + Fibo[i-2];
	int index;
	while(scanf("%d",&index) != EOF)
		printf("%d\n",Fibo[index]);
	return 0;
}

