#include <stdio.h>

int nums[1000000];
int sums[1000000];

int main(void)
{
	int i,quan;
	int times,left,right;
	scanf("%d",&quan);
	for(i=0;i<quan;++i)
	{
		scanf("%d",&nums[i]);
	}
	scanf("%d",&times);
	sums[0] = nums[0];
	for(i=1;i<quan;++i)
	{
		sums[i] = sums[i-1] + nums[i];
	}
	i=0;
	while(i<times)
	{
		scanf("%d%d",&left,&right);
		printf("%d\n",sums[right-1]-sums[left-2]);
		i++;
	}
	return 0;
}	













