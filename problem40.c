#include <stdio.h>

int main()
{
	 a,b,c;
	double s,ans;
	scanf("%d%d%d",&a,&b,&c);
	s = (a+b+c)/2;
	ans = s*(s-a)*(s-b)*(s-c);
	printf("%.0lf\n",ans);
	return 0;
}
