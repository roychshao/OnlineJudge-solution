#include <stdio.h>

int staff[20000001] = { 0 };

int main()
{
	int times,m,ans=0;
	long index;
	scanf("%d",&times);
	for(int j=0;j<times;++j)
	{
		scanf("%ld",&index);
		staff[index+10000000] = 1;
	}
	scanf("%d",&m);
	for(int j=0;j<m;++j)
	{
		scanf("%ld",&index);
		if(staff[index+10000000])
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
