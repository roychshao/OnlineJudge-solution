#include <stdio.h>

int main()
{
	float a,b,c,d,e,f;
	float mul1,x,y;
	scanf("%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f);
	mul1 = -1*(d/a);
	if((b*mul1 + e) == 0 && (c*mul1 + f) != 0)
	{
		printf("No solution\n");
		return 0;
	}
	if((b*mul1 + e) == 0 && (c*mul1 + f) == 0)
	{
		printf("Infinitely many solutions\n");
		return 0;
	}
	y = (c*mul1 + f)/(b*mul1 + e);
	if(a == 0 && (c-(b*y)) != 0)
	{
		printf("No solution\n");
		return 0;
	}
	if(a == 0 && (c-(b*y)) == 0)
	{
		printf("Infinitely many solutions\n");
		return 0;
	}
	x = (c - (b*y))/a;
	printf("x=%.2f\ny=%.2f\n",x,y);
	return 0;
}
