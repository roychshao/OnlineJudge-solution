#include <stdio.h>

int quickpower(int n,int k)
{
	if(k == 0)
		return 1;
	if(k % 2 == 1)
		return (quickpower(n%1007,k/2)%1007)*(quickpower(n%1007,k/2)%1007)*n%1007;
	else
		return (quickpower(n%1007,k/2)%1007)*(quickpower(n%1007,k/2)%1007);
}

int main()
{
	int times,i = 0;
	int n,k,ans;
	scanf("%d",&times);
	while(i < times)
	{
		scanf("%d%d",&n,&k);
		ans = quickpower(n%1007,k);
		printf("%d\n",ans%1007);
		i++;
	}
	return 0;
}
