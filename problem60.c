#include <stdio.h>

int main()
{
	int a,b,ans;
	int and = 0,or = 0,xor = 0;
	scanf("%d%d%d",&a,&b,&ans);
	if((a & b) == ans)
	{
		and = 1;
		printf("AND\n");
	}
	if((a | b) == ans)
	{
		or = 1;
		printf("OR\n");
	}
	if((a ^ b) == ans)
	{
		xor = 1;
		printf("XOR\n");
	}
	if(and == 0 && or == 0 && xor == 0)
		printf("IMPOSSIBLE\n");
	return 0;
}
