#include <stdio.h>

int main()
{
	int times,i=0;
	int A,B;
	scanf("%d",&times);
	while(i<times)
	{
		scanf("%d %d",&A,&B);
		printf("%d %d\n",B,A);
		i++;
	}
	return 0;
}
