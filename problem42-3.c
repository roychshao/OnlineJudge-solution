#include <stdio.h>

int main()
{
	float a,b;
	scanf("%f%f",&a,&b);
	if(b == 0)
	{
		printf("AAAAA!\n");
		continue;
	}
	float ans;
	ans = a/b;
	if((ans - (int)ans) == 0)
		printf("%d\n",(float)ans);
	else
		printf("%.2f\n",ans);
	return 0;
}
