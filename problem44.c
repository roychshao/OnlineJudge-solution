#include <stdio.h>

void towers(int n,char frompeg,char topeg,char auxpeg)
{
	if(n == 1)
	{
		printf("move 1 from %c to %c\n",frompeg,topeg);
		return;
	}
	towers(n-1,frompeg,auxpeg,topeg);
	printf("move %d from %c to %c\n",n,frompeg,topeg);
	towers(n-1,auxpeg,topeg,frompeg);
}
		
int main()
{
	int n;
	scanf("%d",&n);
	towers(n,'A','C','B');
	return 0;
}
