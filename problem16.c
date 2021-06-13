#include <stdio.h>

int gcd(int a,int b)
{
	if(a == 1 || b == 1) return 1;
	if(a == 0 || b == 0) return 0;
	int tmp;
	while(a % b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return b;
}

int main()
{
	int T,i=0;
	int n,a,b;
	scanf("%d",&T);
	while(i < T)
	{
		scanf("%d",&n);
		scanf("%d",&a);
		for(int j=1;j<n;++j)
		{
			scanf("%d",&b);
			a = gcd(a,b);
		}
		printf("%d\n",a);
		i++;
	}
	return 0;
}
