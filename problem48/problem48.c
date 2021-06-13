#include <stdio.h>

int main()
{
	int a,b,c;
	int k;
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d",&k);
	int ans;
	ans = a*(k*k)+b*k+c;
	printf("%d",ans);
	return 0;
}
