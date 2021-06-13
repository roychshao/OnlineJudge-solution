#include <stdio.h>
#include <string.h>

int gcd_f(int a,int b)
{
	int i = 2;
	int ans = 1;
	while(a>=i&&b>=i)
	{
		if((a%i==0)&&(b%i==0))
		{
			ans = ans*i;
			a = a/i;
			b = b/i;
		}
		i++;
	}
	return ans;
}

int main()
{
	int times,quan;
	int number[10];
	int i=0,j=0;
	int gcd;
	scanf("%d",&times);
	scanf("%d",&quan);
	while(i<times)
	{
		for(j=0;j<quan;j++)
		{
			scanf("%d",number[i]);
		}
		gcd = gcd_f(number[0],number[1]);
		for(j=2;j+1<strlen(number);i++)
		{
			gcd = gcd_f(gcd,number[j]);
		}
		i++;
		printf("%d\n",gcd);
	}
	return 0;
}




