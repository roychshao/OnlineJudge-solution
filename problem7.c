#include <stdio.h>

void print(int i)
{
	for(int j=0;j<i;++j)
	{
		for(int k=0;k<i;++k)
		{
			printf("[]");
		}
		printf("\n");
	}
}

int main()
{
	int N,i=1;
	scanf("%d",&N);
	while(i<=N)
	{
		print(i);
		i+=2;
	}
	return 0;
}
